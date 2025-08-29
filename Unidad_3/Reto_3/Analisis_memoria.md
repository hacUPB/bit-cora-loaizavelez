### Analisis.

**spherePositions**

```c++

+		[Vista sin formato]	{_Myval2={_Myfirst=0x0000000007caea20 {x=-512.000000 r=-512.000000 s=-512.000000 ...} _Mylast=0x0000000007cb0280 {...} ...} }	std::_Compressed_pair<std::allocator<glm::vec<3,float,0>>,std::_Vector_val<std::_Simple_types<glm::vec<3,float,0>>>,1>

```
La varaible esta guardado en el vector 3, este vector esta guardado en el stack, lo que significa que cuando termina de recorrer el programa este se destruye, pero, la información queda almacena esta en heap. 


```c++
+		[Vista sin formato]	{_Myval2={_Myfirst=0x0000000007c46120 {r='ÿ' g='\0' b='\0' ...} _Mylast=0x0000000007c46138 {r='ý' g=...} ...} }	std::_Compressed_pair<std::allocator<ofColor_<unsigned char>>,std::_Vector_val<std::_Simple_types<ofColor_<unsigned char>>>,1>

 //_Myval2={_Myfirst=0x0000000007c46120, _Mylast=0x0000000007c46138}

```
**_Myval2={_Myfirst=0x0000000007c46120, _Mylast=0x0000000007c46138}.** este sección esta guradada en la memoria heap, estan asignados los colores RGB de las esferas. Si estuviera en el stack al salir de la función, la información se perdería, se destruye al terminar de compilar.


[Video_Trabajo](https://youtu.be/KTzzkoMWYcs?si=FWHgelXQc6DAu2g3)

### Fotos del trabajo 

![Malla](<foto mallas-1.png>)

![Pruebas memoria](<pruebas memoria-1.png>)