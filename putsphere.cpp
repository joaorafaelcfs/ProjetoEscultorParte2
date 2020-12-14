#include "Sculptor.h"
#include "putsphere.h" 
#include "interpretador.h"
#include <iostream>
#include <cstdlib>    // Biblioteca usado para o exit
#include <math.h>
using namespace std;

PutSphere::PutSphere (int x0, int y0, int z0, int raio, float r, float g, float b, float a){
    this -> x0=x0; this -> y0=y0; this -> z0=z0; this -> raio=raio; //Posição
    this -> r=r; this -> g=g; this -> b=b; this -> a=a;  //Cores 

}
PutSphere::~PutSphere(){
    std::cout << "Destrutor PutSphere" << std::endl;
}
void PutSphere::draw(Sculptor &s){
    int i,j,k, _dimx = 0, _dimy = 0, _dimz = 0;
    s.setColor(r,g,b,a);
    cout << "cores da esfera = " << r << ", "<< g << ", " << b << endl;
    Interpretador c;
    _dimx = c.getDimx(); //ajeitar
    _dimy = c.getDimy();
    _dimz = c.getDimz();
    if (x0 < 0 || y0 < 0 || z0 < 0 || raio < 0 || x0 + raio > _dimx || y0 + raio > _dimy || z0 + raio > _dimz){
        cout << "Dimensão errada" << endl;
        exit(1);
    } else {
        float d;
        for (i = 0; i <= _dimx; i++){
            for (j = 0; j <= _dimy; j++){
                for (k = 0; k <= _dimz; k++){
                    //distancia entre tres pontos
                    d = sqrt(pow(i-x0,2) + pow(j-y0, 2) + pow(k-z0, 2));
                    if (d <= raio){
                        s.putVoxel(i,j,k);
                    }
                }
            }
        } 
    }
}