#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "Sculptor.h"
/**
 *  \brief Classe PutSphere
 */
class PutSphere: public FiguraGeometrica {
    int x0, y0, z0, raio;
public:
/** \brief Construtor da Classe \n
*   \param x0 -- Posição central da esfera no eixo x 
*   \param y0 -- Posição central da esfera no eixo y 
*   \param z0 -- Posição central da esfera no eixo z
*   \param raio -- Raio da esfera
*   \param r -- Cor vermelha 
*   \param g -- Cor verde
*   \param b -- Cor azul
*   \param a -- Transparencia  */
    PutSphere(int x0, int y0, int z0, int raio, float r, float g, float b, float a);
/** \brief Destrutor da Classe*/
    ~PutSphere();
/** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor
/** \brief Ativa todos os voxels que satisfazem à equação da esfera. \n Atribui a ele a cor atual definida na função setColor */
    void draw(Sculptor &s);
};

#ifdef __GNUC__
#include "putsphere.cpp"

#endif // PUTSPHERE_H

#endif