#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "et3.h"
using namespace std;

bool MapaAltura::defini(int x, int y, int deslocamento)
{
    bool def = false;
    if (x + deslocamento < tamanho && y + deslocamento < tamanho)
    {
        def = true;
    }
    return def;
}

int MapaAltura::mediaSquare(int x, int y, int deslocamento)
{
    int medi = 0;
    int i = 0;

    if (x - deslocamento >= 0)
    {
        medi = medi + mapaComAltura[x - deslocamento][y];
        i++;
    }
    if (x + deslocamento <= tamanho - 1)
    {
        medi = medi + mapaComAltura[x + deslocamento][y];
        i++;
    }

    if (y - deslocamento >= 0)
    {
        medi = medi + mapaComAltura[x][y - deslocamento];
        i++;
    }
    if (y + deslocamento <= tamanho - 1)
    {
        medi = medi + mapaComAltura[x][y + deslocamento];
        i++;
    }

    // cout << i << endl;
    medi = medi + rugosidade;

    return medi / i;
}

void MapaAltura::gerarAltura()
{
    vector<Ponto> pontosDefinidos;
    srand(20);

    // 4 cantos
    mapaComAltura[0][0] = 2;
    mapaComAltura[0][tamanho - 1] = 1;
    mapaComAltura[tamanho - 1][0] =  3;
    mapaComAltura[tamanho - 1][tamanho - 1] = 3;

    pontosDefinidos.push_back({0, 0});
    int deslocamento = (tamanho - 1) / 2;

    int rodar = pontosDefinidos.size();

    for (int i = 0; i < tamanho; i++)
    {
        // cout << i;
        int rodar = pontosDefinidos.size();

        for (int j = 0; j < rodar; j++)
        {

            int x = pontosDefinidos.at(j).x;
            int y = pontosDefinidos.at(j).y;

            // criando o do meid
            int linha = pontosDefinidos.at(j).x + (deslocamento);
            int coluna = pontosDefinidos.at(j).y + (deslocamento);

            // criando o square
            int sqareX = 0;
            int squareY = 0;

            // caso 1 diamante
            sqareX = linha;
            squareY = coluna;

            int media = (mapaComAltura[sqareX - deslocamento][squareY - deslocamento] +
                         mapaComAltura[sqareX - deslocamento][squareY + deslocamento] + mapaComAltura[sqareX + deslocamento][squareY - deslocamento] +
                         mapaComAltura[sqareX + deslocamento][squareY + deslocamento] + rugosidade) /
                        4;

            mapaComAltura[sqareX][squareY] = media;
            if (defini(sqareX, squareY, deslocamento))
            {
                pontosDefinidos.push_back({sqareX, squareY});
            }

            // caso 2
            sqareX = linha;
            squareY = coluna - deslocamento;

            mapaComAltura[sqareX][squareY] = mediaSquare(sqareX, squareY, deslocamento);
            if (defini(sqareX, squareY, deslocamento))
            {
                pontosDefinidos.push_back({sqareX, squareY});
            }

            // caso 3
            sqareX = linha + deslocamento;
            squareY = coluna;

            mapaComAltura[sqareX][squareY] = mediaSquare(sqareX, squareY, deslocamento);
            if (defini(sqareX, squareY, deslocamento))
            {
                pontosDefinidos.push_back({sqareX, squareY});
            }

            // caso 4
            sqareX = linha - deslocamento;
            squareY = coluna;

            mapaComAltura[sqareX][squareY] = mediaSquare(sqareX, squareY, deslocamento);
            if (defini(sqareX, squareY, deslocamento))
            {
                pontosDefinidos.push_back({sqareX, squareY});
            }

            // caso 5
            sqareX = linha;
            squareY = coluna + deslocamento;

            mapaComAltura[sqareX][squareY] = mediaSquare(sqareX, squareY, deslocamento);
            if (defini(sqareX, squareY, deslocamento))
            {
                pontosDefinidos.push_back({sqareX, squareY});
            }
        }

        deslocamento = deslocamento / 2;
        if (deslocamento == 0)
            break;
    }
}

int MapaAltura::altura_cordenada(int x, int y)
{
    return mapaComAltura[x][y];
}

int MapaAltura::pegarTamanho()
{
    return tamanho;
}

void MapaAltura::salvarMatrizArquivo(string arq)
{

    ofstream arquivoPPM;

    arquivoPPM.open(arq);

    int n = tamanho;

    arquivoPPM << n << " " << rugosidade << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arquivoPPM << mapaComAltura[i][j] << " ";
        }
        arquivoPPM << endl;
    }

    arquivoPPM.close();
}

void MapaAltura::lerMatrizArquivo(string arq)
{
    ifstream arqMapaTxt(arq);

    int novoTamanho;
    arqMapaTxt >> novoTamanho;

    for (int i = 0; i < tamanho; i++)
    {
        delete[] mapaComAltura[i];
    }
    delete[] mapaComAltura;

    tamanho = novoTamanho;
    int novaRugosidade;

    arqMapaTxt >> novaRugosidade;
    rugosidade = novaRugosidade;

    // da para melhorar se comecar ja com os numeros
    mapaComAltura = new int *[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        mapaComAltura[i] = new int[tamanho]{0}; // inicializa com zero
    }

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {

            arqMapaTxt >> mapaComAltura[i][j];
        }
    }

    // tem qu fazer log(tamanho,2) algo assim para descobrir elevado
    //  elevado = n;
}

void MapaAltura::criarImagem(Paleta paleta, string arq){
    Imagem im(tamanho,tamanho);
   
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            im.mapa[i][j] = tranformarAlturaCor(paleta,mapaComAltura[i][j]);
        }
    }

    im.salvarFormatoPPM(arq);
}

Cor MapaAltura::tranformarAlturaCor(Paleta paleta, int alt){
    //da para otimizar muito 
     
    int perto = paleta.valores[0] - alt;
    int guardarValor = 0;
    int val = 0;
    for(int  i = 1; i < paleta.quantidade; i++){
        val = paleta.valores[i] - alt;
        if(val*val < perto*perto){
            perto = val;
            guardarValor = i;
        }
    }
   
    return paleta.cores[guardarValor+1];
}