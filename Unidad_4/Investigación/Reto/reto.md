### Arte cielo estrellado.
Cpp

```c++
#include "ofApp.h"

// ColorList
void ColorList::addColor(ofColor c) {
    ColorNode* newNode = new ColorNode(c);
    newNode->next = head;
    head = newNode;
}

ofColor ColorList::getRandomColor() const {
    int count = 0;
    ColorNode* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    if (count == 0) return ofColor::white;

    int index = ofRandom(count);
    current = head;
    while (index-- > 0 && current) {
        current = current->next;
    }
    return current ? current->color : ofColor::white;
}

void ColorList::clear() {
    while (head) {
        ColorNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ofApp
void ofApp::setup() {
    ofSetBackgroundColor(10, 10, 30);
    ofSetFrameRate(60);
}

void ofApp::update() {
    if (ofRandom(1.0) < 0.2) {
        spawnStar();
    }
}

void ofApp::draw() {
    std::stack<Star*> temp = starStack;
    while (!temp.empty()) {
        Star* s = temp.top();
        temp.pop();

        ofColor c = colorList.getRandomColor();
        c.setBrightness(ofRandom(180, 255)); // titilar
        ofSetColor(c);
        ofDrawCircle(s->position, s->radius);
    }
}

void ofApp::spawnStar() {
    float x = ofRandomWidth();
    float y = ofRandomHeight();
    float r = ofRandom(2, 5);
    Star* newStar = new Star(ofVec2f(x, y), r);
    starStack.push(newStar);
}

void ofApp::keyPressed(int key) {
    if (key == 'a') {
        ofColor newColor = ofColor::fromHsb(ofRandom(255), 200, 255);
        colorList.addColor(newColor);
    }
    if (key == 'd') {
        clearStars();
    }
}

void ofApp::clearStars() {
    while (!starStack.empty()) {
        delete starStack.top();
        starStack.pop();
    }
}

void ofApp::exit() {
    clearStars();
    colorList.clear();
}

```


.h

```c++
#pragma once
#include "ofMain.h"
#include <stack>

// Nodo de color (lista enlazada)
class ColorNode {
public:
    ofColor color;
    ColorNode* next;

    ColorNode(ofColor c) : color(c), next(nullptr) {}
};

class ColorList {
public:
    ColorNode* head;

    ColorList() : head(nullptr) {}
    ~ColorList() { clear(); }

    void addColor(ofColor c);
    ofColor getRandomColor() const;
    void clear();
};

// Estructura de estrella
struct Star {
    ofVec2f position;
    float radius;

    Star(ofVec2f pos, float r) : position(pos), radius(r) {}
};

class ofApp : public ofBaseApp {
public:
    std::stack<Star*> starStack;
    ColorList colorList;

    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void exit();
    void clearStars();
    void spawnStar();
};

```


1. Exploración creativa: ¿Qué tipo de efecto visual quieres lograr? ¿Cómo pueden ayudarte las diferentes estructuras de datos a lograr ese efecto?

R// el efecto visual que busco con esto es un cielo estrellado que vibre, que las luces destilen y se vean como vivas, decidi usar la pila para las estrellas, se generan en una fila para identificar cual fue el primero en generarse, los colores estan en una lista enlazada, para mayor navegabilidad entre los colores. 

2. Gestión de memoria: ¿Qué consideraciones debes tener en cuenta al gestionar dinámicamente la memoria de los objetos? ¿Cómo asegurar que no haya fugas de memoria?

R// Se creo un exit() y un clearStars() se borran las estrellas con la letra "D" y al salir del programa se libera toda la memoria borrando la lista de colores y borrando la pila de las estrellas.



3. Interacción y dinamismo: ¿Cómo puedes hacer que la interacción del usuario influya en múltiples estructuras de datos simultáneamente para crear un efecto visual coherente y dinámico?

R// para la interacción se presiona la letra "a" para cambiar el color, cada vez que cambias de color las estrellas siguientes siguen otro patrón y con la letra "d" borras las estrellas.



Ubiaciones de memoria: 

**Star:**
 -		newStar	0x0000000007c20b60 {position={x=867.526367 y=591.135193 } radius=4.90615511 }	Star *

- 	position	{x=867.526367 y=591.135193 }	ofVec2f

- 	starStack	{ size=0 }	std::stack<Star *,std::deque<Star *,std::allocator<Star *>>>

- 	v	0x000000000014f764 "ÌÌÌÌ...	unsigned char[4]

-		s	0xcccccccccccccccc {position={x=??? y=??? } radius=??? }	Star *

<video controls src="ubicación de memoria .mp4" title="Title"></video>



star esta guardado en el heap en las coordenadas (x=867.526367 y=591.135193), el puntero Star* esta guardando la ubicación, copiando la posicioón anterior de la estrella y "mudandose" de la pila al stack. En este momento hay 0 estrellas en el contador.

la lista enlazada, contiene los colores en 		v	0x000000000014f764 "ÌÌÌÌ...	unsigned char[4] la lista enlazada


<video controls src="video unidad 4.mp4" title="Title"></video>

 