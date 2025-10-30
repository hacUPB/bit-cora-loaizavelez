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

//Punto 5 Suma el contenido de la posición 0 de la RAM, el contenido de la posición 1 de la RAM y con la constante 69. Guarda el resultado en la posición 2 de la RAM.
@0
D=M
@1
D=D+M
@69
D=D+A
@2
M=D

//Punto 6 Si el valor almacenado en D es igual a 0 salta a la posición 100 de la ROM.

@0
D=M
@100
D;JMP

//Punto 7 Si el valor almacenado en la posición 100 de la RAM es menor a 100 salta a la posición 20 de la ROM.

@100
D=M
D=D-A 
@20
D;JLT






