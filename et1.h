#ifndef ET1_H
#define ET1_H
#include <iostream>
using namespace std;


class Cor {       
  public:            
    int R;
    int G;
    int B;
};

class Paleta {
    public:
    int quantidade;
    Cor cores[100];//Armazena os tipos diferentes de cores
    int valores[100];// Armazena os valores que se conectam com as cores

    void inicializarPaleta();
    void lerCoresArquivo(string arq);
};


#endif