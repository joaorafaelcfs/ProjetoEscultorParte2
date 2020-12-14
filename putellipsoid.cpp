#include "Sculptor.h"
#include "putellipsoid.h" 
#include "interpretador.h"
#include <iostream>
#include <cstdlib>    // Biblioteca usado para o exit
#include <math.h>
using namespace std;

PutEllipsoid::PutEllipsoid (int x0, int y0, int z0, int raiox, int raioy, int raioz, float r, float g, float b, float a){
    this -> x0=x0;; this -> y0=y0; this -> z0=z0; this -> raiox=raiox; this -> raioy=raioy; this -> raioz=raioz;  //Posição
    this -> r=r; this -> g=g; this -> b=b; this -> a=a;  //Cores 

}
PutEllipsoid::~PutEllipsoid(){

}
void PutEllipsoid::draw(Sculptor &s){
    int i,j,k, _dimx = 0, _dimy = 0, _dimz = 0;
    s.setColor(r,g,b,a);
    Interpretador c;
    _dimx = c.getDimx(); //ajeitar
    _dimy = c.getDimy();
    _dimz = c.getDimz();
    if (x0 < 0 || y0 < 0 || z0 < 0 || raiox < 0 || raioy < 0 || raioz < 0 || x0 + raiox > _dimx || y0 + raioy > _dimy || z0 + raioz > _dimz){
        cout << "Dimensão errada" << endl;
        exit(1);
    } else {
        float d;
        for ( i =  x0 - raiox; i < x0 + raiox; i++){
            for (j = y0 - raioy; j < y0 + raioy; j++){
                for (k = z0 - raioz; k < z0 + raioz; k++){
                    // equação da elipsoide
                     d = (float) pow ((i - x0),2)/pow(raiox,2) + (float)pow((j-y0),2)/pow(raioy,2) + (float)pow((k-z0),2)/pow(raioz,2);            
                    if (d <= 1.0){
                        s.putVoxel(i,j,k);
                    }
                }
                
            }
        }
    }
}