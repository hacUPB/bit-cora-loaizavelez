#include <iostream>

int suma(int a, int b) { // función que suma dos variables enteras
   int var = a + b;  // suma los valores de a y b y los almacena en var
   return var; // retorna el var 
}


int main() {
   int c = suma(6, 9); //llama la función suma, a=6 y b=9 y c= resultado
   std::cout << "El valor de c es: " << c << std::endl; 
   return 0; 
}