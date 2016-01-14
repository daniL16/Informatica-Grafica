#include "practica3.hpp"

int grados_libertad = 3 ;
int p3_grado_libertad_activo = 0;
int p3_objeto_activo = 0;
int p3_num_objetos = 1 ;

static NodoGrafoEscena ** obj_jerarquico ;
Dibujo * escena;

void P3_Inicializar( int argc, char *argv[] ){
    escena = new Dibujo();
    obj_jerarquico = new NodoGrafoEscena * [1]{escena};
}

void P3_DibujarObjetos( unsigned modo ){
    ContextoVis cv;
    cv.modo_vis= modo;
    obj_jerarquico[p3_objeto_activo]->visualizar(cv);
}

bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ) {
	switch(toupper(tecla)) {
		case '>' :
            switch(p3_grado_libertad_activo) {
                case 0 :
                    escena->AumentarAlpha();
                    break;
                case 1 :
                    escena->AumentarBeta();
                    break;
                case 2 :
                    escena->AumentarGamma();
                    break;
            }
            break;
        case '<' :
            switch(p3_grado_libertad_activo) {
                case 0 :
                    escena->DisminuirAlpha();
                    break;
                case 1 :
                    escena->DisminuirBeta();
                    break;
                case 2 :
                    escena->DisminuirGamma();
                    break;
            }
	        break;
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
