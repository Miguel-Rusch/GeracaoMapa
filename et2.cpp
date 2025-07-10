#include <iostream>
#include <fstream>
#include <string>
#include "et2.h"
using namespace std;

string Imagem::encotrarPixel(int x, int y)
{
    string res;
    int r, g, b;
    r = mapa[x][y].R;
    g = mapa[x][y].G;
    b = mapa[x][y].B;
    res = to_string(r) + " " + to_string(g) + " " + to_string(b);

    return res;
}

void Imagem::definirPixel(int x, int y, Cor c)
{
    mapa[x][y] = c;
}

void Imagem::salvarFormatoPPM(string nomeArq)
{

    ofstream arquivoPPM;

    arquivoPPM.open(nomeArq);

    arquivoPPM << "P3\n";

    arquivoPPM << largura << " " << altura << "\n";

    arquivoPPM << "255\n";

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            // cout << encotrarPixel(i,j) << " ";
            arquivoPPM << encotrarPixel(i, j) << " ";
        }
        arquivoPPM << endl;
        // cout << endl;
    }

    arquivoPPM.close();
}
