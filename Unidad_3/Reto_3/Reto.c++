#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    xStep = yStep = 40;
    distDiv = 100.0f;
    amplitud = 50.0f;
    selectedSphereIndex = -1;
    generateGrid();
}

//--------------------------------------------------------------
void ofApp::update() {
    // No se requiere lógica de actualización continua por ahora
}

//--------------------------------------------------------------
void ofApp::draw() {
    cam.begin();
    for (int i = 0; i < spherePositions.size(); ++i) {
        if (i == selectedSphereIndex) {
            ofSetColor(255, 0, 0); // Esfera seleccionada
        }
        else {
            ofSetColor(100, 200, 255); // Esferas normales
        }
        ofDrawSphere(spherePositions[i], 5.0);
    }
    cam.end();

    if (selectedSphereIndex != -1) {
        glm::vec3 pos = spherePositions[selectedSphereIndex];
        ofDrawBitmapStringHighlight("Esfera seleccionada:\nX: " + ofToString(pos.x) +
            "\nY: " + ofToString(pos.y) +
            "\nZ: " + ofToString(pos.z), 20, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_UP) amplitud += 5;
    if (key == OF_KEY_DOWN) amplitud -= 5;
    if (key == OF_KEY_RIGHT) distDiv += 5;
    if (key == OF_KEY_LEFT) distDiv -= 5;
    if (key == 'w') yStep += 5;
    if (key == 's') yStep = max(5, yStep - 5);
    if (key == 'd') xStep += 5;
    if (key == 'a') xStep = max(5, xStep - 5);

    generateGrid();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    glm::vec3 rayStart, rayEnd;
    convertMouseToRay(x, y, rayStart, rayEnd);

    selectedSphereIndex = -1;
    for (int i = 0; i < spherePositions.size(); ++i) {
        glm::vec3 intersectionPoint;
        if (rayIntersectsSphere(rayStart, rayEnd - rayStart, spherePositions[i], 5.0, intersectionPoint)) {
            selectedSphereIndex = i;
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::generateGrid() {
    spherePositions.clear();
    for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += xStep) {
        for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += yStep) {
            float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
            spherePositions.push_back(glm::vec3(x, y, z));
        }
    }
}

//--------------------------------------------------------------
void ofApp::convertMouseToRay(int mouseX, int mouseY, glm::vec3& rayStart, glm::vec3& rayEnd) {
    glm::mat4 modelview = cam.getModelViewMatrix();
    glm::mat4 projection = cam.getProjectionMatrix();
    ofRectangle viewport = ofGetCurrentViewport();

    float x = 2.0f * (mouseX - viewport.x) / viewport.width - 1.0f;
    float y = 1.0f - 2.0f * (mouseY - viewport.y) / viewport.height;

    glm::vec4 rayStartNDC(x, y, -1.0f, 1.0f);
    glm::vec4 rayEndNDC(x, y, 1.0f, 1.0f);

    glm::vec4 rayStartWorld = glm::inverse(projection * modelview) * rayStartNDC;
    glm::vec4 rayEndWorld = glm::inverse(projection * modelview) * rayEndNDC;

    rayStartWorld /= rayStartWorld.w;
    rayEndWorld /= rayEndWorld.w;

    rayStart = glm::vec3(rayStartWorld);
    rayEnd = glm::vec3(rayEndWorld);
}

//--------------------------------------------------------------
bool ofApp::rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir,
    const glm::vec3& sphereCenter, float sphereRadius,
    glm::vec3& intersectionPoint) {
    glm::vec3 oc = rayStart - sphereCenter;
    float a = glm::dot(rayDir, rayDir);
    float b = 2.0f * glm::dot(oc, rayDir);
    float c = glm::dot(oc, oc) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) return false;

    float t = (-b - sqrt(discriminant)) / (2.0f * a);
    intersectionPoint = rayStart + t * rayDir;
    return true;
}