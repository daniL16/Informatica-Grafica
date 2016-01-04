#include "NodoGrafoEscena.hpp"

EntradaNGE::EntradaNGE(Objeto3D * pObjeto ) { //(copia solo puntero)
    objeto = pObjeto;
    tipoE=0;
}

EntradaNGE::EntradaNGE (const Matriz4f & pMatriz ){ // (crea copia)
    matriz = new Matriz4f(pMatriz);
    tipoE=1;
}

EntradaNGE::EntradaNGE(Material * material ) { //(copia solo puntero)
    this->material = material;
    tipoE=2;
}

void NodoGrafoEscena::visualizar(unsigned cv ) {
    glMatrixMode(GL_MODELVIEW); // operaremos sobre la modelview
    glPushMatrix() ;// guarda modelview actual
    
    //recorrer todas las entradas del array que hay en el nodo:
    
    for(unsigned i = 0 ; i < entradas.size() ; i++ )
        if(entradas[i].tipoE== 0 )//si la entrada es sub-objeto:
            ((Objeto3D *)entradas[i].objeto)->visualizar( cv ) ; //visualizarlo
        else if (entradas[i].tipoE==1) //si la entrada es transformación:
            glMultMatrixf(*(entradas[i].matriz) );// componerla
        else 
            entradas[i].material->activar();
    
    glMatrixMode(GL_MODELVIEW);// operaremos sobre la modelview
    glPopMatrix();// restaura modelview guardada
    //RESTAURAR MATERIAL 
}

void NodoGrafoEscena::agregar(EntradaNGE * entrada){
    entradas.push_back(*entrada);
}

void NodoGrafoEscena::agregar(Objeto3D * pObjeto ){
    entradas.push_back(EntradaNGE (pObjeto));
}

void NodoGrafoEscena::agregar (const Matriz4f & pMatriz ){
    entradas.push_back(EntradaNGE (pMatriz));
}

  void NodoGrafoEscena::agregar( Material * material ){
     entradas.push_back(EntradaNGE(material));
  }
