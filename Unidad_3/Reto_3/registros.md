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

este es el metodo draw(), aqui se crean las esferas, la parte inicial es un intento de paleta de colores, quedo descartada por una función que genera un color aleatorio. Lo siguiente muestra los FPS, esta ajustado a la camra entonces no se mueestra en pantalla hasta que te alejas. Lo ultimo genera 