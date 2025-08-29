// archivo Cpp

#include "ofApp.h"

Cuadro::Cuadro(float s, ofColor c) {
    size = s;
    color = c;
    offset.set(ofRandom(-100, 100), ofRandom(-100, 100));
}

void Cuadro::draw(const ofVec2f& mousePos) {
    ofSetColor(color);
    ofDrawRectangle(mousePos + offset, size, size);
}

void ofApp::setup() {
    for (int i = 0; i < 5; ++i)
        cuadradosStack.emplace_back(30, ofColor::blue);

    for (int i = 0; i < 5; ++i)
        cuadradosHeap.push_back(new Cuadro(30, ofColor::red));

    ofBackground(240);
}

void ofApp::update() {
    
}

void ofApp::draw() {
    ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

    for (auto& c : cuadradosStack)
        c.draw(mousePos);

    for (auto* c : cuadradosHeap)
        c->draw(mousePos);

    ofSetColor(0);
    ofDrawBitmapString("Azul = Stack | Rojo = Heap", 10, 20);
}

void ofApp::exit() {
    for (auto* c : cuadradosHeap)
        delete c;
    cuadradosHeap.clear();
}

// archivo .h

#pragma once
#include "ofMain.h"

class Cuadro {
public:
    ofVec2f offset;
    ofColor color;
    float size;

    Cuadro(float s, ofColor c);
    void draw(const ofVec2f& mousePos);
};

class ofApp : public ofBaseApp {
public:
    std::vector<Cuadro> cuadradosStack;
    std::vector<Cuadro*> cuadradosHeap;

    void setup();
    void update();
    void draw();
    void exit(); 
};
