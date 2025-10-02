#include "ofApp.h"
#include <iostream>

// SuperStar
SuperStar::SuperStar(const ofVec2f& pos) : position(pos), rotation(0.0f), radius(60.0f) {
    std::cout << "[SuperStar] creada en posicion (" << pos.x << ", " << pos.y << ")\n"; // Mensaje de depuracion
}

void SuperStar::update(float dt) { // dt en segundos
    rotation += dt * 30.0f; // 30 grados por segundo
    std::cout << "[SuperStar] rotacion actual: " << rotation << "\n"; // Mensaje de depuracion
}

void SuperStar::draw() {
    ofPushMatrix(); // Guardar transformacion actual
    ofTranslate(position); // Mover al centro de la estrella
    ofRotateDeg(rotation); // Rotar

    ofPath star; // Crear la forma de la estrella
    star.setFillColor(ofColor(255, 255, 0)); // Amarillo
    star.setStrokeColor(ofColor::black); // Negro
    star.setStrokeWidth(4); // Grosor del borde

    for (int i = 0; i < 10; ++i) { // 10 puntas
        float angle = ofDegToRad(i * 36 - 90); // 36 grados entre puntas, -90 para empezar hacia arriba
        float r = (i % 2 == 0) ? radius : radius * 0.4f; // Alternar entre radio grande y pequeño
        float x = cos(angle) * r; // Calcular coordenadas
        float y = sin(angle) * r; // Calcular coordenadas
        star.lineTo(x, y); // Agregar punto a la estrella
    }
    star.close(); // Cerrar la forma
    star.draw(); // Dibujar la estrella

    ofSetColor(0); // Color de los ojos
    float eyeOffsetX = radius * 0.3f; // Desplazamiento horizontal de los ojos
    float eyeOffsetY = radius * 0.2f; // Desplazamiento vertical de los ojos
    float eyeWidth = radius * 0.15f; // Ancho de los ojos
    float eyeHeight = radius * 0.3f; // Alto de los ojos

    ofDrawEllipse(-eyeOffsetX, -eyeOffsetY, eyeWidth, eyeHeight); // Ojo izquierdo
    ofDrawEllipse(eyeOffsetX, -eyeOffsetY, eyeWidth, eyeHeight); // Ojo derecho

    ofPopMatrix(); // Restaurar transformacion

}

// FallingStar
FallingStar::FallingStar() { // Constructor
    position.set(ofRandomWidth(), ofRandomHeight()); // Posicion inicial aleatoria
    velocity.set(-ofRandom(200, 400), ofRandom(-100, 100)); // Velocidad aleatoria
    alpha = 255; // Opacidad inicial
    std::cout << "[FallingStar] creada en (" << position.x << ", " << position.y << ") con velocidad (" << velocity.x << ", " << velocity.y << ")\n"; // Mensaje de depuracion
}

void FallingStar::update(float dt) { // dt en segundos
    position += velocity * dt;
    alpha -= dt * 100;
    std::cout << "[FallingStar] posicion: (" << position.x << ", " << position.y << "), alpha: " << alpha << "\n";
}

void FallingStar::draw() {
    ofSetColor(150, 0, 255, alpha);
    ofSetLineWidth(3);
    ofDrawLine(position, position + velocity * 0.2f);
}

bool FallingStar::isDead() const {
    if (alpha <= 0) {
        std::cout << "[FallingStar] eliminada\n";
        return true;
    }
    return false;
}

// ofApp
void ofApp::setup() {
    ofBackground(0);
    entities.push_back(std::make_shared<SuperStar>(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2)));
}

void ofApp::update() {
    float dt = ofGetLastFrameTime();

    if (ofRandom(1.0f) < 0.05f) {
        entities.push_back(std::make_shared<FallingStar>());
    }

    for (auto& e : entities) {
        e->update(dt);
    }

    entities.erase(std::remove_if(entities.begin(), entities.end(),
        [](const std::shared_ptr<DrawableEntity>& e) {
            auto fs = std::dynamic_pointer_cast<FallingStar>(e);
            return fs && fs->isDead();
        }), entities.end());

    std::cout << "[ofApp] entidades activas: " << entities.size() << "\n";
}

void ofApp::draw() {
    for (auto& e : entities) {
        e->draw();
    }
}