#include "practica4.hpp"

int angulo_actual = 0;
int alpha,beta; //???
/*
int grados_libertad = 3 ;
int p3_grado_libertad_activo = 0;
int p3_objeto_activo = 0;
int p3_num_objetos = 1 ;

static NodoGrafoEscena ** obj_jerarquico ;
Dibujo * escena;
*/
//parametros materialers
void P4_Inicializar( int argc, char *argv[] ){
    //cargar texturas y crear materiales
    //escena = new Dibujo();
    //obj_jerarquico = new NodoGrafoEscena * [1]{escena};
}

void P4_DibujarObjetos( unsigned modo ){
    //obj_jerarquico[p3_objeto_activo]->visualizar(modo);
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
