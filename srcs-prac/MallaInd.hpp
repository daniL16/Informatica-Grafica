#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include <vector>
#include <aux.hpp>
#include <file_ply_stl.hpp>

#ifndef MALLA_IND
#define MALLA_IND

// clase para mallas indexadas o mallas TVT
class MallaInd : public Objeto3D
{
   protected:
   	std::vector<Tupla3f> vertices;
   	std::vector<Tupla3i> caras;
   public:
      virtual void visualizar( unsigned mode );
      MallaInd();
} ;

#endif

#ifndef MALLAPLY
#define MALLAPLY

// clase mallas indexadas obtenidas de un archivo PLY
class MallaPLY : public MallaInd
{
   public:
      // constructor
      // se debe especificar el nombre completo del archivo a leer
      MallaPLY( const char * nombre_arch ) ; 
} ;

#endif

#ifndef MALLA_REVOL
#define MALLA_REVOL

// clase mallas indexadas obtenidas de un archivo PLY
class MallaRevol : public MallaInd
{
   public:
      // constructor
      // se debe especificar: el nombre completo del archivo a leer
      //                      el número de copias del perfil
      
      MallaRevol( const char * nombre_arch, unsigned nperfiles ) ; 
} ;

#endif


