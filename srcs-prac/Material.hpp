#include "jpg_imagen.hpp"
#include "aux.hpp"
#include "tuplasg.hpp"

#ifndef MATERIAL
#define MATERIAL

class Material      
{  
  public:   
   virtual void activar( ) = 0 ;
};

// ---------------------------------------------------------------------
// Imagen de textura   

class Textura
{  
  public:   
   GLuint        id_text ;    // identificador OpenGL de la textura
   jpg::Imagen * img ;        // puntero a imagen con los texels
   unsigned      mgct ;       // modo de gen. cc.tt. (0 = desactivado, 1 = objeto, 2 = camara)
   float         cs[4],ct[4]; // coeficientes para generación de coords. de textura
   
   void activar(  );          // activa textura en el cauce fijo de OpenGL
   Textura( const std::string & archivoJPG ) ; // crea un textura a partir de un archivo
} ;

// ---------------------------------------------------------------------
// Parámetros de un material estándar (Amb.+Diffuso+Phong)

class MaterialEstandar  : public Material          
{  
  public:   
   Textura * text ;        // puntero a la textura (NULL si no hay)
   Tupla4f   color[4] ;    // colores: 0=emisión, 1=ambiental, 2=difuso, 3=especular
   float     exponente ;   // exponente para la componente pseudo-especular
   
   virtual void activar(  );// activa material en el cauce fijo
                            //   si tiene textura: activa uso de la textura 'text'
                            //   si no tiene textura: desactiva uso de texturas 
} ;


class MaterialLata : public MaterialEstandar
{
  public:
    MaterialLata() ;
};

class MaterialTapasLata : public MaterialEstandar
{
  public:
    MaterialTapasLata() ;
};

class MaterialPeonMadera : public MaterialEstandar
{
  public:
    MaterialPeonMadera() ;
};

class MaterialPeonBlanco : public MaterialEstandar
{
  public:
    MaterialPeonBlanco() ;
};

class MaterialPeonNegro : public MaterialEstandar
{
  public:
    MaterialPeonNegro() ;
};

#endif