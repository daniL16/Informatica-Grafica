// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (declaraciones públicas)
// **
// *********************************************************************
#include "MallaInd.hpp"

#ifndef IG_PRACTICA1_HPP
#define IG_PRACTICA1_HPP

void P1_Inicializar( int argc, char *argv[] ) ;
bool P1_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P1_DibujarObjetos( unsigned modo ) ; 

#endif

class Cubo : public MallaInd {
	public:
		Cubo();
};

class Tetraedro : public MallaInd {
	public:
		Tetraedro();
};

class Cilindro: public MallaInd {
	public:
	   Cilindro(int n,int h); //n : numero de caras, h:altura
};

class Cono: public MallaInd {
	public:
	  Cono(int n,int h);
};

class Toro: public MallaInd {
	public:
	  Toro(int n,int R,int r); // R: radio toro, r: radio agujero
};
