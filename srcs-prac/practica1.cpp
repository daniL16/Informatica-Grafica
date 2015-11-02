// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f 
#include "practica1.hpp"


 Cubo::Cubo() {
		nombre_obj = "cubo";

        vertices.push_back(Tupla3f(-1,-1,1));
        vertices.push_back(Tupla3f(1,-1,1 ));
		vertices.push_back(Tupla3f(1,1,1));
		vertices.push_back(Tupla3f(-1,1,1));
		
		vertices.push_back(Tupla3f(1,-1,-1));
		vertices.push_back(Tupla3f(1,1,-1));
        vertices.push_back(Tupla3f(-1,1,-1));
    	vertices.push_back(Tupla3f(-1,-1,-1));

	    caras.push_back(Tupla3i(0,1,2));
        caras.push_back(Tupla3i(0,2,3)); 

   		caras.push_back(Tupla3i(1,4,5));
   		caras.push_back(Tupla3i(1,5,2));
    		
        caras.push_back(Tupla3i(3,2,5));
   		caras.push_back(Tupla3i(3,5,6));
    		
        caras.push_back(Tupla3i(0,1,4));
   		caras.push_back(Tupla3i(0,4,7));

   		caras.push_back(Tupla3i(7,4,5));
   		caras.push_back(Tupla3i(7,5,6));

        caras.push_back(Tupla3i(0,7,6));
   		caras.push_back(Tupla3i(0,6,3));
}

Tetraedro::Tetraedro(){
		nombre_obj = "tetraedro";

		vertices.push_back(Tupla3f(1,-1,-1));
		vertices.push_back(Tupla3f(-1,1,-1));
		vertices.push_back(Tupla3f (-1,-1,1));
		vertices.push_back(Tupla3f (-1,-1,-1));
				
		caras.push_back(Tupla3i(0,1,3));
		caras.push_back(Tupla3i(0, 1, 2));
		caras.push_back(Tupla3i(1, 3, 2));
		caras.push_back(Tupla3i(3, 0, 2));
}

Cilindro::Cilindro(int n,int h){
       // CILINDRO APOYADO EN EL EJE Z=0 CON CENTRO EN EL ORIGEN    
      
      //tapas
      vertices.push_back(Tupla3f(0,0,0));
      for(int j=0; j<n ; j++){
         vertices.push_back(Tupla3f(cos((2*j*M_PI)/n),sin((2*j*M_PI)/n),0));
      }
      for(int k=1 ; k<n; k++)
	caras.push_back(Tupla3i(0,k,k+1));
      caras.push_back(Tupla3i(0,n,1));

      vertices.push_back(Tupla3f(0,0,h));
      for(int j=0; j<n ; j++){
         vertices.push_back(Tupla3f(cos((2*j*M_PI)/n),sin((2*j*M_PI)/n),h));
      }
      for(int k=1 ; k<n; k++)
	caras.push_back(Tupla3i(n+1,n+k+1,n+k+2));
      caras.push_back(Tupla3i(n+1,2*n+1,n+2));
  // lateral
      for(int i=1;i<n;i++){
	caras.push_back(Tupla3i(i,n+i+1,n+i+2));
	caras.push_back(Tupla3i(i,i+1,n+i+2));
      }
	caras.push_back(Tupla3i(n,n+2,2*n+1));
	caras.push_back(Tupla3i(n,1,2*n+1));
}

Cono::Cono(int n,int h){
	//base
	vertices.push_back(Tupla3f(0,0,0));
	for(int j=0; j<n ; j++){
         vertices.push_back(Tupla3f(cos((2*j*M_PI)/n),sin((2*j*M_PI)/n),0));
      	}
	for(int k=1 ; k<n; k++)
		caras.push_back(Tupla3i(0,k,k+1));
      	caras.push_back(Tupla3i(0,n,1));
	
	// punta
	vertices.push_back(Tupla3f(0,0,h));
	for (int i=1 ; i < n ; i++)
		caras.push_back(Tupla3i(i,i+1,n+1));
	caras.push_back(Tupla3i(n,1,n+1));
}

Toro::Toro(int n,int R,int r){
 /* Ecuaciones parametricas del toro
	x = cos t(R+rcos p)
	y = sen t(R+rcos p)
	z = rsen p
 */
	float x,y,z;
  for (int i=0; i<n ; i++){
	 for (int j=0; j<n ; j = j+2){
		x = (R+r*cos((2*j*M_PI)/n))*cos((2*i*M_PI)/n);
		y = (R+r*cos((2*j*M_PI)/n))*sin((2*i*M_PI)/n);
		z = r*sin((2*j*M_PI)/n);
  	vertices.push_back(Tupla3f(x,y,z));
	//std::cout << "Generado " << x<< "   " << y << "  " << z << std::endl; 
	}}
}	
unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....
unsigned n_obj = 5;
Cubo * cubo;
Tetraedro * tetra;
Cilindro * cilindro;
Cono * cono;
Toro * toro;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e 
// incializado OpenGL. 

void P1_Inicializar( int argc, char *argv[] ){
  cubo = new Cubo();
  tetra = new Tetraedro();
  cilindro = new Cilindro(100,2);
  cono = new Cono(100,2);
  toro = new Toro (4,1,2);
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
   case 4 :
	toro->visualizar(modo);
	break;
  }
}