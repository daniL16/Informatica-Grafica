#include "practica4.hpp"

int angulo_actual = 0;
int alpha,beta;

ColeccionFL fuentes_luz;
static FuenteLuz *luz_direccional,*luz_posicional;
static NodoGrafoEscena ** p4_obj_jerarquico ;
Escena * p4_escena;

void P4_Inicializar( int argc, char *argv[] ){
    p4_escena = new Escena();
    p4_obj_jerarquico = new NodoGrafoEscena * [1]{p4_escena};
    
    luz_direccional = new FuenteLuz(Tupla4f(0.0, 0.0, 0.0, 0.0),0);
    luz_posicional  = new FuenteLuz(Tupla4f(0.0, 6.0, 0.0, 1.0),Tupla4f(0.2, 0.2, 0.7, 1.0),                   
                                    Tupla4f(0.2, 0.2, 0.7, 1.0),Tupla4f(0.2, 0.2, 0.7, 1.0),1);
    
    fuentes_luz.fuentes.push_back(luz_posicional);
    fuentes_luz.fuentes.push_back(luz_direccional);
    
    glEnable( GL_LIGHTING );
    glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE );
    glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR ) ;
    glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );
}

void P4_DibujarObjetos( unsigned modo ){
    glEnable( GL_LIGHTING );
    glEnable( GL_NORMALIZE );
    glDisable( GL_COLOR_MATERIAL );
    
    fuentes_luz.activar();
    
    ContextoVis cv ;
    cv.modo_vis = 4;
    cv.materialActivo = NULL;
    p4_obj_jerarquico[0]->visualizar(cv);
    
    //luz_direccional->desactivar();
    //luz_posicional->desactivar();

    glDisable( GL_LIGHTING );
    glDisable( GL_NORMALIZE );
    glEnable( GL_COLOR_MATERIAL );    

}

bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ) {
	switch(toupper(tecla)) {
		case '>' :
            switch(angulo_actual) {
                case 0 :
                    luz_direccional->modificar_direccion(0.1,0);;
                    break;
                case 1 :
                    luz_direccional->modificar_direccion(0,0.1);
                    break;
            }
            break;
        case '<' :
            switch(angulo_actual) {
                case 0 :
                    luz_direccional->modificar_direccion(-0.1,0);
                    break;
                case 1 :
                    luz_direccional->modificar_direccion(0,-0.1);
                    break;
            }
	        break;
		case 'G' :
            angulo_actual = (angulo_actual+1)%2;
			break;
		default :
			return false;
	}
    return true;
}
