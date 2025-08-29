#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    xStep = yStep = 40; 
    distDiv = 100.0f; // Distancia entre esferas
    amplitud = 150.0f; // Amplitud de la onda
    selectedSphereIndex = -1; 
    generateGrid();
}

//--------------------------------------------------------------
void ofApp::update() {
    // No se requiere lógica de actualización continua por ahora
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
    cam.begin();
   /* vector<ofColor> palette = {
        ofColor(255, 0, 0),   // Rojo
        ofColor(0, 255, 0),   // Verde
        ofColor(0, 0, 255),   // Azul
        ofColor(255, 255, 0), // Amarillo
        ofColor(0, 255, 255), // Cian
        ofColor(255, 0, 255)  // Magenta
	};

    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate(), 2), ofGetWidth() - 80, 20);

   
    for (auto& pos  :  spherePositions)
    {
        if (sphereSelected && pos == *selectedSpherePosition) 
        {
			ofSetColor(100, 0, 255);  
        }
        else 
        {
            ofSetColor(0,255 , 0);
        }
		ofDrawSphere(pos, 5);
    }*/


	 //Experimento de color aleatorio
    
    for (auto& pos : spherePositions)
{
    if (sphereSelected && pos == *selectedSpherePosition)
    {
        // Color fijo para la esfera seleccionada
        ofSetColor(255, 255, 0); // Amarillo como énfasis
    }
    else
    {
        // Color aleatorio para las demás
        int r = ofRandom(100, 200);
        int g = ofRandom(80, 200);
        int b = ofRandom(15, 200);
        ofSetColor(r, g, b);
    }

    ofDrawSphere(pos, 5);
}


    
    

    cam.end();



    if (sphereSelected )
    {
		ofSetColor(255);
        ofDrawBitmapString("Esfera seleccionada en: ("
            + ofToString(selectedSpherePosition->x, 2) + ", "
            + ofToString(selectedSpherePosition->y, 2) + ", "
			+ ofToString(selectedSpherePosition->z, 2) + ")", 10, 20);
    }
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {

		//Flechas para ajustar la amplitud y la distancia
    case OF_KEY_UP:
        amplitud += 5;
        break;
    case OF_KEY_DOWN:
        amplitud -= 5;
        break;
    case OF_KEY_RIGHT:
        distDiv += 5;
        break;
    case OF_KEY_LEFT:
        distDiv -= 5;
        break;

		//WASD para ajustar el paso
    case 'w':
        yStep += 5;
        break;
    case 's':
        yStep = max(5, yStep - 5);
        break;
    case 'd':
        xStep += 5;
        break;
    case 'a':
        xStep = max(5, xStep - 5);
        break;
    }

    generateGrid();
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    // Convertir las coordenadas del mouse en un rayo 3D
    glm::vec3 rayStart, rayEnd;
    convertMouseToRay(x, y, rayStart, rayEnd);

    // Comprobar si el rayo intersecta alguna esfera
    sphereSelected = false;

    for (auto& pos : spherePositions) {
		glm::vec3 intersectionPoint; // Punto de intersección
        if (rayIntersectsSphere(rayStart, rayEnd - rayStart, pos, 5.0, intersectionPoint)) {
			// Seleccionar la esfera 
			printf("Esfera seleccionada en: (%.2f, %.2f, %.2f)\n", pos.x, pos.y, pos.z);
			sphereSelected = true;
			selectedSpherePosition = &pos;

            if (sphereSelected && pos == *selectedSpherePosition) {
                ofSetColor(255, 0, 0); 
            } 
            else{
                ofSetColor(0, 0, 255); 
			}
            
			
			
           
			//ofSetColor(255, 0, 0); , NO CAMBIA EL COLOR



			
			
          
			
			
                
            
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
