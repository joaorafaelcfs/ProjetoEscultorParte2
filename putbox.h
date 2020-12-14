#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "Sculptor.h"
/**
 *  \brief Classe PutBox
 */
class PutBox: public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1;
public:
/** \brief Construtor da Classe \n
*   \param x0  x1 -- Ativa uma sequência de voxels no intervalo de x0 a x1
*   \param y0 y1 -- Ativa uma sequência de voxels no intervalo de y0 a y1
*   \param z0 z1 -- Ativa uma sequência de voxels no intervalo de z0 a z1
*   \param r -- Cor vermelha 
*   \param g -- Cor verde
*   \param b -- Cor azul  
*   \param a -- Transparencia */
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    /** \brief Destrutor da Classe \n*/
    ~PutBox();
    /** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor
    /** \brief Essa função é responsável por ativar todos os voxels compreendidos no intervalo [x0,x1], [y0,y1], [z0,z1].*/
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "putbox.cpp"

#endif // PUTBOX_H

#endif