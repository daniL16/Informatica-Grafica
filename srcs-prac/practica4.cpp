#include "practica4.hpp"

int angulo_actual = 0;
int alpha,beta;
//Textura coca_cola;
//Textura madera;

static NodoGrafoEscena ** p4_obj_jerarquico ;
Escena * p4_escena;

void P4_Inicializar( int argc, char *argv[] ){
    //cargar texturas y crear materiales
    p4_escena = new Escena();
    p4_obj_jerarquico = new NodoGrafoEscena * [1]{p4_escena};
}

void P4_DibujarObjetos( unsigned modo ){
    p4_obj_jerarquico[0]->visualizar(modo);
}

bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ) {
	switch(toupper(tecla)) {
		/*case '>' :
            switch(angulo_actual) {
                case 0 :
                    escena->AumentarAlpha();
                    break;
                case 1 :
                    escena->AumentarBeta();
                    break;
            }
            break;
        case '<' :
            switch(angulo_actual) {
                case 0 :
                    escena->DisminuirAlpha();
                    break;
                case 1 :
                    escena->DisminuirBeta();
                    break;
            }
	        break;*/
		case 'G' :
            angulo_actual = (angulo_actual+1)%2;
			break;
		default :
			return false;
	}
    return true;
}
