#include "cutellipsoid.h" 
#include <math.h>
CutEllipsoid::CutEllipsoid (int mx, int my, int mz, int raiox, int raioy, int raioz){
    this -> x0=mx; this -> y0=my; this -> z0=mz; this -> raiox=raiox; this -> raioy=raioy; this -> raioz=raioz;  //Posição
}

CutEllipsoid::~CutEllipsoid(){
    std::cout << "Destrutor CutEllipsoid" << std::endl;
}

void CutEllipsoid::draw(Sculptor &s){
    int i,j,k, _dimx = 0, _dimy = 0, _dimz = 0;
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
                    if ( i >= 0 && i < _dimx && j >=0 && j <= _dimy && k >=0 && k < _dimz){
                        d = (float) pow ((i - x0),2)/pow(raiox,2) + (float)pow((j-y0),2)/pow(raioy,2) + (float)pow((k-z0),2)/pow(raioz,2);     
                        if (d <= 1.0){
                            s.cutVoxel(i,j,k);
                        }
                    } 
                } 
            }
        } 
    }
}