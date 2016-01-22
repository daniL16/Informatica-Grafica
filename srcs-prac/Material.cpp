#include "Material.hpp"

Textura::Textura( const std::string & archivoJPG ){
    glEnable( GL_TEXTURE_2D );
    
    img = new jpg::Imagen(archivoJPG);
}

void Textura::activar(){
    
    glEnable(GL_TEXTURE_2D); 
    
}

void MaterialEstandar::activar(){
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color[3]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]);
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente ) ;
    
    if (text != NULL){
        // Carga la imagen
        glTexImage2D(GL_TEXTURE_2D, 0, 3, text->img->tamX(), text->img->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, text->img->leerPixels());
        
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        
        text->activar();
        glDisable(GL_COLOR_MATERIAL);
    }
    else{
        glDisable(GL_TEXTURE_2D);
    }
}

MaterialLata::MaterialLata(){
    text = new Textura("../imgs/lata-coke.jpg");
    color[0] = Tupla4f(0.5, 0.5, 0.5, 1.0);
    color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[2] = Tupla4f(0.2, 0.2, 0.2, 1.0);
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 30;
}

MaterialTapasLata::MaterialTapasLata(){
    text = NULL;
    color[0] = Tupla4f(0.2, 0.2, 0.2, 1.0);
    color[1] = Tupla4f(0.2, 0.2, 0.2, 1.0);
    color[2] = Tupla4f(0.5, 0.5, 0.5, 1.0);
    color[3] = Tupla4f(0.5, 0.5, 0.5, 1.0);
    exponente = 6.0;  
}

MaterialPeonMadera::MaterialPeonMadera(){
    text = new Textura("../imgs/text-madera.jpg");
    color[0] = Tupla4f(0.5, 0.5, 0.5, 1.0);
    color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[2] = Tupla4f(0.2, 0.2, 0.2, 1.0);
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 6.0;
}

MaterialPeonBlanco::MaterialPeonBlanco(){
  color[0] = Tupla4f(0.9, 0.9, 0.9, 1.0);
    color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[2] = Tupla4f(0.5, 0.5, 0.5, 1.0);
    color[3] = Tupla4f(0, 0, 0, 1.0);
    exponente = 6.0;  
}

MaterialPeonNegro::MaterialPeonNegro(){
   color[0] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[1] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[2] = Tupla4f(0.0, 0.0, 0.0, 1.0);
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 3.0; 
}
