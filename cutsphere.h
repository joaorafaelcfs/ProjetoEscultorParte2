#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "Sculptor.h"
#include "figurageometrica.h"
/**
 *  \brief Classe CutSphere
 */
class CutSphere: public FiguraGeometrica{
    int x0, y0, z0, raio;
public: 
/** \brief Construtor da Classe \n
*   \param mx -- Posição central da esfera no eixo x 
*   \param my -- Posição central da esfera no eixo y 
*   \param mz -- Posição central da esfera no eixo z
*   \param raio -- Raio da esfera  */
    CutSphere (int mx, int my, int mz, int raio);
/** \brief Destrutor da Classe*/
    ~CutSphere();
/** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor*
/** \brief Ativa todos os voxels que satisfazem à equação da esfera. \n Atribui a ele a cor atual definida na função setColor */
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "cutsphere.cpp"

#endif // CUTSPHERE_H

#endif