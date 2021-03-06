#include "practica2.hpp"

int num_objetos = 2 ;
unsigned p2_objeto_activo = 0 ; // 0: objeto ply, 1: objeto revolucion
static MallaInd * obj_ply = 0;
static MallaInd * obj_rev = 0;
int nperfiles = 50;



void P2_Inicializar(int argc, char *argv[]){
	switch (argc){	
		case 2:
			obj_ply = new MallaPLY(argv[1]);
			obj_rev = new MallaRevol ("../plys/peon.ply",nperfiles,false);
			break;
		case 3:
			obj_ply = new MallaPLY(argv[1]);
			obj_rev = new MallaRevol (argv[2],nperfiles,false);
			break;
		default :
			obj_ply = new MallaPLY("../plys/beethoven.ply");
			obj_rev = new MallaRevol ("../plys/peon.ply",nperfiles,false);
			break;
	}
}

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla ) 
{
   if (tecla != 'o')
     return false ;
   else{
      p2_objeto_activo = (p2_objeto_activo+1)% num_objetos;
      return true ;
   }
}


void P2_DibujarObjetos( unsigned modo ) {
  
    if (modo > 3)
        modo = 2;
    
    switch(p2_objeto_activo){
    case 0:
	obj_ply->visualizar(modo);
	break;
    case 1:
	obj_rev->visualizar(modo);
	break;
  }
}
