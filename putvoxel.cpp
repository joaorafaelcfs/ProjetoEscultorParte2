#include "Sculptor.h"
#include "putvoxel.h" 
#include "interpretador.h"
#include <iostream>
#include <cstdlib>    // Biblioteca usado para o exit
using namespace std;
PutVoxel::PutVoxel (int x, int y, int z, float r, float g, float b, float a){
    this -> x=x; this -> y=y; this -> z=z; //Posição 
    this -> r=r; this -> g=g; this -> b=b; this -> a=a;  //Cores    
}

void PutVoxel::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    s.putVoxel(x,y,z);
}