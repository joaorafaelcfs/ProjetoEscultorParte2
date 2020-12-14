#include "cutvoxel.h" 

CutVoxel::CutVoxel (int mx, int my, int mz){
    this -> x=mx; this -> y=my; this -> z=mz; //Posição 
}

void CutVoxel::draw(Sculptor &s){
    s.cutVoxel(x,y,z);
}