#include <iostream>
#include "et1.h"
#include "et2.h"



int main(){
    
    Imagem img(10,15);
     Paleta p1;
    
     p1.lerCoresArquivo("cores.txt");

    
    img.definirPixel(2,2,{255,0,225});
    cout << img.encotrarPixel(2,2);
    
    img.salvarFormatoPPM("a.ppm");
   
    return 0;
}

// para compilar
// g++ main.cpp et1.cpp et2.cpp -o cor
// ./cor