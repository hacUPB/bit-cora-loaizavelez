
@1
D=A
@i     // en este bloque se inicializa el programa, se asigna el valor @1 en la dirección @i, esta esta asignada en la dirección 16.
M=D


@0
D=A     // Se crea la variable sum que empieza después de la dirección 15, en este caso asignado a 17 y su valor es 0.
@sum     // aqui se van guardando las sumas de los numeros naturales por eso el valor aumenta exponencialmente
M=D

(LOOP)
@i
D=M
@100        // aqui se inicia el loop, @i apunta a @100 y el valor de ambas se resta, Si el valor es menor a 100
D=D-A
@END
D;JGE


@i
D=M    
@sum // se asigna el valor de @i a D y luego se suma al valor de @sum
M=D+M // el valor de @sum aumenta en cada ciclo del loop


@i
M=M+1   // el valor de @i aumenra en 1cada que se completa el loop

@LOOP // Se regresa al inicio del loop
0;JMP

(END)
@END  
0;JMP // se detiene el programa al llegar a 100