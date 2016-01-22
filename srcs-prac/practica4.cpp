#include "practica4.hpp"

int angulo_actual = 0;
float alpha = 0,beta = 0;


ColeccionFL * fuentes_luz = NULL;
static FuenteLuz *luz_posicional;
FuenteDireccional * luz_direccional;
static NodoGrafoEscena ** p4_obj_jerarquico ;
Escena * p4_escena;

void P4_Inicializar( int argc, char *argv[] ){
    fuentes_luz = new ColeccionFL();
    
    glEnable(GL_RESCALE_NORMAL);
    
    p4_escena = new Escena();
    p4_obj_jerarquico = new NodoGrafoEscena * [1]{p4_escena};
    
    luz_direccional = new FuenteDireccional(0,0); 
    luz_posicional  = new FuentePosicional(Tupla3f( 0.0, 6.0, 0.0));
    
    fuentes_luz->fuentes.push_back(luz_posicional);
    fuentes_luz->fuentes.push_back(luz_direccional);
    
    fuentes_luz->activar();
    
    glEnable( GL_LIGHTING );
    glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE );
    glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR ) ;
    glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );
    glDisable( GL_LIGHTING );
}

void P4_DibujarObjetos( unsigned modo ){
    
    
    if (modo >= 4){
            fuentes_luz->activar();
            ContextoVis cv ;
            cv.modo_vis = modo;
            cv.materialActivo = 0;
            p4_obj_jerarquico[0]->visualizar(cv);
            fuentes_luz->desactivar();
    }
    
    else {
        p4_obj_jerarquico[0]->visualizar(modo);
    }
}
   
bool P4_FGE_PulsarTeclaNormal(  unsigned char tecla ) {
	switch(toupper(tecla)) {
		case '>' :
            luz_direccional->variarAngulo( angulo_actual, +0.5 ) ;
            break;
        case '<' :
            luz_direccional->variarAngulo( angulo_actual, -0.5 ) ;
	        break;
		case 'G' :
            angulo_actual = (angulo_actual+1)%2;
			break;
		default :
			return false;
	}
    return true;
}
