#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "Sculptor.h"
/**
 *  \brief Classe PutVoxel
 */
class PutVoxel: public FiguraGeometrica {
    int x,y,z;
public:
/** \brief Construtor da Classe \n
*   \param x -- Desativa o voxel na posição x
*   \param y -- Desativa o voxel na posição y
*   \param z -- Desativa o voxel na posição z 
*   \param r -- Cor vermelha 
*   \param g -- Cor verde
*   \param b -- Cor azul
*   \param a -- Transparencia*/  
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
/** \brief Destrutor da Classe*/
    ~PutVoxel(){}
/** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor*/
/** \brief Essa função é responsável por ativar um voxel na posição x,y,z*/
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "putvoxel.cpp"

#endif // PUTVOXEL_H

#endif