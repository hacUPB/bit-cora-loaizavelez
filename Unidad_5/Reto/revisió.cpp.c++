#include "ofApp.h"

FallingStar::FallingStar(const ofVec2f& pos)
    : position(pos), rotation(0.0f), radius(30.0f) {
}

void FallingStar::updateImpl(float dt) {
    rotation += dt * 90.0f;
    position.y += dt * 100.0f;
}

void FallingStar::drawImpl() const {
    ofPushMatrix();
    ofTranslate(position);
    ofRotateDeg(rotation);
    ofSetColor(255, 100, 100);
    ofDrawCircle(0, 0, radius);
    ofPopMatrix();
}

const ofVec2f& FallingStar::getPosition() const { return position; }
float FallingStar::getRotation() const { return rotation; }
float FallingStar::getRadius() const { return radius; }