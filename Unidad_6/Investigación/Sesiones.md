


### Sesión 2


![alt text](image.png)


```c++
Particle* ParticleFactory::createParticle(const std::string& type) { 
	Particle* particle = new Particle(); // Crear una nueva partícula

	if (type == "star") { // Configurar propiedades específicas para una estrella
		particle->size = ofRandom(2, 4);  // Tamaño pequeño
		particle->color = ofColor(255, 0, 0); // Rojo
    }
    else if (type == "shooting_star") {
        particle->size = ofRandom(3, 6);
        particle->color = ofColor(0, 255, 0);
        particle->velocity *= 3;
    }
    else if (type == "planet") {
        particle->size = ofRandom(5, 8);
        particle->color = ofColor(0, 0, 255);
    }
    return particle;
}

```

El patrón de sieño de la factoria no depende de una ubicación específica, es decir, puede estar en el Draw, en el set up o en una clase que cumpla la condición para que se genere la esfera.





- ¿Qué hace el patrón observer en este caso?

    R//

- ¿Qué hace el patrón factory en este caso?

    R// La

- ¿Qué hace el patrón state en este caso?

    R// 


Experimenta con el código y realiza algunas modificaciones para entender mejor su funcionamiento. Por ejemplo:

- Adiciona un nuevo tipo de partícula.

    R//

- Adiciona un nuevo estado.

    R//

- Modifica el comportamiento de las partículas.

    R//

- Crea otros eventos para notificar a las partículas.