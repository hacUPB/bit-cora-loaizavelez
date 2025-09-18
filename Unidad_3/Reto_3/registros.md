### Rgeistros 

```c++
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
```

este es el metodo draw(), aqui se crean las esferas, la parte inicial es un intento de paleta de colores, quedo descartada por una función que genera un color aleatorio. Lo siguiente muestra los FPS, esta ajustado a la camra entonces no se mueestra en pantalla hasta que te alejas. La ultima sección del codigo genera la esfera, toma una posición, se le asigna un color y luego el radio de la esfera.

```c++


void ofApp::setup() {
    ofBackground(0);
    xStep = yStep = 40;
    distDiv = 100.0f; // Distancia entre esferas
    amplitud = 150.0f; // Amplitud de la onda
    selectedSphereIndex = -1;
    generateGrid();
}
```
este inicializa el entorno, el color dle fondo se asigna a negro, luego se asignas las variables para la distancia entre esferas y la amplitud de la onda ademas de generarse la malla de esferas.