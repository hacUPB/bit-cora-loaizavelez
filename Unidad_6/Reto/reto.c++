//--------------------------------------------------------------- .h
#pragma once

#include "ofMain.h"
#include <vector>
#include <string>

class Observer {
public:
    virtual void onNotify(const std::string& event) = 0;
};

class Subject {
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
protected:
    void notify(const std::string& event);
private:
    std::vector<Observer*> observers;
};

class Particle;

class State {
public:
    virtual void update(Particle* particle) = 0;
    virtual void onEnter(Particle* particle) {}
    virtual void onExit(Particle* particle) {}
    virtual ~State() = default;
};

class Particle : public Observer {
public:
    Particle();
    virtual ~Particle();

    virtual void update();
    virtual void draw();
    virtual void onNotify(const std::string& event) override;
    void setState(State* newState);

    ofVec2f position;
    ofVec2f velocity;
    float size;
    ofColor color;
    ofVec2f originalPosition;

private:
    State* state;
};


class SquareParticle : public Particle {
public:
    SquareParticle();
    void update() override;
    void draw() override;
    void onNotify(const std::string& event) override;
};

class StaticState : public State {
public:
    void update(Particle* particle) override;
};

class MovingState : public State {
public:
    void update(Particle* particle) override;
    void onEnter(Particle* particle) override;
};

class NoBorderState : public State {
public:
    void update(Particle* particle) override;
};

class ParticleFactory {
public:
    static Particle* createParticle(const std::string& type);
};

class ofApp : public ofBaseApp, public Subject {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
private:
    std::vector<Particle*> particles;
    bool showBorders = true;
};



//--------------------------------------------------------------- cpp 

#include "ofApp.h"
#include <algorithm>

// Subject
void Subject::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const std::string& event) {
    for (Observer* observer : observers) {
        observer->onNotify(event);
    }
}

// States
void StaticState::update(Particle* particle) {
    particle->velocity.set(0, 0);
}

void MovingState::onEnter(Particle* particle) {
    particle->velocity = ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5));
}

void MovingState::update(Particle* particle) {
    particle->position += particle->velocity;
    if (particle->position.x < 0 || particle->position.x > ofGetWidth()) {
        particle->velocity.x *= -1;
    }
    if (particle->position.y < 0 || particle->position.y > ofGetHeight()) {
        particle->velocity.y *= -1;
    }
}

void NoBorderState::update(Particle* particle) {
    particle->position += particle->velocity;
}

// Particle
Particle::Particle() {
    position = ofVec2f(0, 0);
    originalPosition = position;
    velocity.set(0, 0);
    size = 15;
    color = ofColor::white;
    state = new StaticState();
}

Particle::~Particle() {
    delete state;
}

void Particle::setState(State* newState) {
    if (state) {
        state->onExit(this);
        delete state;
    }
    state = newState;
    if (state) {
        state->onEnter(this);
    }
}

void Particle::update() {
    if (state) {
        state->update(this);
    }
}

void Particle::draw() {
    ofSetColor(color);
    ofDrawCircle(position, size);
}

void Particle::onNotify(const std::string& event) {
    if (event == "launch") {
        setState(new MovingState());
    }
    else if (event == "reset") {
        position = originalPosition;
        setState(new StaticState());
    }
    else if (event == "disable_border") {
        setState(new NoBorderState());
    }
}

// SquareParticle
SquareParticle::SquareParticle() {
    size = 10;
    color = ofColor::fromHsb(ofRandom(0, 255), 200, 255);
    velocity = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
}

void SquareParticle::update() {
    position += velocity;
    if (position.x < 0 || position.x > ofGetWidth()) velocity.x *= -1;
    if (position.y < 0 || position.y > ofGetHeight()) velocity.y *= -1;
}

void SquareParticle::draw() {
    ofSetColor(color);
    ofDrawRectangle(position.x - size, position.y - size, size * 2, size * 2);
}

void SquareParticle::onNotify(const std::string& event) {
    // No hace nada
}

// Factory
Particle* ParticleFactory::createParticle(const std::string& type) {
    if (type == "square") {
        return new SquareParticle();
    }

    Particle* p = new Particle();
    if (type == "ball") {
        p->color = ofColor::fromHsb(ofRandom(0, 255), 200, 255);
    }
    return p;
}

// ofApp
void ofApp::setup() {
    ofBackground(0);

    float ballSize = 15;
    float spacing = ballSize * 2.1;
    float squareSpacing = 20;

    ofVec2f center(ofGetWidth() / 2, ofGetHeight() / 2);

    int numSquares = 0;
    int squaresPerRow = 3;
    int squareRows = 2;
    int ballIndex = 0;

    for (int row = 0; row < 5; ++row) {
        int ballsInRow = row + 1;
        float rowY = center.y + (row - 2) * spacing;
        float rowStartX = center.x - (spacing * (ballsInRow - 1)) / 2;

        for (int col = 0; col < ballsInRow; ++col) {
            if (ballIndex >= 15) break;
            Particle* p = ParticleFactory::createParticle("ball");
            p->position = ofVec2f(rowStartX + col * spacing, rowY);
            p->originalPosition = p->position;
            particles.push_back(p);
            addObserver(p);
            ballIndex++;
        }
    }

    for (int row = 0; row < squareRows; ++row) {
        float rowY = center.y - squareSpacing + row * squareSpacing;
        float rowStartX = center.x - (squareSpacing * (squaresPerRow - 1)) / 2;

        for (int col = 0; col < squaresPerRow; ++col) {
            if (numSquares >= 6) break;
            Particle* p = ParticleFactory::createParticle("square");
            p->position = ofVec2f(rowStartX + col * squareSpacing, rowY);
            p->originalPosition = p->position;
            particles.push_back(p);
            // No se agrega como observer
            numSquares++;
        }
    }
}

void ofApp::update() {
    for (Particle* p : particles) {
        p->update();
    }
}

void ofApp::draw() {
    for (Particle* p : particles) {
        p->draw();
    }

    if (showBorders) {
        ofSetColor(0, 255, 0);
        ofNoFill();
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }

    ofSetColor(255);
    ofDrawBitmapString("Press 'l' to launch, 'r' to reset, 'd' to disable borders", 10, ofGetHeight() - 10);

    int numCirculos = 15;
    int numCuadrados = 6;
    int fps = static_cast<int>(ofGetFrameRate());

    std::string info = "Cantidad circulos: " + std::to_string(numCirculos) +
        "\nCantidad cuadrados: " + std::to_string(numCuadrados) +
        "\nFPS: " + std::to_string(fps);

    ofDrawBitmapString(info, 10, 20);
}


void ofApp::keyPressed(int key) {
    if (key == 'l') {
        notify("launch");
        showBorders = true;
    }
    else if (key == 'r') {
        notify("reset");
        showBorders = true;
    }
    else if (key == 'd') {
        notify("disable_border");
        showBorders = false;
    }
}