//RAM[200] = 250
@250
D=A
@200
M=D
//RAM[3]= 250
@250
D=A
@3
M=D

@15
D=A
@3
M=M-D
//
@200
D=M
@100
M=D

//RAM[2] =RAM[0]+RAM[1]+17
@43
D=A
@0
M=D

@30
D=M
@1
M=M+D

