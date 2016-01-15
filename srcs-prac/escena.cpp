#include "escena.hpp"

Escena::Escena(){
    //agregar(new MaterialLata());
    //agregar(new Lata());
    agregar(MAT_Traslacion(0.0,0.0,1.0));
    agregar(new MaterialPeonMadera());
    agregar(new Peon());
    agregar(MAT_Traslacion(3.0,0.0,0.0));
    agregar(new MaterialPeonNegro());
    agregar(new Peon());
    agregar(MAT_Traslacion(3.0,0.0,0.0));
    agregar(new MaterialPeonBlanco());
    agregar(new Peon());
     
}

Peon::Peon(){
    peon = new MallaRevol("../plys/peon.ply",25);
    agregar(peon);
}

Lata::Lata(){
    
    agregar(new MallaRevol("../plys/lata-psup.ply",25));
    agregar(new MallaRevol("../plys/lata-pinf.ply",25));
    agregar(new MallaRevol("../plys/lata-pcue.ply",25));
}