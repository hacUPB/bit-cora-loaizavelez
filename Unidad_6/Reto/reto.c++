#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    // Ball State Pattern
    struct BallState {
        void (*update)(ofVec2f&, ofVec2f&);
    };

    static void idleUpdate(ofVec2f& pos, ofVec2f& vel) {
        // No movimiento
    }

    static void movingUpdate(ofVec2f& pos, ofVec2f& vel) {
        pos += vel;
        vel *= 0.98; // fricción
    }

    BallState idleState = { idleUpdate };
    BallState movingState = { movingUpdate };

    // Ball class
    struct Ball {
        ofVec2f pos, vel;
        ofColor color;
        BallState* state;

        Ball(float x, float y, ofColor c, BallState* s) : pos(x, y), vel(0, 0), color(c), state(s) {}

        void update() {
            if (state && state->update) state->update(pos, vel);
        }

        void draw() {
            ofSetColor(color);
            ofDrawCircle(pos, 10);
        }

        void setState(BallState* newState) {
            state = newState;
        }
    };

    // Observer Pattern
    struct BallObserver {
        std::function<void(Ball*)> onBallLaunched;
    };

    // Factory Pattern
    Ball* createBall(float x, float y, ofColor color) {
        return new Ball(x, y, color, &idleState);
    }

    std::vector<Ball*> balls;
    std::vector<BallObserver> observers;

    void setup();
    void update();
    void draw();
    void keyPressed(int key);
};



//---------------------------------------------------------------

#include "ofApp.h"

void ofApp::setup() {
    float centerX = ofGetWidth() / 2;
    float centerY = ofGetHeight() / 2;
    float radius = 12;
    int rows = 5;
    int ballIndex = 0;

    for (int row = 0; row < rows; ++row) {
        int ballsInRow = row + 1;
        float offsetX = centerX - (ballsInRow - 1) * radius;
        float offsetY = centerY + row * radius * 1.8;

        for (int col = 0; col < ballsInRow; ++col) {
            float x = offsetX + col * radius * 2;
            float y = offsetY;
            ofColor color = ofColor::fromHsb(ofRandom(255), 255, 255);
            balls.push_back(createBall(x, y, color));
            ballIndex++;
        }
    }

    observers.push_back({
        [](Ball* b) {
            ofLog() << "Ball launched at position: " << b->pos;
        }
        });
}


void ofApp::update() {
    for (auto& b : balls) {
        b->update();
    }
}

void ofApp::draw() {
    ofBackground(0);
    for (auto& b : balls) {
        b->draw();
    }
}

void ofApp::keyPressed(int key) {
    if (key == 'l') {
        for (auto& b : balls) {
            b->vel = ofVec2f(ofRandom(-5, 5), ofRandom(-5, 5));
            b->setState(&movingState);
            for (auto& obs : observers) {
                obs.onBallLaunched(b);
            }
        }
    }
}