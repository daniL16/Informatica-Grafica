// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica1.hpp"


unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....
unsigned n_obj = 4;
Cubo * cubo;
Tetraedro * tetra;
Cilindro * cilindro;
Cono * cono;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P1_Inicializar( int argc, char *argv[] ){
  cubo = new Cubo();
  tetra = new Tetraedro();
  cilindro = new Cilindro(100);
  cono = new Cono(100,2);
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar 
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
   if (tecla != 'o')
     return false ;
   else{
      objeto_activo = (objeto_activo+1)% n_obj;

      return true ;
   }
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P1_DibujarObjetos( unsigned modo ) {
  
     if (modo > 3)
        modo = 2;
    
    switch(objeto_activo){
        case 0 :
            tetra->visualizar(modo);
            break;
        case 1 :
            cubo->visualizar(modo);    
            break;
        case 2 :
	       cilindro->visualizar(modo);
	       break;
        case 3 :
	       cono->visualizar(modo);
	       break;
    }
    
}
