### Actividad 1



### Actividad 2
- ¿Qué fue lo que incluimos en el archivo .h?


- ¿Cómo funciona la aplicación?


- ¿Qué hace la función mouseMoved?


- ¿Qué hace la función mousePressed?


- ¿Qué hace la función setup?


- ¿Qué hace la función update?


- ¿Qué hace la función draw?


### Actividad 3

### Actividad 4

### Actividad 5


### Actividad 6

R// El error es que la esfera es seleccionada acompaña al puntero del mouse causando que no se puedan seleccionar ninguna otra esfera, en ocasiones permite coger un par de esferas, despúes de seleccionar alguna esta el problema de que solo te acompaña una esfera. No tiene una función para cuando se desselecciona, causando que la comparativa del radio de la esfera siempre detecte a la esfera que te acompaña.

La manera que se soluciono el problema fue creando una clase llamada **"mouseReleased"**, hace que al soltar el click izquierdo la esfera se vuelva nula dejando de seguir al mouse. Permitiendo seleccionar otra esfera.

```cpp
void ofApp::mouseReleased(int x, int y, int button) // This function is called when the mouse button is released
{
	if (button == 0) // Check if the left mouse button was released
    {
		selectedSphere = nullptr; // Deselect the sphere
    }
}

```

### Actividad 7

R// lo primero que sucede al presionar la tecla c, es que crea un objeto en una coordenada demasiado alejada Position (717.741, 6.65645), el objeto al estar en stack y al salir de la función directamente se destruye.

R// La esfera es creada y ya es visible en el entorno ademas de que tiene coordenadas más pequeñas.

R// 



### Actividad 8

### Actividad 9


### Actividad 10

