#include "luz.hpp"

FuenteLuz::FuenteLuz(){
    
}

void FuenteLuz::modificar_direccion( float alpha, float beta ){
    longi  = longi+alpha;
    lati  = lati+beta;
}

void FuenteLuz::activar(int i ){
    glLightfv(GL_LIGHT0+i,GL_AMBIENT,colores[0]);
    glLightfv(GL_LIGHT0+i,GL_DIFFUSE,colores[1]);
    glLightfv(GL_LIGHT0+i,GL_SPECULAR,colores[2]);
    glEnable(GL_LIGHT0+i); 
    if( posvec[3] )
         glLightfv(GL_LIGHT0+i,GL_POSITION,posvec);
    else {
        Tupla4f ejeZ(cosf(longi)*sinf(lati),sinf(longi)*sinf(lati),cosf(lati),0.0);
        glLightfv( GL_LIGHT0+i, GL_POSITION, ejeZ );
    }
}

void FuenteLuz::desactivar( int i ) {
    glDisable(GL_LIGHT0+i);
}

void ColeccionFL::activar(){
    int n = fuentes.size();
    glEnable(GL_DEPTH_TEST);   //Activa el buffer de profundidad.
    glEnable(GL_LIGHTING);     //Activa la iluminacion
    for (int i=0; i < n ; i++){
         fuentes[i]->activar(i);
    }
}

void ColeccionFL::desactivar() {
    glDisable(GL_DEPTH_TEST);   //Activa el buffer de profundidad.
    glDisable(GL_LIGHTING);     //Activa la iluminacion
    for(int i=0; i<fuentes.size(); i++){
        fuentes[i]->desactivar(i);
    }
}

FuenteDireccional::FuenteDireccional( float alpha_inicial, float beta_inicial ){
    // posición (si w=1) o vector (w=0)
    posvec = Tupla4f(alpha_inicial, 0, beta_inicial, 0); //en este caso w=0
    // colores[]: 0=ambiental, 1=difuso, 2=especular.
    colores[0] = Tupla4f(0.6 ,0.6 ,0.6 , 1.0);
    colores[1] = Tupla4f(0, 0, 0.0 , 1.0);
    colores[2] = Tupla4f(0.3, 0.3, 0.3 , 1.0);
}

void FuenteDireccional::variarAngulo( unsigned angulo, float incremento ){
    if(angulo == 0)
        posvec = posvec+Tupla4f(incremento,0,0,0);
    else
        posvec = posvec+Tupla4f(0,0,incremento,0);
    std::cout << posvec << std::endl;
}

//Constructor de una fuente posicional
FuentePosicional::FuentePosicional( const Tupla3f & posicion ){
    // posición (si w=1) o vector (w=0)
    posvec = Tupla4f(posicion[0], posicion[1], posicion[2], 1); //en este caso w=1
    // colores[]: 0=ambiental, 1=difuso, 2=especular.
    colores[0] = Tupla4f(0.6 ,0.6 ,0.6 , 1.0);
    colores[1] = Tupla4f(0, 0, 0.0 , 1.0);
    colores[2] = Tupla4f(0.3, 0.3, 0.3 , 1.0);
}

