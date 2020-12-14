#include "cutbox.h" 

CutBox::CutBox (int mx0, int mx1, int my0, int my1, int mz0, int mz1){
    this -> x0=mx0; this -> y0=my0; this -> z0=mz0; //Posição 
    this -> x1=mx1; this -> y1=my1; this -> z1=mz1; //Posição 
}

CutBox::~CutBox(){
    std::cout << "Destrutor CutBox" << std::endl;
}

void CutBox::draw(Sculptor &s){
    int i,j,k;
    if (x0 > x1 || y0 > y1 || z0 > z1 || x0 < 0 || y0 < 0 || z0 < 0){
        cout << "Dimensão errada" << endl;
        exit(1);
    }
    for (i=x0; i<=x1; i++){
        for (j=y0; j<=y1; j++){
            for (k=z0; k<=z1; k++){
                s.cutVoxel(i,j,k);
            }
        }
    }
}