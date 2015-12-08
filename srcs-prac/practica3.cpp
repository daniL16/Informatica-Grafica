#include "practica3.hpp"

int grados_libertad = 3 ;
//float alpha,beta,gamma = 0 ;
int p3_grado_libertad_activo ;
int p3_objeto_activo = 0;
int p3_num_objetos ;

static Objeto3D * obj_jerarquico ;

void P3_Inicializar( int argc, char *argv[] ){
    obj_jerarquico = new Runner();
}

void P3_DibujarObjetos( unsigned modo ){
    obj_jerarquico->visualizar(modo);
}

bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ) {
	switch(toupper(tecla)) {
		case '>' :
            switch(p3_grado_libertad_activo) {
                case 0 :
                    break;
                case 1 :
                    break;
                case 2 :
                    break;
            }
		case '<' :
			
		case 'G' :
            p3_grado_libertad_activo = (p3_grado_libertad_activo+1) % grados_libertad; 
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
