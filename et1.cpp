#include <iostream>
#include <fstream>
#include <string>
#include "et1.h"
using namespace std;



void Paleta::inicializarPaleta(){

     Paleta cores = {

        2, //quantidade de cores
        {{ 255 , 0 , 0 } , { 0 , 255 , 0 }},//cores
        { 0, 10 }//valores associados as cores de mesmo indice

    };
   
}


void Paleta::lerCoresArquivo(string arq){

   

     ifstream arqCores(arq);
     int n;
      arqCores >> n;
      quantidade = n;
      
     for(int i = 0; i < n; i++) {
        arqCores >> valores[i];
        arqCores >> cores[i].R;
        arqCores >> cores[i].G;
        arqCores >> cores[i].B;
     }


   
     arqCores.close();

}



