#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "Sculptor.h"
#include "figurageometrica.h"
/**
 *  \brief Classe CutEllipsoid
 */
class CutEllipsoid: public FiguraGeometrica{
    int x0, y0, z0, raiox, raioy, raioz;
public: 
/** \brief Construtor da Classe \n
*   \param mx -- Posição central da elipse no eixo x 
*   \param my -- Posição central da elipse no eixo y 
*   \param mz -- Posição central da elipse no eixo z
*   \param raiox -- Raio da elipse no eixo x
*   \param raioy -- Raio da elipse no eixo y
*   \param raioz -- Raio da elipse no eixo z  */
    CutEllipsoid (int mx, int my, int mz, int raiox, int raioy, int raioz);
/** \brief Destrutor da Classe \n*/
    ~CutEllipsoid();
/** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor*/
/** \brief Desativa todos os voxels que satisfazem à equação da elipsóide.*/
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "cutellipsoid.cpp"

#endif // CUTELLIPSOID_H

#endif