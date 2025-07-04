#ifndef ET2_H
#define ET2_H
#include <iostream>
#include "et1.h"

using namespace std;


//tentar puxar do et1.h 



class Imagem {
    public:
    
   int largura;
   int altura;
   Cor **mapa;
   


   //enteder essa parte melhor
  Imagem(int largura, int altura) {
    this->largura = largura;
    this->altura = altura;
    mapa = new Cor*[largura];
    for (int i = 0; i < largura; ++i) {
        mapa[i] = new Cor[altura];
    }
}

~Imagem() {
    for (int i = 0; i < largura; ++i) {
        delete[] mapa[i];
    }
    delete[] mapa;
}
   

   //definir dunções

   string encotrarPixel(int x,int y);

   void definirPixel(int x,int y,Cor c);

   void salvarFormatoPPM(string nomePPM);

};


#endif