#include "Material.hpp"

FuenteLuz::FuenteLuz( Tupla4f vec, Tupla4f ambiental, Tupla4f difuso, Tupla4f especular,int w){
    
    colores[0] = ambiental;
    colores[1] = difuso;
    colores[2] = especular;
    this->w = w;
    longi = 0;
    lati = 0;

    posvec = vec;
}

FuenteLuz::FuenteLuz( Tupla4f vec,int w){
    this->w = w;
    longi = 0;
    lati = 0;

    posvec = vec;
}

void FuenteLuz::modificar_direccion( float alpha, float beta ){
    longi  = longi+alpha;
    lati  = lati+beta;
}

void FuenteLuz::activar(int i ){
    glEnable(GL_LIGHT0+i); 
    if( w )
         glLightfv(GL_LIGHT0+i,GL_POSITION,posvec);
    else {
        Tupla4f ejeZ(cosf(longi)*sinf(lati),sinf(longi)*sinf(lati),cosf(lati),0.0);
        glLightfv( GL_LIGHT0+i, GL_POSITION, ejeZ );
    }

    glLightfv(GL_LIGHT0+i,GL_AMBIENT,colores[0]);
    glLightfv(GL_LIGHT0+i,GL_DIFFUSE,colores[1]);
    glLightfv(GL_LIGHT0+i,GL_SPECULAR,colores[2]);
}

void ColeccionFL::activar(){
    int n = fuentes.size();
    for (int i=0; i < 8 ; i++){
        if (i < n) 
        fuentes[i]->activar(i);
        else
        glDisable(GL_LIGHT0+i);
    }
}

Textura::Textura( const std::string & archivoJPG ){
    glEnable( GL_TEXTURE_2D );
    
    img = new jpg::Imagen(archivoJPG);
    
    glGenTextures( 1, &id_text);
    glBindTexture( GL_TEXTURE_2D, this->id_text );
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
    
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB,img->tamX(), img->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, img->leerPixels());
    
  glBindTexture(GL_TEXTURE_2D, 0); 
  glDisable( GL_TEXTURE_2D ); 
}

void Textura::activar(){
    
    glEnable(GL_TEXTURE_2D); 
    glBindTexture(GL_TEXTURE_2D,id_text);
    
    switch(mgct){
        case 0:
        glDisable( GL_TEXTURE_GEN_S );
        glDisable( GL_TEXTURE_GEN_T );
        break;
        case 1:
            glEnable(GL_TEXTURE_GEN_S);
            glEnable(GL_TEXTURE_GEN_T);
            glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
        glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
            glTexGenfv( GL_S, GL_OBJECT_PLANE, cs );
            glTexGenfv( GL_T, GL_OBJECT_PLANE, ct );
            break;
        case 2:
            glEnable(GL_TEXTURE_GEN_S);
            glEnable(GL_TEXTURE_GEN_T);
            glTexGenfv( GL_S, GL_EYE_PLANE, cs );
            glTexGenfv( GL_T, GL_EYE_PLANE, ct );
            break;
                
    }
}

void MaterialEstandar::activar(){
    
    glEnable(GL_LIGHTING);

    glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, color[0] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color[1] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, color[2] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color[3] );

    glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, &(this->exponente) ) ;
    
    if (text != NULL)
        text->activar();
    
    else
        glDisable(GL_TEXTURE_2D); 

}

MaterialLata::MaterialLata(){
    text = new Textura("../imgs/lata-coke.jpg");
    color[0] = Tupla4f(0.3, 0.3, 0.3, 1.0);
    color[1] = Tupla4f(0.05, 0.05, 0.05, 1.0);
    color[2] = Tupla4f(0.7, 0.7, 0.7, 1.0);
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 6.0;
}

MaterialTapasLata::MaterialTapasLata(){
   color[0] = Tupla4f(0.3, 0.3, 0.3, 1.0);
    color[1] = Tupla4f(0.05, 0.05, 0.05, 1.0);
    color[2] = Tupla4f(0.7, 0.7, 0.7, 1.0);
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 6.0;  
}

MaterialPeonMadera::MaterialPeonMadera(){
    text = new Textura("../imgs/text-madera.jpg");
    color[0] = Tupla4f(0.3, 0.3, 0.3, 1.0);
    color[1] = Tupla4f(0.05, 0.05, 0.05, 1.0);
    color[2] = Tupla4f(0.7, 0.7, 0.7, 1.0);
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 6.0;
}

MaterialPeonBlanco::MaterialPeonBlanco(){
  color[0] = Tupla4f(0.6, 0.6, 0.6, 1.0);
    color[1] = Tupla4f(0.05, 0.05, 0.05, 1.0);
    color[2] = Tupla4f(0.5, 0.5, 0.5, 1.0);
    color[3] = Tupla4f(0.0, 0.0, 0.0, 0.0);
    exponente = 6.0;  
}

MaterialPeonNegro::MaterialPeonNegro(){
   color[0] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[1] = Tupla4f(0.02, 0.02, 0.02, 1.0);
    color[2] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 3.0; 
}
