// Punto 1
@1978
D=A
M=D
//Punto 2 Guarda en la posición 100 de la RAM el número 69.
@69
D=A
@100
M=D

//Punto 3 Guarda en la posición 200 de la RAM el contenido de la posición 24 de la RAM
@24
D=A
@200
M=D

//Punto 4 Lee lo que hay en la posición 100 de la RAM, resta 15 y guarda el resultado en la posición 100 de la RAM.
@100
D=M
@15
D=D-A
@100
M=D

