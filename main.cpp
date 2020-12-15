#include <iostream>
#include "Sculptor.h" 
#include <vector>
#include "interpretador.h"

using namespace std;
/** 
 *  \brief Projeto de Programação Avançada
*/
/** 
 *  Autores: João Rafael e Myllena Sila
*/

int main(){
    Sculptor *s1;
    
    Interpretador parser;

    std::vector<FiguraGeometrica*>figs;
    
    figs = parser.parse("batman.txt");

    s1 = new Sculptor (parser.getDimx(), parser.getDimy(), parser.getDimz());

    for (size_t i=0; i<figs.size(); i++){
        figs[i]->draw(*s1);
    }

    s1 -> writeOFF((char*)"batman.off");

    for (size_t i=0; i<figs.size();i++){
        delete figs[i];
    }
    delete s1;
    return 0;

}