#include <iostream>
#include "et1.h"
#include "et2.h"

void Imagem::encotrarPixel(int x,int y){
    cout <<  mapa[x][y].R << " , " << mapa[x][y].G << " , " << mapa[x][y].B;
   
    
}


int main(){
    
    Imagem img(10,15);
     Paleta p1;
    
     p1.lerCoresArquivo("cores.txt");
    
    img.encotrarPixel(2,2);
    

   
    return 0;
}

// para compilar
// g++ main.cpp et1.cpp -o cor
//./cor