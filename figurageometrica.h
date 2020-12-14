#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"
/**
 *  \brief Classe FiguraGeometrica
 */
class FiguraGeometrica{
    protected:
        float r,g,b,a; // Cores
    public:
/** \brief Construtor da Classe \n*/
        virtual ~FiguraGeometrica(){}; // classe abstrata, porque possui uma função virtual pura
/** \brief Essa é uma função virtual que instrua o objeto a se desenhar em um objeto do tipo Sculptor*/
        virtual void draw(Sculptor &s) = 0;
};

#endif // FIGURAGEOMETRICA_H