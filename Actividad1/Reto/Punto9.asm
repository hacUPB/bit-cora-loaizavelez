// i = 1
@i
M=1
// sum = 0
@sum
M=0
// sum = sum + i
@i
D=M
@sum
M=D+M
// i = i + 1
@i
D=M+1
@i
M=D

1. se incializa con la variable i=1, en la variable suma se inicializa en 0, luego se suma el valor i+sum incrementenado el valor i en 1.
2. la varaible i esta guardada en dirección de RAM 16 y Suma en RAM 17

3.Optimización 

@i
M=M+i