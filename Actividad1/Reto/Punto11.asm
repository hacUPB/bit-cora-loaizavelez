//Punto 11

// i = 1000 
@1000
D=A
@i
M=D
(LOOP)
// if (i == 0) goto CONT
@i
D=M
@CONT
D;JEQ
// i = i - 1
@i
M=M-1
// goto LOOP
@LOOP
0;JMP
(CONT)

1. La función de este codigo es hacer que la variable 100 vaya decrementando dentro del loop en 1 unidad, cuando llegue a 0 el loop se dentendra.
2. La variable i esta guardada en la dirección @16 de la RAM:
3. Los comentarios no se guardan dentro del ensamblador, unicamente sirven como guía. 
4. 
