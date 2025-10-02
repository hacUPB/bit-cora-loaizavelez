#pragma once
#include "ofMain.h"

// Clase base con polimorfismo en tiempo de compilación
template<typename Derived>
class DrawableEntity {
public:
    void update(float dt) {
        static_cast<Derived*>(this)->updateImpl(dt);
    }

    void draw() const {
        static_cast<const Derived*>(this)->drawImpl();
    }
};

// Clase FallingStar
class FallingStar : public DrawableEntity<FallingStar> {
private:
    ofVec2f position;
    float rotation;
    float radius;

public:
    FallingStar(const ofVec2f& pos);

    void updateImpl(float dt);
    void drawImpl() const;

    const ofVec2f& getPosition() const;
    float getRotation() const;
    float getRadius() const;
};