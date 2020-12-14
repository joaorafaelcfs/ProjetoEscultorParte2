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
    
    figs = parser.parse("lata51.txt");

    s1 = new Sculptor (parser.getDimx(), parser.getDimy(), parser.getDimz());

    cout << "tamanho = " << figs.size() << endl;
    for (size_t i=0; i<figs.size(); i++){
        cout << "draw" << endl;
        figs[i]->draw(*s1);
    }
    
    s1 -> writeOFF((char*)"lata51.off");

    for (size_t i=0; i<figs.size();i++){
        delete figs[i];
    }

    delete s1;
    return 0;

}