### Actividad 1

R// este programa genera un circulo, este circulo tiene la función de seguir el mouse, cada vez que el mouse se desplaza el circulo lo sigue.


### Actividad 2
- ¿Qué fue lo que incluimos en el archivo .h?

R// 
```c++
public:
        void setup(); // se encarga de inicializar el programa.
        void update(); // se encarga de actualizar en tiempo real para dibujar el objeto. Usualmente está vacia porque el objeto no debe actualizarse contstantemente.
        void draw(); // es la función encargada de dibujar el objeto.


         void mouseMoved(int x, int y ); // Es la función de que permite mover el mouse atraves del canvas.
        void mousePressed(int x, int y, int button); // Es la función que permite detectar en que momento y en que espacio se presiona el click del mouse.

    private:

        vector<ofVec2f> particles;
        ofColor particleColor;

```


- ¿Cómo funciona la aplicación?

R// Cada vez que el mouse se desplaza, genera un nuevo circulo, cada que se presiona el mouse los circulos cambian de color y tienen un limite de ciruclos que pueden estar a la vez, 100 es el limite, cada vez que se llega a este número se elimina el circulo más antiguo.


- ¿Qué hace la función mouseMoved?

R// Cada que se desplaza el mouse, no importa la orientación, genera un nuevo circulo. Eliminando el más antiguo.


- ¿Qué hace la función mousePressed?

R// Genera un color aleatorio cada vez que se presiona el click.


- ¿Qué hace la función setup?

R// Cuando se inicializa el programa, se pone el fondo en negro y el ciruclo empieza con un color en blanco.


- ¿Qué hace la función update?

R// No tiene ninguna función.


- ¿Qué hace la función draw?

R// Es el que se encarga de crear los circulos, se le asigna la posición en (X) y (Y) y el radio de 50.

### Actividad 3

- void ofApp::setup(): Está clase se encarga de inicializar el programa, genra el fondo en negro y asigna el color blanco al circulo.

- void ofApp::update(): no tiene ninguna función.

- void ofApp::draw(): Se encarga de deibujar el ciruclo en la posicón del mouse de radio 50 y se le asigna el color blanco.

- void ofApp::mouseMoved(int x, int y ): está clase se encarga del movimiento del mouse, cada vez que se desplaza, elimina el ciruclo más viejo y crea uno nuevo.

- void ofApp::mousePressed(int x, int y, int button): Está clase tiene la función de cambiar el color de los ciruclos cada que se preisona el click.

**Parte eliminada**


```c#

void ofApp::mouseMoved(int x, int y) {
    particles.push_back(ofVec2f(x, y));
    //if (particles.size() > 100) { 
   //     particles.erase(particles.begin());
    //}
}


```
si se elimina el particles.erase, ninguno de los circulos generados se eliminara, causando que la pantalla se sature de circulos. Como hipotesis, de seguir generando circulos causara el crasheo del programa.




### Actividad 5

- ¿Cuál es la definición de un puntero?

R// Por la definición de puntero, es poner una variable y asignarle la posiciónde memoria de otra variable y se incrusta en esta posición.

- ¿Dónde está el puntero?

R// El puntero está localiza en las siguientes lineas de codigo.

```c++
  private:

        vector<Sphere*> spheres;
        Sphere* selectedSphere;

```

- ¿Cómo se inicializa el puntero?
- ¿Para qué se está usando el puntero?
- ¿Qué es exactamente lo que está almacenado en el puntero?

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

R// La esfera es creada y ya es visible en el entorno ademas de que tiene coordenadas más pequeñas. Está esfera no es destruida porque al salir de la función sigue existiendo, ahora es capaz de generarse dentro del canvas.

R// Cuando se guarda en stack, al salir de la función el objeto se destruye.

En Heap, el objeto persiste hasta que se borre manualmente. El heap tiene la caracteristica de que aun si es cerrado el programa, ese espacio de memoria lo sigue usando la variable.



### Actividad 8

R// **Stack**

```c++
+		[Vista sin formato]	{_Myval2={_Myfirst=0x0000000000701dd0 {offset={...} color={...} size=30.0000000 } _Mylast=0x0000000000701e20 {...} ...} }	std::_Compressed_pair<std::allocator<Cuadro>,std::_Vector_val<std::_Simple_types<Cuadro>>,1>

```
```c++
+		[Vista sin formato]	{_Myval2={_Myfirst=0x0000000000000000 {???} _Mylast=0x0000000000000000 {???} _Myend=0x0000000000000000 {...} } }	std::_Compressed_pair<std::allocator<Cuadro *>,std::_Vector_val<std::_Simple_types<Cuadro *>>,1>


```

¿Cuándo debo crear objetos en el heap y cuándo en memoria global?

R// para cuando debas usar memoria global, debes primero determinar lo siguiente, ¿cuanto sera la vida util del programa?, las variables globales funcionan para todas las clases, ya que todas tienen acceso a estás, ademas de funcionar para toda la clase en la que este, si por ejemplo el programa es sencillo, no generará problemas a largo plazo, pero si el programa crece, creara conflictos porque se debe usar siempre la misma la variable, con su nombre preciso. 

El heap es dinámico, es decir, va a persistir en todo momento de la compilacón del programa, ademas de poder agregar información tanto como se pueda. Cabe alclarar que al persistir, se debe eliminar la información, si no se hace, ese esapcio de morira seguira siendo utilziado.

### Actividad 9

R// al presionarse el click, no importa si es el izquiero o el derecho, se genera un circulo donde tiene el nombre de la ubicación de memoria, heap memory. Al apretarse "f" se eliminan los circulos.

R// Comose menciono anteriormente, si en memoria heap no se eliminan manualmente la información de la memoria, se queda almacenada incluso si se cierra el programa, lo que hace la linea de codigo es permitir la eliminación manual de estós objetos. Unicamente si se presiona la tecla f.



