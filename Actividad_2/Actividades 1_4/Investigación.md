## Actividad 1

-  **¿Qué es la entrada-salida mapeada a memoria?**

**R//** se usan los dispositivos como la pantalla y el teclado, se escribe la dirección de memoria asignada a la pantalla con el screen memory map iniciando desde la dirección 16384 , también el teclado tiene asginado unas direcciones de memoria este esta asignado a la ultima drección, cada letra tiene un valor asginado en ASCII.

- **¿Cómo se implementa en la plataforma Hack?**

**R//** Dentro del simulador la pantalla usa la dirección de memoria 16384 hasta la 24575, el teclado tiene asignada la ultima dirección la 24756, cada letra tiene un valor en ASCII que se ve reflejado en esta dirección.

- **Inventa un programa que haga uso de la entrada-salida mapeada a memoria.**

    @KBD //KBD = 24576
        D=M 

        @100

        D=D-A

        @DRAW

        D;JEQ 

        @KBD //KBD = 24576

        D=M 

        @101

        D=D-A

		@CLEAR

		D;JEQ

		@LOOP

		0;JMP
		

- **Investiga el funcionamiento del programa con el simulador.**

**R//** este programa genera una imagen, y se usa la dirección del teclado para que al ser presionada la letra "e", termine el loop y vuelva al incio borrando todo lo que hay en pantalla.