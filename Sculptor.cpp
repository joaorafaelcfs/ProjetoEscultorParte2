#include "Sculptor.h" // Header onde está declarada a classe Sculptor
#include "interpretador.h"
#include <iostream>   // Biblioteca Padrao
#include <cstdlib>    // Biblioteca usado para o exit
#include <fstream>    // Biblioteca usado para as streams
#include <cmath>      // Biblioteca usado para operações matematicas
#include <queue>

using namespace std;

// Construtor da classe Esculptor
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;
    cout << "Dimensoes" << endl;
    cout << " x = " << nx <<" y = " << ny << " z = " << nz << endl;
    if (_nx <= 0 || _ny <= 0 || _nz <= 0){
        _nx = _ny = _nz = 0;
    }
// Alocaçao da matriz 3d
    v = new Voxel **[nx];
    if ( v == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }
    v[0] = new Voxel*[nx*ny];
    if (v[0] == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }
    v[0][0] = new Voxel[nx*ny*nz];
    if (v[0][0] == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }

    for (int i = 1; i < nx; i++){
        v[i] = v[i-1] + ny;
    }

    for (int j = 1; j < (nx*ny); j++){
        v[0][j] = v[0][j-1] + nz;

    }
}

// Destrutor da classe Esculptor
Sculptor::~Sculptor(){  
//liberação da memoria que foi alocada para a matriz 3D
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

// Definição da cor do desenho
void Sculptor::setColor (float _r, float _g, float _b, float alpha){ 
    if (_r < 0 || _r > 1 || _g < 0 || _g > 1 || _b < 0 || _b > 1 || alpha < 0 || alpha > 1){
        cout << "Valor errado para cor " << endl;
        exit(1);
    }
    r = _r*255;
    g = _g*255;
    b = _b*255;
    a = alpha;
}
// Ativa o Voxel na posição (x,y,z), 
void Sculptor::putVoxel (int x, int y ,int z){ 
    
// isOn = true
    if ( x < 0 || x > nx || y < 0 || y > ny || z < 0 || z > nz){
        cout << "Valor errado para ativar o Voxel" << endl;
        exit(1);
    } else {
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

// Desativa o Voxel na posição (x,y,z)
void Sculptor::cutVoxel (int x, int y, int z){ 
//isOn = false
    if ( x < 0 || x > nx || y < 0 || y > ny || z < 0 || z > nz){
        cout << "Valor errado para desativar o Voxel" << endl;
        exit(1);
    } else {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::writeOFF(char *filename){
// variáveis relacionado ao n° de vertices, faces e arestas
    int nv = 0, nf = 0, i, j, k;

// variavel para faces
    int face = 0;

    ofstream escultura;

    escultura.open(filename); // abertura do arquivo off que receberá as informações necessárias para a escultura

    if (escultura.is_open()){
        cout << "Arquivo aberto" << endl;
    } else {
        cout << "Arquivo não abriu" <<endl;
        exit(1);
    }
   
// Escrever primeira linha no arquivo.
    escultura << "OFF" << endl;
// Contar a quantidade de vertices e faces que deverão ser incluidos no arquivo
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny ; j++){
            for (k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                    //cout << "i = " << i << " j = " << j << " k = " << k << endl;
                    nv = nv + 8;
                    nf = nf + 6;
                }
            }
        }
    }
// Escrever a quantidade de vertices, faces e arestas
    escultura << nv << " " << nf << " 0" << endl;

    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++){
            for (k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                    escultura << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    escultura << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    escultura << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    escultura << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    escultura << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    escultura << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    escultura << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    escultura << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }
    
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++){
            for (k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                    escultura << 4 << " " << face + 0 << " " << face + 3 << " " << face + 2 << " " << face + 1 << " " <<
                    v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    escultura << 4 << " " << face + 4 << " " << face + 5 << " " << face + 6 << " " << face + 7 << " " <<
                    v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    escultura << 4 << " " << face + 0 << " " << face + 1 << " " << face + 5 << " " << face + 4 << " " <<
                    v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    escultura << 4 << " " << face + 0 << " " << face + 4 << " " << face + 7 << " " << face + 3 << " " <<
                    v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    escultura << 4 << " " << face + 3 << " " << face + 7 << " " << face + 6 << " " << face + 2 << " " <<
                    v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    escultura << 4 << " " << face + 1 << " " << face + 2 << " " << face + 6 << " " << face + 5 << " " <<
                    v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    face = face + 8;
                }
            }
        }
    }
    if (escultura.is_open()){
        cout << "Arquivo Salvo" << endl;
    }

    escultura.close();
}