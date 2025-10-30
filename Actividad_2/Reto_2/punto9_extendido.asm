// Suma de 6 + 9
@6
D=A        // D = 6
@9
D=D+A      // D = 15
@16
M=D        // RAM[16] = 15

// Mostrar el resultado en pantalla
// Queremos encender 15 píxeles => 15 en binario = 0000000000001111
// Lo escribimos en RAM[16384] (pantalla, fila 0)
@16384     // Dirección de inicio de pantalla
A=A        // A = 16384
M=D        // RAM[16384] = 15 (encender primeros 4 píxeles)

(END)
@END
0;JMP      // Bucle infinito
