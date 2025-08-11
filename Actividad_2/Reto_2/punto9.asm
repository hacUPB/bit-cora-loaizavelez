// Cargar a = 6
@6
D=A
@a        // dirección 16
M=D

// Cargar b = 9
@9
D=A
@b        // dirección 17
M=D

// Simular suma(a, b)
@a
D=M       // D = a
@b
D=D+M     // D = a + b
@var      // dirección 18
M=D       // var = a + b

// Simular return: c = var
@var
D=M
@c        // dirección 19
M=D

// Fin del programa (bucle infinito)
(END)
@END
0;JMP