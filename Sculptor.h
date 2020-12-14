#ifndef SCULPTOR_H_INCLUDED
#define SCULPTOR_H_INCLUDED
#include <string>
#include <vector>

/** 
 *  \brief Declaração do Struct Voxel \n
 *  No struct Voxel é armazenado variaveis que irão determinar as cores (r,g,b) e transparência (a) do objeto,
 *  como também  teremos a propriedade isOn que define se o voxel correspondete deve ser incluído no arquivo digital.
 *  \param r - Cor vermelha
 *  \param g - Cor verde
 *  \param b - Cor azul
 *  \param a - Transparência
 *  \param isOn - Incluir ou não no arquivo digital
*/

struct Voxel {
  float r,g,b; // Cores
  float a; // Transparencia
  bool isOn; // Included or not
};

/**
 *  \brief Classe Sculptor
 */

class Sculptor {
protected:
  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
/** \brief Construtor da Classe \n Aqui fazemos a alocação dinâmica de memória para o nosso vetor ***v
 *  \param _nx -- Dimensão em x
 *  \param _ny -- Dimensão em y
 *  \param _nz -- Dimensão em z*/
  Sculptor(int _nx, int _ny, int _nz);
/** \brief Destrutor da Classe \n Aqui fazemos a liberação da memória do nosso vetor ***v */
  ~Sculptor();
/** \brief Atribuição de cor ao objeto desenhado
 *  \n As variáveis r,g,b e alpha recebem valores compreendidos em um intervalo de [0,1]. A variável r está relacionada a cor vermelha (red),
 * g está relacionada a cor verde (green) e b é a cor azul (blue). E por sua vez a variável alpha corresponde a transparência que o objeto terá. \n
 * A cada vez que o usuário quiser mudar a cor de um objeto, ele deverá chamar essa função. 
 *  \param r -- Cor vermelha 
 *  \param g -- Cor verde
 *  \param b -- Cor azul
 *  \param alpha -- Transparência */
  void setColor(float r, float g, float b, float alpha);
/** \brief Essa função é responsável por formar um voxel na posição x,y,z e fazendo isOn = true. \n Atribui a ele a cor atual definida na função setColor
*   \param x -- Ativação do voxel na posição x
*   \param y -- Ativação do voxel na posição y
*   \param z -- Ativação do voxel na posição z */
  void putVoxel(int x, int y, int z);
/** \brief Essa função é responsável por excluir um voxel na posição x,y,z e fazendo isOn = false.
*   \param x -- Desativa o voxel na posição x
*   \param y -- Desativa o voxel na posição y
*   \param z -- Desativa o voxel na posição z */  
  void cutVoxel(int x, int y, int z);
/** \brief Aqui a função grava a escultura no formato OFF no arquivo "filename".
*   \param *filename -- Nome que o seu arquivo OFF receberá */
  void writeOFF(char* filename);
  void limpaVoxels();
};


#ifdef __GNUC__
#include "Sculptor.cpp"
#endif // SCULPTOR_H_INCLUDED

#endif