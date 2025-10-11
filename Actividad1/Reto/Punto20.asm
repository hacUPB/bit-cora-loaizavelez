// Espera tecla 'd'
(LOOP_KEY)
  @KBD
  D=M           // Leer entrada del teclado
  @100
  D=D-A         // Comparar con ASCII 'd'
  @draw
  D;JEQ         // Si coincide, dibujar

  @LOOP_KEY
  0;JMP         // Si no, seguir esperando

// Pegar aquí el bloque de dibujo que ya creaste
(draw)
  @SCREEN
  D=A
  @R12
  AD=D+M        // Aquí puedes inicializar R12 como 0 antes si lo necesitas
  // ... todas las filas del bitmap van aquí ...
  // Puedes colocar directamente el bloque que me compartiste

  @END
  0;JMP         // Finaliza y entra en bucle

(END)
  @END
  0;JMP