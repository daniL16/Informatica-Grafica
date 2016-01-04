#include "MallaInd.hpp"

void MallaInd::calcularNormales(){
    int k = caras.size();
    Tupla3f p,q,r,a,b,m,n;
    Tupla3i cara_actual;
    
    for (int i = 0 ; i < k ; i++){
        cara_actual = caras[i];
        p = vertices[cara_actual(0)];
        q =  vertices[cara_actual(1)];
        r =  vertices[cara_actual(2)];
        a = q - p;
        b = r - p;
        m = a.cross(b);
        n = m.normalized();
        normales_c.push_back(n);
        

        normales_v[cara_actual(0)] = normales_v[cara_actual(0)] + n;
        normales_v[cara_actual(1)] = normales_v[cara_actual(1)] + n;
        normales_v[cara_actual(2)] = normales_v[cara_actual(2)] + n;
    }
    for (int i = 0 ; i < normales_v.size() ; i++){
        normales_v[i] = normales_v[i].normalized();
    }
}

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

MallaRevol::MallaRevol(const char * nombre_arch, unsigned nperfiles,bool texturas){
	
	std::vector<float> vertices_ply;
	
	ply::read_vertices (nombre_arch,vertices_ply);
	
	int tam = vertices_ply.size();
	int n = tam/3;
	double alfa;

	//vertices del perfil dado
	for(int i = 0 ; i <= tam-3 ; i = i+3)
		vertices.push_back(Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]));	

		

	// generamos los vertices y las caras
	for (unsigned  k = 1 ; k < nperfiles ; k++){
		alfa = (k*2*M_PI)/nperfiles;       
		for(int i = 0 ; i < n ; i++)
			vertices.push_back(Tupla3f(vertices[i](0)*cos(alfa)+vertices[i](2)*sin(alfa),
					   	   vertices[i](1),
					   	   vertices[i](2)*cos(alfa)-vertices[i](0)*sin(alfa)));
		
	
		for (unsigned i = (k-1)*n ; i < k*n-1 ; i++){
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

Cubo::Cubo() {
		nombre_obj = "cubo";

        vertices.push_back(Tupla3f(-1,-1,1));
        vertices.push_back(Tupla3f(1,-1,1 ));
		vertices.push_back(Tupla3f(1,1,1));
		vertices.push_back(Tupla3f(-1,1,1));
		
		vertices.push_back(Tupla3f(1,-1,-1));
		vertices.push_back(Tupla3f(1,1,-1));
        vertices.push_back(Tupla3f(-1,1,-1));
    	vertices.push_back(Tupla3f(-1,-1,-1));

	    caras.push_back(Tupla3i(0,1,2));
        caras.push_back(Tupla3i(0,2,3)); 

   		caras.push_back(Tupla3i(1,4,5));
   		caras.push_back(Tupla3i(1,5,2));
    		
        caras.push_back(Tupla3i(3,2,5));
   		caras.push_back(Tupla3i(3,5,6));
    		
        caras.push_back(Tupla3i(0,1,4));
   		caras.push_back(Tupla3i(0,4,7));

   		caras.push_back(Tupla3i(7,4,5));
   		caras.push_back(Tupla3i(7,5,6));

        caras.push_back(Tupla3i(0,7,6));
   		caras.push_back(Tupla3i(0,6,3));
}

Tetraedro::Tetraedro(){
		nombre_obj = "tetraedro";

		vertices.push_back(Tupla3f(1,-1,-1));
		vertices.push_back(Tupla3f(-1,1,-1));
		vertices.push_back(Tupla3f (-1,-1,1));
		vertices.push_back(Tupla3f (-1,-1,-1));
				
		caras.push_back(Tupla3i(0,1,3));
		caras.push_back(Tupla3i(0, 1, 2));
		caras.push_back(Tupla3i(1, 3, 2));
		caras.push_back(Tupla3i(3, 0, 2));
}

Cilindro::Cilindro(int n){
       // CILINDRO APOYADO EN EL EJE Z=0 CON CENTRO EN EL ORIGEN    
      
      //tapas
      vertices.push_back(Tupla3f(0,-1,0));
      for(int j=0; j<n ; j++){
         vertices.push_back(Tupla3f(cos((2*j*M_PI)/n),-1,sin((2*j*M_PI)/n)));
      }
      for(int k=1 ; k<n; k++)
	caras.push_back(Tupla3i(0,k,k+1));
      caras.push_back(Tupla3i(0,n,1));

      vertices.push_back(Tupla3f(0,1,0));
      for(int j=0; j<n ; j++){
         vertices.push_back(Tupla3f(cos((2*j*M_PI)/n),1,sin((2*j*M_PI)/n)));
      }
      for(int k=1 ; k<n; k++)
	caras.push_back(Tupla3i(n+1,n+k+1,n+k+2));
      caras.push_back(Tupla3i(n+1,2*n+1,n+2));
  // lateral
      for(int i=1;i<n;i++){
	caras.push_back(Tupla3i(i,n+i+1,n+i+2));
	caras.push_back(Tupla3i(i,i+1,n+i+2));
      }
	caras.push_back(Tupla3i(n,n+2,2*n+1));
	caras.push_back(Tupla3i(n,1,2*n+1));
}

Cono::Cono(int n,int h){
	//base
	vertices.push_back(Tupla3f(0,0,0));
	for(int j=0; j<n ; j++){
         vertices.push_back(Tupla3f(cos((2*j*M_PI)/n),sin((2*j*M_PI)/n),0));
      	}
	for(int k=1 ; k<n; k++)
		caras.push_back(Tupla3i(0,k,k+1));
      	caras.push_back(Tupla3i(0,n,1));
	
	// punta
	vertices.push_back(Tupla3f(0,0,h));
	for (int i=1 ; i < n ; i++)
		caras.push_back(Tupla3i(i,i+1,n+1));
	caras.push_back(Tupla3i(n,1,n+1));
}



