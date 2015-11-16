Pilar::Pilar(){
agregar (MAT_Escalado()) ; // estirar el cubo hacia arriba
agregar (MAT_Traslacion ()) ; // mover a la izda.
agregar (new Cubo);
}

Pluma::Pluma(){
agregar (MAT_Traslacion ()) ; //levantar
agregar (MAT_Escalado()) ; // estirar el cubo hacia la izqda
agregar (new Cubo);
}

Peso::Peso(){
agregar (MAT_Traslacion ()) ; // colocar
agregar (new Cubo);
}
