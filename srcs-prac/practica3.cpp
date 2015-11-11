#include "practica3.hpp"

int grados_libertad = 3 ;
int p3_grado_libertad_activo ;
int p3_objeto_activo = 0;
int p3_num_objetos ;
//static * obj_jerarquico = NULL ;

void P3_Inicializar( int argc, char *argv[] ){

}

void P3_DibujarObjetos( unsigned modo ){

}

bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ) {
	switch(toupper(tecla)) {
		case '>' :
			if (p3_grado_libertad_activo < grados_libertad-1 )
				p3_grado_libertad_activo++;	
			break;
		case '<' :
			if (p3_grado_libertad_activo > 0 )
				p3_grado_libertad_activo--;	
			break;
		case 'G' :
			break;
		case 'O' :
			p3_objeto_activo = (p3_objeto_activo+1)% p3_num_objetos;
			break;
		default :
			return false;
	}
	std::cout << "grado de libertad actual : " << p3_grado_libertad_activo << std::endl;
	return true;
}
