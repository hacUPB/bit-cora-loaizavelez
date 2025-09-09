### Arte cielo estrellado.

La Simulación se construye sobre una arquitectura modular que combina cuatro estructuras de datos: un arreglo **dinámico** para gestionar las estrellas activas, una **cola** para secuenciar los remolinos visuales, una pila que registra eventos de interacción del usuario y una lista enlazada que conecta trazos entre elementos. Cada objeto visual (estrella, remolino, trazo) se crea dinámicamente en el heap. Los eventos se almacenan en la pila **stack**, aprovechando el LIFO (last input first output) para revertir acciones recientes, mientras que **los remolinos se encolan en el heap y se procesan en orden de aparición**. La interactividad mediante teclado, mouse altera simultáneamente estas estructuras, con el mouse, inspirada en el cielo estrellado de Van Gogh. La gestión de memoria se realiza explícitamente con delete.


