#include "cutsphere.h" 
#include <math.h>
CutSphere::CutSphere (int mx, int my, int mz, int raio){
    this -> x0=mx; this -> y0=my; this -> z0=mz; this -> raio=raio; //Posição 
}

CutSphere::~CutSphere(){
    std::cout << "Destrutor CutSphere" << std::endl;
}

void CutSphere::draw(Sculptor &s){
    int i,j,k, _dimx = 0, _dimy = 0, _dimz = 0;
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
                        s.cutVoxel(i,j,k);
                    }
                }
            }
        } 
    }
}