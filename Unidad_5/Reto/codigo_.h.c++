#pragma once
#include "ofMain.h"

// Clase base abstracta
class DrawableEntity { 
public:
    virtual void update(float dt) = 0; 
    virtual void draw() = 0;
    virtual ~DrawableEntity() {} // Destructor virtual
};

// Superestrella vectorial con ojos
class SuperStar : public DrawableEntity {
private:
    ofVec2f position;
    float rotation;
    float radius;

public:
    SuperStar(const ofVec2f& pos);
    void update(float dt) override;
    void draw() override;
};

// Estrella fugaz
class FallingStar : public DrawableEntity {
private:
    ofVec2f position, velocity;
    float alpha;

public:
    FallingStar();
    void update(float dt) override;
    void draw() override;
    bool isDead() const;
};

// Clase principal
class ofApp : public ofBaseApp {
private:
    std::vector<std::shared_ptr<DrawableEntity>> entities;

public:
    void setup();
    void update();
    void draw();
};