#include <iostream>
#include "et1.h"
#include "et2.h"




int main(){
    
    Imagem img(10,15);
     Paleta p1;
    
     p1.lerCoresArquivo("cores.txt");
    


   
    return 0;
}

// para compilar
// g++ main.cpp et1.cpp -o cor
//./cor