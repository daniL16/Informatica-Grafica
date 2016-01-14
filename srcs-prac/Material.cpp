#include "Material.hpp"

void FuenteLuz::activar(int i ){
    glEnable(GL_LIGHT0+i);
    
    glLightfv(GL_LIGHT0+i,GL_AMBIENT,colores[0]);
    glLightfv(GL_LIGHT0+i,GL_DIFFUSE,colores[1]);
    glLightfv(GL_LIGHT0+i,GL_SPECULAR,colores[2]);
    
    //glLightfv(GL_LIGHT0+i,GL_POSITION, posf );
    //glLightfv(GL_LIGHT0+i,GL_POSITION, dirf )
    if(posvec == 0){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        
        glLoadIdentity();
        //glMultMatrix();// ??
        glRotatef(longi,0.0,1.0,0.0);
        glRotatef(lati,-1.0,0.0,0.0);
        
        glPopMatrix();
    }
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
    glGenTextures( 1, &id_text);
    
    //img = new jpg::Imagen(archivoJPG);
    //img = img->leerPixels();

}

void Textura::activar(){
    glEnable(GL_TEXTURE_2D); 
    glBindTexture(GL_TEXTURE_2D,id_text);
}

void MaterialEstandar::activar(){
    if (text != NULL){
        text->activar();
    }
    else
        glDisable(GL_TEXTURE_2D); 

}

MaterialLata::MaterialLata(){
    text = new Textura("../imgs/lata-coke.jpg");
    //lata_sup->setColor(0.184314, 0.309804, 0.309804, 1.0);
}

MaterialPeonMadera::MaterialPeonMadera(){
    text = new Textura("text-madera.jpg");
}