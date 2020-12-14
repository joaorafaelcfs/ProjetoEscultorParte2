#ifndef CUTBOX_H
#define CUTBOX_H
#include "Sculptor.h"
#include "figurageometrica.h"
/**
 *  \brief Classe CutBox
 */
class CutBox: public FiguraGeometrica{
    int x0, x1, y0, y1, z0, z1;
public: 
/** \brief Construtor da Classe \n
*   \param mx0  mx1 -- Desativa uma sequência de voxels no intervalo de x0 a x1
*   \param my0 my1 -- Desativa uma sequência de voxels no intervalo de y0 a y1
*   \param mz0 mz1 -- Desativa uma sequência de voxels no intervalo de z0 a z1 */
    CutBox (int mx0, int mx1, int my0, int my1, int mz0, int mz1);
    /** \brief Destrutor da Classe */
    ~CutBox();
    /** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor
    /** \brief Essa função é responsável por desativar todos os voxels compreendidos no intervalo [x0,x1], [y0,y1], [z0,z1].*/
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "cutbox.cpp"

#endif // CUTBOX_H

#endif