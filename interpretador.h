#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include "figurageometrica.h"
#include <string>
#include <iostream>
/**
 *  \brief Classe Interpretador
 */
class Interpretador{
    int dimx, dimy, dimz; // dimensões do escultor ... 1° linha da escultura
    float r, g, b, a; // ler as cores
public:
/** \brief Construtor da Classe \n*/
    Interpretador();
    std::vector<FiguraGeometrica *> parse(std::string filename); //metodo parse que faz a interpretação
    /**
* \param getDimx -- Metodo que retorna a dimensao do eixo x
* \param getDimy -- Metodo que retorna a dimensao do eixo y
* \param getDimz -- Metodo que retorna a dimensao do eixo z */  
    int getDimx(); int getDimy(); int getDimz(); // metodos que retorna a dimensao

};

#ifdef __GNUC__
#include "interpretador.cpp"

#endif // INTERPRETADOR_H

#endif