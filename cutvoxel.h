#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "Sculptor.h"
#include "figurageometrica.h"
/**
 *  \brief Classe CutVoxel
 */
class CutVoxel: public FiguraGeometrica{
    int x, y, z;
public: 
/** \brief Construtor da Classe \n
*   \param mx -- Desativa o voxel na posição x
*   \param my -- Desativa o voxel na posição y
*   \param mz -- Desativa o voxel na posição z */  
    CutVoxel (int mx, int my, int mz);
/** \brief Destrutor da Classe*/
    ~CutVoxel(){};
/** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor*/
/** \brief Essa função é responsável por excluir um voxel na posição x,y,z*/
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "cutvoxel.cpp"

#endif // CUTVOXEL_H

#endif