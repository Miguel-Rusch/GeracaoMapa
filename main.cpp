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

    int tamanho = ma.pegarTamanho();

     for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            cout << setw(4) << ma.mapaComAltura[i][j]; // 4 espaços para alinhamento (3 dígitos + espaço)
        }
        cout << endl;
    }

    cout << ma.altura_cordenada(8,0);

    ma.salvarMatrizArquivo("qe.txt");
   
    return 0;
}

// para compilar
// g++ main.cpp et1.cpp et2.cpp et3.cpp -o cor
// ./cor