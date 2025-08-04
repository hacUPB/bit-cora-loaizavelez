// var = 10
@10
D=A
@var
M=D

// punt = &var
@var
D=A
@punt
M=D

// *punt = 20
@20
D=A
@punt
A=M    // A = contenido de punt (es decir, dirección de var)
M=D    // M = 20 → var = 20