#include <iostream>
#include <iomanip>
#include "et1.h"
#include "et2.h"
#include "et3.h"



int main(){
    
    // Imagem img(3,2);
    //  Paleta p1;
    
    //  p1.lerCoresArquivo("cores.txt");

    
    // img.definirPixel(0,0,{255,255,225});


    
    // img.salvarFormatoPPM("a.ppm");

    MapaAltura ma(3,0);


    ma.gerarAltura();

    

     for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << setw(4) << ma.mapaComAltura[i][j]; // 4 espaços para alinhamento (3 dígitos + espaço)
        }
        cout << endl;
    }

   
    return 0;
}

// para compilar
// g++ main.cpp et1.cpp et2.cpp et3.cpp -o cor
// ./cor