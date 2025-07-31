``` as
(LOOP)

        @KBD //KBD = 24576
        D=M 
        @100
        D=D-A
        @DRAW
        D;JEQ 
		D=M
		@CLEAR
		D;JEQ
		@LOOP
		0;JMP
		
      
(DRAW)
```

