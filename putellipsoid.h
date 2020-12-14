#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"
#include "Sculptor.h"

/**
 *  \brief Classe PutEllipsoid
 */
class PutEllipsoid: public FiguraGeometrica {
    int x0, y0, z0, raiox, raioy, raioz;
public:
/** \brief Construtor da Classe \n
*   \param x0 -- Posição central da elipse no eixo x 
*   \param y0 -- Posição central da elipse no eixo y 
*   \param z0 -- Posição central da elipse no eixo z
*   \param raiox -- Raio da elipse no eixo x
*   \param raioy -- Raio da elipse no eixo y
*   \param raioz -- Raio da elipse no eixo z 
*   \param r -- Cor vermelha 
*   \param g -- Cor verde
*   \param b -- Cor azul 
*   \param a -- Transparencia */
    PutEllipsoid(int x0, int y0, int z0, int raiox, int raioy, int raioz, float r, float g, float b, float a);
/** \brief Destrutor da Classe \n*/
    ~PutEllipsoid();
/** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor*/
/** \brief Ativa todos os voxels que satisfazem à equação da elipsóide. \n Atribui a ele a cor atual definida na função setColor*/
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "putellipsoid.cpp"

#endif // PUTELLIPSOID_H

#endif