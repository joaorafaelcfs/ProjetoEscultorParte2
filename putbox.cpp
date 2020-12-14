#include "Sculptor.h"
#include "putbox.h" 
#include "interpretador.h"
#include <iostream>
#include <cstdlib>    // Biblioteca usado para o exit
using namespace std;
PutBox::PutBox (int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a){
    this -> x0=x0; this -> y0=y0; this -> z0=z0; //Posição 
    this -> x1=x1; this -> y1=y1; this -> z1=z1; //Posição 
    this -> r=r; this -> g=g; this -> b=b; this -> a=a;  //Cores
    
}
PutBox::~PutBox(){
    
}
void PutBox::draw(Sculptor &s){
    int i,j,k;
    s.setColor(r,g,b,a);
    if (x0 > x1 || y0 > y1 || z0 > z1 || x0 < 0 || y0 < 0 || z0 < 0){
        cout << "Dimensão errada" << endl;
        exit(1);
    }
    for (i=x0; i<=x1; i++){
        for (j=y0; j<=y1; j++){
            for (k=z0; k<=z1; k++){
                s.putVoxel(i,j,k);
            }
        }
    }
}