#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "et3.h"
using namespace std;

bool MapaAltura::defini(int x,int y,int deslocamento){
    bool def = false;
    if(x + deslocamento < tamanho && y + deslocamento < tamanho){
        def = true;
    }
    return def;
}

int MapaAltura::mediaSquare(int x,int y,int deslocamento){
    int medi = 0;
    int i = 0;
 
   

    if(x - deslocamento >= 0){
        medi = medi + mapaComAltura[x-deslocamento][y];
        i++;
    }
    if(x + deslocamento <= tamanho -1){
        medi = medi + mapaComAltura[x+deslocamento][y];
        i++;
    }

    if(y - deslocamento >= 0){
        medi = medi + mapaComAltura[x][y - deslocamento];
        i++;    
    }
    if(y + deslocamento <= tamanho -1){
        medi = medi + mapaComAltura[x][y + deslocamento];
        i++;
    }

      // cout << i << endl;
    medi = medi + rugosidade;
   
    return medi/i;
}


void MapaAltura::gerarAltura(){
    vector<Ponto> pontosDefinidos;


    //4 cantos
    mapaComAltura[0][0] = rand()%100;
    mapaComAltura[0][tamanho-1] = rand()%100;
    mapaComAltura[tamanho-1][0] = rand()%100;
    mapaComAltura[tamanho-1][tamanho-1] = rand()%100;


    pontosDefinidos.push_back({0,0});
    int deslocamento = (tamanho -1)/2;
    
    


    int rodar = pontosDefinidos.size();

    for(int i = 0; i < pow(2,elevado);i++){
       // cout << i;
        int rodar = pontosDefinidos.size();

        
            
        
        
        for(int j = 0; j < rodar; j++){

            int x = pontosDefinidos.at(j).x;
            int y = pontosDefinidos.at(j).y;
            
            


           
            //criando o do meid
            int linha = pontosDefinidos.at(j).x + (deslocamento);
            int coluna = pontosDefinidos.at(j).y + (deslocamento);
            

            //criando o square
            int sqareX = 0;
            int squareY = 0;

           
                //caso 1
                    sqareX = linha;
                    squareY = coluna;
                   
                   int media = (mapaComAltura[sqareX - deslocamento][squareY - deslocamento] + 
                   mapaComAltura[sqareX - deslocamento][squareY + deslocamento] + mapaComAltura[sqareX + deslocamento][squareY - deslocamento] + 
                   mapaComAltura[sqareX + deslocamento][squareY + deslocamento]+rugosidade)/4;
                   
                    mapaComAltura[sqareX][squareY] = media;
                     if(defini(sqareX,squareY,deslocamento)){
                        pontosDefinidos.push_back({sqareX,squareY});   
                     }
                    
                //caso 2
                    sqareX = linha;
                    squareY = coluna - deslocamento;
                   
                    mapaComAltura[sqareX][squareY] = mediaSquare(sqareX,squareY,deslocamento);
                     if(defini(sqareX,squareY,deslocamento)){
                        pontosDefinidos.push_back({sqareX,squareY});
                     }
                
                //caso 3
                    sqareX = linha + deslocamento;
                    squareY = coluna;
                   
                    mapaComAltura[sqareX][squareY] = mediaSquare(sqareX,squareY,deslocamento);
                     if(defini(sqareX,squareY,deslocamento)){
                        pontosDefinidos.push_back({sqareX,squareY});
                     }
                
                //caso 4
                    sqareX = linha - deslocamento;
                    squareY = coluna;
                   
                    mapaComAltura[sqareX][squareY] = mediaSquare(sqareX,squareY,deslocamento);
                     if(defini(sqareX,squareY,deslocamento)){
                        pontosDefinidos.push_back({sqareX,squareY});
                     }

                //caso 5
                    sqareX = linha;
                    squareY = coluna + deslocamento;
                   
                    mapaComAltura[sqareX][squareY] = mediaSquare(sqareX,squareY,deslocamento);
                     if(defini(sqareX,squareY,deslocamento)){
                        pontosDefinidos.push_back({sqareX,squareY});
                    }
                    
                   

                
                
            

        }


        deslocamento = deslocamento/2;
        if(deslocamento == 0)break;

    }
}









