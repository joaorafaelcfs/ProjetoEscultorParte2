#include "interpretador.h"
#include <fstream>
#include <sstream>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include <iostream>
int dx, dy,dz;
Interpretador::Interpretador(){
    cout << "Contrutor Interpretador" << endl;
}

std::vector<FiguraGeometrica*> Interpretador::parse(std::string filename){
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;
    
    fin.open(filename.c_str());
    if (!fin.is_open()){
         // verifica se o fluxo foi aberto
        std::cout << "Não abriu" << filename << std::endl;
        exit(0);
    }

    while (fin.good()){ 
        std::getline (fin, s); // fin >> s
        if (fin.good()){
            //lança o string s no fluxo ss
            ss.clear();
            ss.str(s);
            ss >> token;
            //realiza o pasing dos tokens
            if (ss.good()){
                // dimensoes da tela
                if (token.compare("dim") == 0){
                    ss >> dimx >> dimy >> dimz;
                    dx = dimx;
                    dy = dimy;
                    dz = dimz;
                    std::cout << "dimx = " << dimx << " dimy = " << dimy << " dimz = " << dimz << std::endl;
                }
                //usuario define brush
                else if (token.compare("putvoxel") == 0){
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));
                }
                else if (token.compare("cutvoxel") == 0){
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0;
                    figs.push_back(new CutVoxel(x0,y0,z0));
                }
                else if (token.compare("putbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
                }
                else if (token.compare("cutbox") == 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
                }
                else if (token.compare("putsphere") == 0){
                    int x0, y0, z0, raio ;
                    ss >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));
                }
                else if (token.compare("cutsphere") == 0){
                    int x0, y0, z0, raio ;
                    ss >> x0 >> y0 >> z0 >> raio;
                    figs.push_back(new CutSphere(x0,y0,z0,raio));
                }
                else if (token.compare("putellipsoid") == 0){
                    int x0, y0, z0, raiox, raioy, raioz;
                    ss >> x0 >> y0 >> z0 >> raiox >> raioy >> raioz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(x0,y0,z0,raiox,raioy,raioz,r, g, b, a));
                }
                else if (token.compare("cutellipsoid") == 0){
                    int x0, y0, z0, raiox, raioy, raioz;
                    ss >> x0 >> y0 >> z0 >> raiox >> raioy >> raioz;
                    figs.push_back(new CutEllipsoid(x0,y0,z0,raiox,raioy,raioz));
                }
            }
        }
    }
    return (figs);
}

int Interpretador::getDimx(){
    return dx;
}

int Interpretador::getDimy(){
    return dy;
}

int Interpretador::getDimz(){
    return dz;
}