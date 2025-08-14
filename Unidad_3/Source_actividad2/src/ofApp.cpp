#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() { // Initialize the application
	ofBackground(8); // // // Set the background color to a dark shade
	particleColor = ofColor::white; // Initialize the particle color to white
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() { // Draw particles
	for (auto& pos : particles) { // Loop through each particle position
		ofSetColor(particleColor); // Set the color for the particles
		ofDrawCircle(pos.x, pos.y, 50); // Draw a circle at the particle position
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) { // Add a new particle at the mouse position
	particles.push_back(ofVec2f(x, y)); // Store the mouse position as a new particle
	if (particles.size() > 100) { // Limit the number of particles to 100
		particles.erase(particles.begin()); // Remove the oldest particle if the limit is exceeded
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) { // Change the particle color when the mouse is pressed
	particleColor = ofColor(ofRandom(255), ofRandom(255 ), ofRandom(255)); // Generate a random color for the particles
}
