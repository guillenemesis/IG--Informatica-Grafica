//**************************************************************************
// Práctica 2 usando objetos
//**************************************************************************

#include "objetos.h"
#include "file_ply_stl.h"
#include <iostream>


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{

}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
	glColor3f(r,g,b);
	glPointSize(grosor);
	glBegin(GL_POINTS);
	for(int i=0; i<vertices.size(); i++){
		glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
	}
	glEnd();
	


}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
	int v1,v2,v3;

	glColor3f(r,g,b);
	glLineWidth(grosor);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	for(int i=0; i<caras.size(); i++){
		v1=caras[i]._0;
		v2=caras[i]._1;
		v3=caras[i]._2;

		glVertex3f(vertices[v1].x, vertices[v1].y, vertices[v1].z);
		glVertex3f(vertices[v2].x, vertices[v2].y, vertices[v2].z);
		glVertex3f(vertices[v3].x, vertices[v3].y, vertices[v3].z);
	}
	glEnd( );
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
	int v1,v2,v3;

	glColor3f(r,g,b);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	for(int i=0; i<caras.size(); i++){
		v1=caras[i]._0;
		v2=caras[i]._1;
		v3=caras[i]._2;

		glVertex3f(vertices[v1].x, vertices[v1].y, vertices[v1].z);
		glVertex3f(vertices[v2].x, vertices[v2].y, vertices[v2].z);
		glVertex3f(vertices[v3].x, vertices[v3].y, vertices[v3].z);
	}
	glEnd( );
 
}

//*************************************************************************
// dibujar en modo sólido con iluminacion y sombreado plano
//*************************************************************************

void _triangulos3D::draw_solido_sombreado_plano(float r, float g, float b)
{
	int v1,v2,v3;
	bool conTextura = false;

	if(texturas.size() > 0) conTextura = true;

	glColor3f(r,g,b);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_FLAT);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	if(!conTextura){
		glBegin(GL_TRIANGLES);
		for(int i=0; i<caras.size(); i++){
			v1=caras[i]._0;
			v2=caras[i]._1;
			v3=caras[i]._2;

			glNormal3f(normalesCaras[i].x, normalesCaras[i].y, normalesCaras[i].z);
			glVertex3f(vertices[v1].x, vertices[v1].y, vertices[v1].z);
			glVertex3f(vertices[v2].x, vertices[v2].y, vertices[v2].z);
			glVertex3f(vertices[v3].x, vertices[v3].y, vertices[v3].z);
		}
		glEnd( );
	}else{
		glBegin(GL_TRIANGLES);
		for(int i=0; i<caras.size(); i++){
			v1=caras[i]._0;
			v2=caras[i]._1;
			v3=caras[i]._2;

			glNormal3f(normalesCaras[i].x, normalesCaras[i].y, normalesCaras[i].z);
			glTexCoord2f(texturas[v1].x, texturas[v1].y);
			glVertex3f(vertices[v1].x, vertices[v1].y, vertices[v1].z);
			glTexCoord2f(texturas[v2].x, texturas[v2].y);
			glVertex3f(vertices[v2].x, vertices[v2].y, vertices[v2].z);
			glTexCoord2f(texturas[v3].x, texturas[v3].y);
			glVertex3f(vertices[v3].x, vertices[v3].y, vertices[v3].z);
		}
		glEnd( );
	}
 
}

//*************************************************************************
// dibujar en modo sólido con iluminacion y sombreado suave
//*************************************************************************

void _triangulos3D::draw_solido_sombreado_suave(float r, float g, float b)
{
	int v1,v2,v3;
	bool conTextura = false;

	if(texturas.size() > 0) conTextura = true;

	glColor3f(r,g,b);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	if(!conTextura){
		glBegin(GL_TRIANGLES);
		for(int i=0; i<caras.size(); i++){
			v1=caras[i]._0;
			v2=caras[i]._1;
			v3=caras[i]._2;

			glNormal3f(normalesVertices[v1].x, normalesVertices[v1].y, normalesVertices[v1].z);
			glVertex3f(vertices[v1].x, vertices[v1].y, vertices[v1].z);
			glNormal3f(normalesVertices[v2].x, normalesVertices[v2].y, normalesVertices[v2].z);
			glVertex3f(vertices[v2].x, vertices[v2].y, vertices[v2].z);
			glNormal3f(normalesVertices[v3].x, normalesVertices[v3].y, normalesVertices[v3].z);
			glVertex3f(vertices[v3].x, vertices[v3].y, vertices[v3].z);
		}
		glEnd( );
	}else{
		glBegin(GL_TRIANGLES);
		for(int i=0; i<caras.size(); i++){
			v1=caras[i]._0;
			v2=caras[i]._1;
			v3=caras[i]._2;

			glNormal3f(normalesVertices[v1].x, normalesVertices[v1].y, normalesVertices[v1].z);
			glTexCoord2f(texturas[v1].x, texturas[v1].y);
			glVertex3f(vertices[v1].x, vertices[v1].y, vertices[v1].z);

			glNormal3f(normalesVertices[v2].x, normalesVertices[v2].y, normalesVertices[v2].z);
			glTexCoord2f(texturas[v2].x, texturas[v2].y);
			glVertex3f(vertices[v2].x, vertices[v2].y, vertices[v2].z);

			glNormal3f(normalesVertices[v3].x, normalesVertices[v3].y, normalesVertices[v3].z);
			glTexCoord2f(texturas[v3].x, texturas[v3].y);
			glVertex3f(vertices[v3].x, vertices[v3].y, vertices[v3].z);
		}
		glEnd( );
	}
 
}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
	int v1,v2,v3;

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	for(int i=0; i<caras.size(); i++){
		v1=caras[i]._0;
		v2=caras[i]._1;
		v3=caras[i]._2;
		
		if(i%2==0) 
			glColor3f(r1,g1,b1);
		else
			glColor3f(r2,g2,b2);
		

		glVertex3f(vertices[v1].x, vertices[v1].y, vertices[v1].z);
		glVertex3f(vertices[v2].x, vertices[v2].y, vertices[v2].z);
		glVertex3f(vertices[v3].x, vertices[v3].y, vertices[v3].z);
	}
	glEnd( );
}
//*************************************************************************
// calcular normales por caras y por vertices
//*************************************************************************

void _triangulos3D::calcularNormalesCaras(){
	_vertex3f productoVectorial;
	_vertex3f vector1;
	_vertex3f vector2;
	int v1,v2,v3;

	for(int i=0; i<caras.size(); i++){
		v1=caras[i]._0;
		v2=caras[i]._1;
		v3=caras[i]._2;

		vector1.x = vertices[v2].x - vertices[v1].x;
		vector1.y = vertices[v2].y - vertices[v1].y;
		vector1.z = vertices[v2].z - vertices[v1].z;

		vector2.x = vertices[v3].x - vertices[v1].x;
		vector2.y = vertices[v3].y - vertices[v1].y;
		vector2.z = vertices[v3].z - vertices[v1].z;

		productoVectorial = vector1.cross_product(vector2);
		productoVectorial.normalize();

		normalesCaras.push_back(_vertex3f(productoVectorial.x, productoVectorial.y, productoVectorial.z));			
	}
}

//--------------------------------------------------------------------------

void _triangulos3D::calcularNormalesVertices(){
	int v1,v2,v3;

	for(int i=0; i<vertices.size(); i++){
		normalesVertices.push_back(_vertex3f(0.0, 0.0, 0.0));
	}

	for(int i=0; i<caras.size(); i++){
		v1=caras[i]._0;
		v2=caras[i]._1;
		v3=caras[i]._2;

		normalesVertices[v1] += normalesCaras[i];
		normalesVertices[v2] += normalesCaras[i];
		normalesVertices[v3] += normalesCaras[i];
	}
	for(int i=0; i<vertices.size(); i++){
		normalesVertices[i].normalize();
	}
}


//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
// Vertices
	vertices.push_back(_vertex3f(-tam, -tam, tam));
	vertices.push_back(_vertex3f(tam, -tam, tam));
	vertices.push_back(_vertex3f(tam, tam, tam));
	vertices.push_back(_vertex3f(-tam, tam, tam));

        vertices.push_back(_vertex3f(tam, tam, -tam));
    	vertices.push_back(_vertex3f(-tam, tam, -tam));
    	vertices.push_back(_vertex3f(-tam, -tam, -tam));
    	vertices.push_back(_vertex3f(tam, -tam, -tam));

	// Caras
   	caras.push_back(_vertex3i(0, 1, 2));
    	caras.push_back(_vertex3i(2, 3, 0));
	caras.push_back(_vertex3i(1, 7, 2));
	caras.push_back(_vertex3i(7, 4, 2));    
	caras.push_back(_vertex3i(4, 5, 2));
	caras.push_back(_vertex3i(5, 3, 2));
	caras.push_back(_vertex3i(0, 3, 5));
	caras.push_back(_vertex3i(5, 6, 0));
	caras.push_back(_vertex3i(6, 7, 1));
	caras.push_back(_vertex3i(1, 0, 6));
	caras.push_back(_vertex3i(6, 5, 4));
	caras.push_back(_vertex3i(4, 7, 6));	
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{
	// Vertices
	vertices.push_back(_vertex3f(-tam,-tam, tam));
	vertices.push_back(_vertex3f(tam,-tam, tam));
	vertices.push_back(_vertex3f(tam, tam, tam));
	vertices.push_back(_vertex3f(-tam, tam, tam));
	vertices.push_back(_vertex3f(0,	0, 2*al)); 

	// Caras
	caras.push_back(_vertex3i(1, 0, 3));
	caras.push_back(_vertex3i(1, 3, 2));
	caras.push_back(_vertex3i(0, 1, 4));
	caras.push_back(_vertex3i(0, 4, 3));
	caras.push_back(_vertex3i(3, 4, 2));
	caras.push_back(_vertex3i(1, 2, 4));
}

//*************************************************************************
// clase tetraedro
//*************************************************************************

_tetraedro::_tetraedro(float tam)
{
	// Vertices
	vertices.push_back(_vertex3f(0, 0, 0));
	vertices.push_back(_vertex3f(0,tam, 0));
	vertices.push_back(_vertex3f((tam*sqrt(3))/2, tam/2, 0));
	vertices.push_back(_vertex3f((tam*sqrt(3))/6, tam/2, (tam*sqrt(6))/3));

	// Caras
	caras.push_back(_vertex3i(0, 2, 3));
	caras.push_back(_vertex3i(1, 3, 2));
	caras.push_back(_vertex3i(1, 0, 3));
	caras.push_back(_vertex3i(0, 1, 2));
}

//*************************************************************************
// clase modeloPLY
//*************************************************************************

/* Constructor que toma los vertices del archivo .ply para crear el modelo */
_modeloPLY::_modeloPLY(float tam, char * fileName)
{
	float x, y, z;	
	_file_ply aux;

	aux.open(fileName); 
	aux.read(puntos, faces);
	aux.close();

	//vertices
	for(int i=0; i<puntos.size(); i+=3){
		x=puntos[i];
		y=puntos[i+1];
		z=puntos[i+2];

		vertices.push_back(_vertex3f(x*tam, y*tam, z*tam));

	}
}

//---------------------------------------------------------------------------------------------------------------

/* Añadir las caras del archivo .ply a la estructura de datos del modelo */
void _modeloPLY::usarCarasArchivoPLY(){
	int v1, v2, v3;

	//caras
	for(int i=0; i<faces.size(); i+=3){
		v1=faces[i];
		v2=faces[i+1];
		v3=faces[i+2];

		caras.push_back(_vertex3i(v1, v2, v3));
	}

}

//---------------------------------------------------------------------------------------------------------------

/* Crear solido de revolucion con un perfil sobre eje y */
void _modeloPLY::crearObjetoRevolucion(int n){
	float x, y, z,angulo;
	float anguloGiro=(2.0*M_PI)/n;
	int veces=1, i;
	int verticesPerfil=puntos.size()/3;

	//creacion de perfiles de vertices rotados
	while(veces<=n-1 && n>1){
		angulo=anguloGiro*veces;

		for(int i=0; i<verticesPerfil; i++){
			x=vertices[i].x;
			y=vertices[i].y;
			z=vertices[i].z;
	
			vertices.push_back(_vertex3f(x*cos(angulo) + z*sin(angulo), y, -x*sin(angulo) + z*cos(angulo)));
		}
		veces++;
	}

	//caras entre perfiles consecutivos menos la union del ultimo y primer perfil
	for(i=0; i<vertices.size()-verticesPerfil; i++){
		if((i+1)%verticesPerfil!=0){
			caras.push_back(_vertex3i(i, i+verticesPerfil+1, i+1)); 
			caras.push_back(_vertex3i(i+verticesPerfil+1,i, i+verticesPerfil)); 
		}
	}
	
	//caras entre el ultimo perfil y el primero
	for(int j=0; j<verticesPerfil-1; i++, j++){
		caras.push_back(_vertex3i(i, j+1, i+1));
		caras.push_back(_vertex3i(j+1, i, j));
	}

	//creacion de vertices centrales de las tapas
	vertices.push_back(_vertex3f(0, vertices[0].y, 0));
	vertices.push_back(_vertex3f(0, vertices[verticesPerfil-1].y, 0));

	//caras de las tapas 
	for(i=0; i<vertices.size()-3-verticesPerfil; i+=verticesPerfil){
		caras.push_back(_vertex3i(i, vertices.size()-2 , i+verticesPerfil ));
		caras.push_back(_vertex3i(i+verticesPerfil-1, i + 2*verticesPerfil - 1 , vertices.size()-1 ));
	}
	//cara del ultimo vertice con el primero de las tapas
	caras.push_back(_vertex3i(i, vertices.size()-2, 0 ));
	caras.push_back(_vertex3i(i+verticesPerfil-1, 0 + verticesPerfil - 1 , vertices.size()-1 ));

}
//---------------------------------------------------------------------------------------------------------------

/* solido de revolucion con TEXTURAS */
void _modeloPLY::crearObjetoRevolucionConTexturas(int n){
	float x, y, z,angulo;
	float anguloGiro=(2.0*M_PI)/n;
	int veces=1, i;
	int verticesPerfil=puntos.size()/3;

	//creacion de perfiles de vertices rotados
	while(veces<=n-1 && n>1){
		angulo=anguloGiro*veces;

		for(int i=0; i<verticesPerfil; i++){
			x=vertices[i].x;
			y=vertices[i].y;
			z=vertices[i].z;
	
			vertices.push_back(_vertex3f(x*cos(angulo) + z*sin(angulo), y, -x*sin(angulo) + z*cos(angulo)));
		}
		veces++;
	}

	//caras entre perfiles consecutivos menos la union del ultimo y primer perfil
	for(i=0; i<vertices.size()-verticesPerfil; i++){
		if((i+1)%verticesPerfil!=0){
			caras.push_back(_vertex3i(i, i+verticesPerfil+1, i+1)); 
			caras.push_back(_vertex3i(i+verticesPerfil+1,i, i+verticesPerfil)); 
		}
	}
	
	//caras entre el ultimo perfil y el primero
	for(int j=0; j<verticesPerfil-1; i++, j++){
		caras.push_back(_vertex3i(i, j+1, i+1));
		caras.push_back(_vertex3i(j+1, i, j));
	}

	//calcular las coordenadas de textura (s,t) para cada vertice de cada perfil

	double d[verticesPerfil];	//vector de distancias de cada punto al inicial de su perfil
    	d[0] = 0;
	
	for(int i=1; i<verticesPerfil; i++){
		double x = pow((vertices[i].x-vertices[i-1].x), 2);
    		double y = pow((vertices[i].y-vertices[i-1].y), 2);
    		double z = pow((vertices[i].z-vertices[i-1].z), 2);

    		double result = sqrt((double)(x+y+z));
	
		d[i] = d[i-1] + result;
	}
	for(int i=0; i<=n+1; i++){
        	float si = (float)i/(n);
        	for(int j=0; j<verticesPerfil; j++){
            	float tj = d[j]/d[verticesPerfil-1];

            	texturas.push_back(_vertex2f(si, tj));

       		}
    	}

	//creacion de vertices centrales de las tapas
	vertices.push_back(_vertex3f(0, vertices[0].y, 0));
	vertices.push_back(_vertex3f(0, vertices[verticesPerfil-1].y, 0));

	//caras de las tapas 
	for(i=0; i<vertices.size()-3-verticesPerfil; i+=verticesPerfil){
		caras.push_back(_vertex3i(i, vertices.size()-2 , i+verticesPerfil ));
		caras.push_back(_vertex3i(i+verticesPerfil-1, i + 2*verticesPerfil - 1 , vertices.size()-1 ));
	}
	//cara del ultimo vertice con el primero de las tapas
	caras.push_back(_vertex3i(i, vertices.size()-2, 0 ));
	caras.push_back(_vertex3i(i+verticesPerfil-1, 0 + verticesPerfil - 1 , vertices.size()-1 ));

}
//---------------------------------------------------------------------------------------------------------------

/* Crear solido por barrido con un poligono segun vector pasado por parametro reescalado por parametro size */
void _modeloPLY::crearObjetoBarrido(float Vx, float Vy, float Vz, float size){
	int verticesPLY=vertices.size();
	int i;
	float centroX, centroY, centroZ;

	//creamos los vertices trasladados
	for(int i=0; i<verticesPLY; i++){
		vertices.push_back(_vertex3f(vertices[i].x + Vx*size, vertices[i].y + Vy*size, vertices[i].z + Vz*size));
	}

	//calculo de punto central del poligono inicial
	centroX=0; centroY=0; centroZ=0;

	for(int i=0; i<verticesPLY; i++){
		centroX += vertices[i].x;
		centroY += vertices[i].y;
		centroZ += vertices[i].z;
	}
	vertices.push_back(_vertex3f(centroX/verticesPLY, centroY/verticesPLY, centroZ/verticesPLY));

	//calculo de punto central del poligono trasladado
	centroX=0; centroY=0; centroZ=0;

	for(int i=verticesPLY; i<vertices.size()-1; i++){
		centroX += vertices[i].x;
		centroY += vertices[i].y;
		centroZ += vertices[i].z;
	}
	vertices.push_back(_vertex3f(centroX/verticesPLY, centroY/verticesPLY, centroZ/verticesPLY));

	//caras laterales hechas con los vertices iniciales menos el ultimo, la union con el inicial se hace aparte
	for(i=0; i<verticesPLY-1; i++){
		caras.push_back(_vertex3i(i, i+verticesPLY+1, i+verticesPLY));
		caras.push_back(_vertex3i(i+verticesPLY+1, i, i+1));
	}

	//caras laterales de la union
	caras.push_back(_vertex3i(i, i+1, i+verticesPLY));
	caras.push_back(_vertex3i(i+1, i, 0));

	//caras de la tapa 1
	for(i=0; i<verticesPLY-1; i++){
		caras.push_back(_vertex3i(i, vertices.size()-2, i+1 ));
	}
	caras.push_back(_vertex3i(i, vertices.size()-2, 0 ));

	//caras de la tapa 2
	for(i=verticesPLY; i<vertices.size()-3; i++){
		caras.push_back(_vertex3i(i+1, vertices.size()-1, i ));
	}
	caras.push_back(_vertex3i(i-verticesPLY+1, vertices.size()-1, i ));
}

//*************************************************************************
// clase modeloJerarquico
//*************************************************************************

void _modeloJerarquico::drawModeloJerarquico(int tamTorre, int tamPluma, float movCarro, float movCable, int angulo){
	float tamCubo=0.5;
	float escalaCarro=0.15;
	float escalaCable=0.15;
	float escalaCaja=0.3;
	_cubo cubo1(tamCubo);
	_piramide piramide1(tamCubo);
	_modeloPLY prisma1(1.0, "triangulo.ply");
	prisma1.crearObjetoBarrido(0.0, 0.0, 1.0, 1.0);

	//base----------------------------------
	glPushMatrix();		
	glScalef(2.0,0.2,2.0);
	glTranslatef(0.0,tamCubo,0.0);
	cubo1.draw_solido_ajedrez(0.0, 1.0, 0.0, 0.0, 0.6, 0.0);
	cubo1.draw_aristas(0.0, 0.0, 0.0, 2);
	glPopMatrix();

	//torre----------------------------------
	glPushMatrix();
	glTranslatef(0.0,tamCubo*2*0.2,0.0);
	glTranslatef(0.0,tamCubo,0.0);		
	cubo1.draw_aristas(0.0, 0.0, 0.0, 2);

	for(int i=0; i<tamTorre-1; i++){
		glTranslatef(0.0,tamCubo*2,0.0);
		cubo1.draw_aristas(0.0, 0.0, 0.0, 2);
	}
	glPopMatrix();

	glRotatef(angulo,0,1,0); //giro de la pluma
	//piramide------------------------------
	glPushMatrix();	
	glTranslatef(0.0,(tamCubo*2*tamTorre)+1-tamCubo,0.0);
	glTranslatef(0.0,tamCubo*2*0.2,0.0);
	glRotatef(-90,1,0,0);
	piramide1.draw_aristas(0.0, 0.0, 0.0, 2);
	glPopMatrix();

	//pluma----------------------------------
	glPushMatrix();
	glTranslatef(0.0,tamCubo*2*tamTorre,0.0);
	glTranslatef(0.0,tamCubo*2*0.2,0.0);
	glTranslatef(0.0,tamCubo,0.0);	
	cubo1.draw_aristas(0.0, 0.0, 0.0, 2);
	glPushMatrix();
	glTranslatef(-tamCubo*2,0.0,0.0);
	cubo1.draw_aristas(0.0, 0.0, 0.0, 2);
	glTranslatef(-tamCubo,0.0,0.0);
	glTranslatef(0.0,-tamCubo,0.0);
	glTranslatef(0.0,0.0,tamCubo);
	glRotatef(180,0,1,0);
	prisma1.draw_aristas(0.0, 0.0, 0.0, 2);
	glPopMatrix();

	for(int i=0; i<tamPluma-1; i++){
		glTranslatef(tamCubo*2,0.0,0.0);
		cubo1.draw_aristas(0.0, 0.0, 0.0, 2);
	}
	glTranslatef(tamCubo,0.0,0.0);
	glTranslatef(0.0,-tamCubo,0.0);
	glTranslatef(0.0,0.0,-tamCubo);
	prisma1.draw_aristas(0.0, 0.0, 0.0, 2);
	glPopMatrix();

	glTranslatef(movCarro,0.0,0.0);  //movimiento del carro

	//carro----------------------------------
	glPushMatrix();
	glTranslatef(0.0,tamCubo*2*tamTorre,0.0);
	glTranslatef(0.0,tamCubo*2*0.2,0.0);
	glTranslatef(0.0,-tamCubo*escalaCarro,0.0);
	glTranslatef(2*tamCubo,0.0,0.0);
	glScalef(1.0,escalaCarro,1.0);
	cubo1.draw_aristas(0.0, 0.0, 0.0, 2);
	cubo1.draw_solido(0.0, 1.0, 0.0);
	glPopMatrix();		


	glTranslatef(2*tamCubo,tamTorre + tamCubo*2*0.2*escalaCarro,0.0);

	//cable----------------------------------
	glPushMatrix();
	glTranslatef(0.0,-movCable/2,0.0);
	glScalef(escalaCable,-movCable,escalaCable); //extender cable
	cubo1.draw_solido( 0.0, 0.5, 0.0);
	glPopMatrix();

	//caja-----------------------------------
	glTranslatef(0.0,-movCable,0.0);	//bajar la caja con el cable
	glPushMatrix();
	glTranslatef(0.0,-tamCubo*escalaCaja,0.0);  
	glScalef(escalaCaja,escalaCaja,escalaCaja); 
	cubo1.draw_aristas(0.0, 0.0, 0.0, 2);
	cubo1.draw_solido( 0.0, 0.5, 0.9);
	glPopMatrix();

}
//*************************************************************************
// clase luz
//*************************************************************************
void _luz::activarLuzAmbiente(){
	GLfloat vectorLuz[] = {valores[0], valores[1], valores[2], valores[3]};

	switch (nombre){
		case 0: //GL_LIGHT0
			glLightfv(GL_LIGHT0, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			break;
		case 1: //GL_LIGHT1
			glLightfv(GL_LIGHT1, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
			break;
		case 2: //GL_LIGHT2
			glLightfv(GL_LIGHT2, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT2);
			break;
		case 3: //GL_LIGHT3
			glLightfv(GL_LIGHT3, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT3);
			break;
		case 4: //GL_LIGHT4
			glLightfv(GL_LIGHT4, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT4);
			break;
		case 5: //GL_LIGHT5
			glLightfv(GL_LIGHT5, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT5);
			break;
		case 6: //GL_LIGHT6
			glLightfv(GL_LIGHT6, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT6);
			break;
		case 7: //GL_LIGHT7
			glLightfv(GL_LIGHT7, GL_AMBIENT, vectorLuz);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT7);
			break;
	}
}

//--------------------------------------------------------------------------------------------

void _luz::posicion(float x, float y, float z, float w){
	pos.push_back(x); pos.push_back(y); pos.push_back(z); pos.push_back(w);

	GLfloat vectorLuz[] = {x, y, z, w};

	switch (nombre){
		case 0: //GL_LIGHT0
			glLightfv(GL_LIGHT0, GL_POSITION, vectorLuz);
			break;
		case 1: //GL_LIGHT1
			glLightfv(GL_LIGHT1, GL_POSITION, vectorLuz);
			break;
		case 2: //GL_LIGHT2
			glLightfv(GL_LIGHT2, GL_POSITION, vectorLuz);
			break;
		case 3: //GL_LIGHT3
			glLightfv(GL_LIGHT3, GL_POSITION, vectorLuz);
			break;
		case 4: //GL_LIGHT4
			glLightfv(GL_LIGHT4, GL_POSITION, vectorLuz);
			break;
		case 5: //GL_LIGHT5
			glLightfv(GL_LIGHT5, GL_POSITION, vectorLuz);
			break;
		case 6: //GL_LIGHT6
			glLightfv(GL_LIGHT6, GL_POSITION, vectorLuz);
			break;
		case 7: //GL_LIGHT7
			glLightfv(GL_LIGHT7, GL_POSITION, vectorLuz);
			break;
	}
}

//--------------------------------------------------------------------------------------------

void _luz::mover(int alfa, int beta){
	float x = 100*cos(beta)*sin(alfa);
	float y = 100*sin(beta);
	float z = 100*cos(beta)*cos(alfa);

	GLfloat vectorLuz[] = {x, y, z, pos[3]};

	switch (nombre){
		case 0: //GL_LIGHT0
			glLightfv(GL_LIGHT0, GL_POSITION, vectorLuz);
			break;
		case 1: //GL_LIGHT1
			glLightfv(GL_LIGHT1, GL_POSITION, vectorLuz);
			break;
		case 2: //GL_LIGHT2
			glLightfv(GL_LIGHT2, GL_POSITION, vectorLuz);
			break;
		case 3: //GL_LIGHT3
			glLightfv(GL_LIGHT3, GL_POSITION, vectorLuz);
			break;
		case 4: //GL_LIGHT4
			glLightfv(GL_LIGHT4, GL_POSITION, vectorLuz);
			break;
		case 5: //GL_LIGHT5
			glLightfv(GL_LIGHT5, GL_POSITION, vectorLuz);
			break;
		case 6: //GL_LIGHT6
			glLightfv(GL_LIGHT6, GL_POSITION, vectorLuz);
			break;
		case 7: //GL_LIGHT7
			glLightfv(GL_LIGHT7, GL_POSITION, vectorLuz);
			break;
	}
}

//--------------------------------------------------------------------------------------------

void _luz::desactivarLuzAmbiente(){
	switch (nombre){
		case 0: //GL_LIGHT0
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			break;
		case 1: //GL_LIGHT1
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT1);
			break;
		case 2: //GL_LIGHT2
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT2);
			break;
		case 3: //GL_LIGHT3
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT3);
			break;
		case 4: //GL_LIGHT4
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT4);
			break;
		case 5: //GL_LIGHT5
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT5);
			break;
		case 6: //GL_LIGHT6
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT6);
			break;
		case 7: //GL_LIGHT7
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT7);
			break;
	}
}
//*************************************************************************
// clase textura
//*************************************************************************
void _textura::activar(){
	if (pimg != NULL){
        glTexImage2D(GL_TEXTURE_2D, 0, 3, pimg->tamX(), pimg->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, pimg->leerPixels());

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

        glEnable(GL_TEXTURE_2D);
        glDisable(GL_COLOR_MATERIAL);
    }
    else{
        glEnable(GL_COLOR_MATERIAL);
        glDisable(GL_TEXTURE_2D);
    }
}

//--------------------------------------------------------------------------------------------

void _textura::activarProcedural(){

	static GLfloat plano_s[4]={1.0, 0.0, 0.0, 0.0}, plano_t[4]={0.0, 1.0, 0.0, 0.0};	

	if (pimg != NULL){
        glTexImage2D(GL_TEXTURE_2D, 0, 3, pimg->tamX(), pimg->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, pimg->leerPixels());

        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

        glEnable(GL_TEXTURE_2D);
        glDisable(GL_COLOR_MATERIAL);

	glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
	glTexGenfv(GL_S,GL_OBJECT_PLANE,plano_s);
	glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
	glTexGenfv(GL_T,GL_OBJECT_PLANE,plano_t);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
    }
    else{
        glEnable(GL_COLOR_MATERIAL);
        glDisable(GL_TEXTURE_2D);
    }
}

//--------------------------------------------------------------------------------------------

void _textura::desactivar(){
	if (pimg != NULL)
		glDisable(GL_COLOR_MATERIAL);
		
    	else{
        	glDisable(GL_TEXTURE_2D);
    	}
}

//--------------------------------------------------------------------------------------------

void _textura::desactivarProcedural(){
	if (pimg != NULL){
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_COLOR_MATERIAL);
    	}else{
        	glDisable(GL_TEXTURE_2D);
    	}
}

//--------------------------------------------------------------------------------------------

void _textura::perla(){
	GLfloat mat_difuso1[]={0.25,0.20725,0.20725,0.922},
	mat_difuso2[]={1.0,0.829,0.829,0.922},
	mat_especular2[]={0.296648,0.296648,0.296648,0.922},
	mat_brillo2=11.264;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,mat_difuso1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mat_difuso2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,mat_especular2);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,mat_brillo2);
}

//--------------------------------------------------------------------------------------------

void _textura::plasticoNegro(){
	GLfloat mat_difuso1[]={0.0,0.0,0.0,1.0},
	mat_difuso2[]={0.01,0.01,0.01,1.0},
	mat_especular2[]={0.5,0.5,0.5,1.0},
	mat_brillo2=32;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,mat_difuso1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mat_difuso2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,mat_especular2);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS,mat_brillo2);
}
