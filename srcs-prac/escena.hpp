#ifndef ESCENA
#define ESCENA

#include "MallaInd.hpp"
#include "NodoGrafoEscena.hpp"
#include <matrizg.hpp> 
 
class Escena: public NodoGrafoEscena {
    public:
    Escena();
};

class Peon: public NodoGrafoEscena {
    protected:
    MallaInd * peon;
    public:
    Peon();
}; 

class Lata: public NodoGrafoEscena {
    MallaInd * lata;
    public: 
    Lata(); 
};
#endif