#include "MallaInd.hpp"

MallaInd::MallaInd(){
	nombre_obj=" ";
}

void MallaInd::visualizar( unsigned mode ){
                 if (mode == 3){

		    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		    for (unsigned i = 0 ; i < caras.size() ; i++) {
	               if (i %2 == 0)
                         glColor3f(1,0,0);
                       else
                         glColor3f(0,0,0);

                       glEnableClientState(GL_VERTEX_ARRAY);
		       glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
		       glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,&caras[i]);
		       glDisableClientState(GL_VERTEX_ARRAY);				
		     }
		    }

		    else {
		      switch(mode){
			case 0 :
			  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			  break;
			case 1 :
			  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			  break;
			case 2:
			  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			  break;
			}
	
         		glColor3f(1,0.3,0);
    			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT,0, &vertices[0]);
			glDrawElements(GL_TRIANGLES,3*(caras.size()),GL_UNSIGNED_INT,&caras[0]);
			glDisableClientState(GL_VERTEX_ARRAY);
		     }
 }

MallaPLY::MallaPLY( const char * nombre_arch ){
	std::vector<float> vertices_ply;
	std::vector<int> caras_ply;
	ply::read(nombre_arch,vertices_ply, caras_ply);
	int n = vertices_ply.size();
	int c = caras_ply.size();
	for(int i = 0 ; i <= n-3 ; i = i+3)
		vertices.push_back(Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]));
	for(int i = 0 ; i <= c-3 ; i = i+3)
		caras.push_back(Tupla3i(caras_ply[i],caras_ply[i+1],caras_ply[i+2]));
}

MallaRevol::MallaRevol(const char * nombre_arch, unsigned nperfiles ){
	
	std::vector<float> vertices_ply;
	
	ply::read_vertices (nombre_arch,vertices_ply);
	
	int tam = vertices_ply.size();
	int n = tam/3;
	double alfa;

	//vertices del perfil dado
	for(int i = 0 ; i <= tam-3 ; i = i+3)
		vertices.push_back(Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]));	

		

	// generamos los vertices y las caras
	for (unsigned int k = 1 ; k < nperfiles ; k++){
		alfa = (k*2*M_PI)/nperfiles;       
		for(int i = 0 ; i < n ; i++)
			vertices.push_back(Tupla3f(vertices[i](0)*cos(alfa)+vertices[i](2)*sin(alfa),
					   	   vertices[i](1),
					   	   vertices[i](2)*cos(alfa)-vertices[i](0)*sin(alfa)));
		
	
		for (int i = (k-1)*n ; i < k*n-1 ; i++){
			caras.push_back(Tupla3i(i+1,i+n+1,i));	
			caras.push_back(Tupla3i(i,i+n+1,i+n));	
		}
	}
	
 	
	// unimos el ultimo con el primero
	for (int i = 0 ; i < n-1 ; i++) {
		caras.push_back(Tupla3i((nperfiles-1)*n+i,i+1,i));
		caras.push_back(Tupla3i((nperfiles-1)*n+i,i+1,(nperfiles-1)*n+i+1));
	}

	//tapas
	vertices.push_back(Tupla3f(0,vertices_ply[1],0));
	vertices.push_back(Tupla3f(0,vertices_ply[tam-2],0));
	
	for (unsigned int i = 1 ; i < nperfiles ; i++){
			caras.push_back(Tupla3i((i-1)*n,i*n,n*nperfiles));
			caras.push_back(Tupla3i(i*n-1,(i+1)*n-1,n*nperfiles+1));			
	}

	caras.push_back(Tupla3i((nperfiles-1)*n,0,n*nperfiles));
	caras.push_back(Tupla3i(nperfiles*n-1,n-1,n*nperfiles+1));
}


