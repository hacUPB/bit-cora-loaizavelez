
@10
D=A // se carga el valor de @10 en la dirección A
@var // luego el @var apunta a esa dirección y guarda el valor de @10 en Var
M=D


@var
D=A
@punt // se guarda la dirección de @Var en el puntero 
M=D


@20
D=A
// en esta parte del codigo el @20 esta cargado en A

@punt  
A=M   
// Aqui se mira al puntero que tiene guardada la dirección de @var
M=D    
//aqui se traslada esa información de @var = @16 pasando a incrustarse al puntero @punt=@17