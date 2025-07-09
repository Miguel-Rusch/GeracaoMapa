#ifndef ET3_H
#define ET3_H
#include <iostream>
#include <cmath>

using namespace std;

struct Ponto {
    int x;
    int y;


};
class MapaAltura{
    private:
    int tamanho;
    int elevado;//2^n -1 == tamanho
    int rugosidade;
    

    public:
    int **mapaComAltura;
      MapaAltura(int n, int ale) {
        tamanho = pow(2, n) + 1;
        mapaComAltura = new int*[tamanho];
        for (int i = 0; i < tamanho; i++) {
            mapaComAltura[i] = new int[tamanho]{0};  // inicializa com zero
        }

        elevado = n;
        rugosidade = ale;
    }

    ~MapaAltura(){
        for(int i = 0; i < tamanho; i++){
            delete[] mapaComAltura[i];
        }
        delete[] mapaComAltura;

    }




    void gerarAltura();

    int  altura_cordenada(int x,int y);

    int  pegarTamanho();

    void salvarMatrizArquivo(string arq);

    void lerMatrizArquivo(string arq);
    //funcoes auxiliares
    int mediaSquare(int x, int y, int deslocamento);

    bool defini(int x, int y, int deslocamento);
};



#endif