#include <iostream>
#include <fstream>
#include <string>
#include "et2.h"
using namespace std;

string Imagem::encotrarPixel(int x,int y){
    string res;
    res = (mapa[x][y].R + " " + mapa[x][y].G) + " " + mapa[x][y].B + " ";
   
    return res;
}

void Imagem::definirPixel(int x,int y,Cor c){
    mapa[x][y] = c;
}




void Imagem::salvarFormatoPPM(string nomeArq){
    
    ofstream arquivoPPM;

    arquivoPPM.open(nomeArq);

    arquivoPPM << "P3\n";
    arquivoPPM <<largura << " " << altura << "/n";
    
    for(int i = 0; i < largura; i++){
        for(int j = 0; j < altura;j++){
            arquivoPPM << encotrarPixel(i,j);
        }
    }

    arquivoPPM.close();


}





