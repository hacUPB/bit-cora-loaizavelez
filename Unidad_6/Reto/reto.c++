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
    ~Particle();

    void update();
    void draw();
    void onNotify(const std::string& event) override;
    void setState(State* newState);

    ofVec2f position;
    ofVec2f velocity;
    float size;
    ofColor color;
    ofVec2f originalPosition;

private:
    State* state;
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

// StaticState
void StaticState::update(Particle* particle) {
    particle->velocity.set(0, 0);
}

// MovingState
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

// NoBorderState
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

// ParticleFactory
Particle* ParticleFactory::createParticle(const std::string& type) {
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
    ofVec2f center(ofGetWidth() / 2, ofGetHeight() / 2);

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