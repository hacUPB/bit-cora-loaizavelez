### Sesión 1: la naturaleza de los objetos en C++



- ¿Qué representa la clase Particle?


```c#
class Particle {
public:
    float x, y;
    void move(float dx, float dy) {
        x += dx;
        y += dy;
    }
};

```

    R// La clase particle, tiene atributos que definen el movimiento de una particula en 2 dimensiones, con una distancia "dx" y una distancia "dy" y sus coordenadas son representadas por una variable flotante, acepta decimales, en el eje coordenado (X,Y), dentro de la clase hay una función move, con un flotante "dx" y "dy" encargada de mover la particula por el plano.


- ¿Cómo interactúan sus atributos y métodos?

    R// "float x, y;" es la posición de la particula en el plano, la función move devuelve la nueva posición en la que la prticula esta al momento de desplazarse, ¿Cómo se logra? toma la posición original de la particula y al momnento de desplazarla, suma el diferencial del movimento con la posición anterior.


- Explícame en detalle qué es un objeto en C++ y cómo se relaciona con una clase. Usa el ejemplo de una clase Particle con atributos x y y y un método move.

    R// Una clase no es más que un molde, no ocupa espacio de memoria, al momento de agregar o instanciarla es cuando la memoria se ocupa, al momento de instanciarla es cuando se crea el objeto, con sus atributos y funciones que se le hayan asignado, el ejemplo de clase particle sigue la siguiente estructura:

    1.) Se define la clase, en este caso la **clase particle**
    2.) Se asignan atributos, la posición flotante en (X,Y) 
    3.) El metodo o función **move** que devuelve un nuevo valor de la posición de la particula. 


- ¿Cómo afectan los datos estáticos al tamaño de la instancia?

    R// Las variables estáticas cómo  **static int s;** no afectan al tamaño de la memoria porque pertencen a la clase, no al objeto, son parte de la plantilla. Se guardan en variables locales para todas las instancias del objeto.

- ¿Qué diferencias hay entre datos estáticos y dinámicos en términos de memoria?

    R// 
    
    Static:

    1.) Se guardan globalmente.

    2.) Se guarda para todas las instancias.

    3.) Existe mientras el programa este corriendo.

    4.) La gestión es automática, es decir, se crean al inicar el prorgrama, no requiere de ser agregados manualmente dentro de la instancia. 

    5.) Las variables dinámicas deben ser creadas con un new y deben tener un delete para que no ocupen el espacio de memoria.

- **Explícame cómo el uso de variables estáticas y dinámicas en una clase afecta el tamaño de sus instancias. ¿Las variables estáticas ocupan espacio en cada objeto?**

    R// Las varaibles estáticas no ocupan memoria, ya que son parte de la plantilla, no forman parte del objeto y se comparten para todas la clases, guardados globalmente. Las variables estáticas no se guardan **sizeof(Simple)** ya que no ocupan espacio de memoria, ya anteriormente mencionado solo se usa una vez para todas las clases.

    Las variables dinámicas, en cambio, si ocupan espacio de memoria ya que forman parte del objeto, se acceden meidante punteros y estos punteros aunque formen parte del objeto se almacenan en el heap, aparte del objeto.


**Reflexión**

- ¿Qué es un objeto desde la perspectiva de la memoria?

    R// Un objeto es una instancia de la plantilla, usando el ejemplo de la particula, se crea el molde y luego con esa ayuda, se crea el objeto y es cuando ocupa la memoria, un papel no tiene peso, lo que ocupa es con lo que se rellena. 

- ¿Cómo influyen los atributos y métodos en el tamaño y estructura del objeto?

    R// si los atributos son estáticos, no ocupan espacio, forman parte de la case y se aplican para todas las clases. Las dinámicas en todo caso, deben ser instanciadas, y deben ser eliminadas manualmente, al contario de el estatico, que se eliminan al terminar de correr el programa. 


- ¿Los atributos están almacenados de forma contigua?

    R// Si, los atributos estan guardados guardados de manera contigua.

    Direcci¾n de p1: 000000000014F1D8
    Direcci¾n de p2: 000000000014F1F8


    Tama±o de Particle: 8 bytes


    Direcci¾n de p1.x: 000000000014F1D8
    Direcci¾n de p1.y: 000000000014F1DC

- ¿Qué indica el tamaño del objeto sobre su estructura interna?

    R// La cantidad de atributos que almacena.

- Prompt para ChatGPT: ¿Cómo se almacenan los objetos en memoria en C++? Si tengo dos instancias de Particle, ¿Cómo se relacionan sus direcciones de memoria? ¿Los atributos están contiguos?

    R//




### Sesión 2: ubicación en memoria de datos y métodos

- ¿Dónde se almacenan los datos y métodos de una clase en C++ en la memoria? Explica el concepto de vtable y cómo se relaciona con los métodos virtuales.

    R// Los datos no estáticos se guardan dentro del stack, al terminar el programa o salir de su función se borran y son guardados dentro de los objetos, sin embargo si son instanciados con **new**, al usar este metodo es cuando ocupa espacio de memoria, los estáticos no ocupan memoria al ser parte de la clase, las varaibles estáticas se guardan dentro de el **.bss** y el **.data** y los metodos son guardados dentro del **.text** la parte más baja de la memoria. 

    Las vtable o tablas virtuales, estás tablas contiene punteros que apuntan a funciones, aprovechando el poliformismo dinámico, es una estructura que permite llamar metodoso durante el tiempo de ejecucion del programa, permitiendo usar metodos diferentes del objeto. Cada clase tiene un puntero llamado **vptr**, al llamarse el metodo virtual se accede a este puntero **vptr** y se buscan los metodos a los que apunta el **vtable** para luego ejecutar los metodos.



- ¿En qué parte de la memoria se encuentran las vtable de cada objeto?

    R// Las vtables están almacenadas en la zona de memoria global, siendo gestionada por el compilador, cada clase con metodos virtuales tiene unicamente una vtable, con punteros a las funciones, incluso con overwrite.


- ¿Cómo afecta la presencia de métodos virtuales al tamaño del objeto?

    R// La presencia de métodos virtuales agrega un puntero oculto (vptr) al objeto, lo que:
     Aumenta el tamaño del objeto en 4 bytes (32 bits) o 8 bytes (64 bits).

- ¿Qué papel juegan las vtables en el polimorfismo?

    R// Al llamarse un metodo virtual, permite que funcione durante el tiempo de ejecución. Permitiendo el poliformismo dinámico. Ya que cada clase tiene sus propios punteros invisibles, que permiten acceder a las vtable. 


- ¿Cómo afecta la presencia de métodos virtuales al tamaño del objeto?

    R// Cuando una clase en C++ declara al menos un método virtual, el compilador agrega un puntero oculto llamado vptr a cada instancia de la clase. Este puntero apunta a la vtable correspondiente. Aumentando en consecuencia el tamaño del objeto, **los vptr ocupan un espacio de 8 bytes** si la clase tiene un metodo de **sizeof()** se puede observar el aumento.




- ¿Qué papel juegan las vtables en el polimorfismo?

    R// Son metodos generados por el compilador, dentro de estás tablas se encuentrar punteros que acceden a las funciones, que a su vez deben ser accedidos por los vptr.





































### Sesión 2



```c#
Base b;
Derived d;
std::cout << "Vtable de Base: " << *(void**)&b << std::endl;
std::cout << "Vtable de Derived: " << *(void**)&d << std::endl;

```


- ¿En qué parte de la memoria se encuentran las vtable de cada objeto?

    R// vtable, es parte de una tabla de funciones virutales generada por el compilador, cada vtable derivado 


- ¿Cómo afecta la presencia de métodos virtuales al tamaño del objeto?

    R//

- ¿Qué papel juegan las vtables en el polimorfismo?


    R//

- Prompt para ChatGPT: ¿Cómo se implementan los métodos virtuales en C++? Explica el concepto de vtable y cómo se utiliza para resolver llamadas a métodos virtuales.

    R//


