#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <fstream>
#include "utils/utils.h"
#include "utils/vector3.h"


class Objeto3D
{
public:
	virtual void draw() = 0; // Dibuja el objeto
};

class Ejes : Objeto3D
{
public:
	float longitud = 30;
	// Dibuja el objeto
	void draw()
	{
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);
		{
			glColor3f(0, 1, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, longitud, 0);

			glColor3f(1, 0, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(longitud, 0, 0);

			glColor3f(0, 0, 1);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, longitud);
		}
		glEnd();
		glEnable(GL_LIGHTING);
	}
};

class Cubo : Objeto3D
{
private:
	float lado;

public:
	Cubo(float l = 1) : lado(l) {};

	void update()
	{
		lado += 0.01;
	}
	void draw()
	{

		glBegin(GL_QUADS);
		{
			// X POSITIVO
			//   auto aux = NormalDadosVertices(lado, 0, lado, lado, 0, 0, lado, lado, lado);
			auto aux = utils::triangleNormal(utils::Vector3(lado, 0, lado), 
											utils::Vector3(lado, 0, 0), 
											utils::Vector3(lado, lado, 0));
			glNormal3f(aux.x, aux.y, aux.z);
			// glNormal3f(1,0,0);
			glVertex3f(lado, 0, 0);
			glVertex3f(lado, lado, 0);
			glVertex3f(lado, lado, lado);
			glVertex3f(lado, 0, lado);

			// Y POSITIVO
			glNormal3f(0, 1, 0);
			glVertex3f(0, lado, 0);
			glVertex3f(0, lado, lado);
			glVertex3f(lado, lado, lado);
			glVertex3f(lado, lado, 0);

			// Z POSITIVO
			glNormal3f(0, 0, 1);
			glVertex3f(0, 0, lado);
			glVertex3f(lado, 0, lado);
			glVertex3f(lado, lado, lado);
			glVertex3f(0, lado, lado);

			// X 0
			glNormal3f(-1, 0, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, lado);
			glVertex3f(0, lado, lado);
			glVertex3f(0, lado, 0);

			// Y 0
			glNormal3f(0, -1, 0);
			glVertex3f(0, 0, 0);
			glVertex3f(lado, 0, 0);
			glVertex3f(lado, 0, lado);
			glVertex3f(0, 0, lado);

			// Z 0
			glNormal3f(0, 0, -1);
			glVertex3f(0, 0, 0);
			glVertex3f(0, lado, 0);
			glVertex3f(lado, lado, 0);
			glVertex3f(lado, 0, 0);
		}
		glEnd();
	};
};

class Tetrahedro : Objeto3D
{
private:
	float lado;
};

class Esfera : Objeto3D
{
private:
	float radio;
	int muestras;
};

class Octahedro : Objeto3D
{
private:
	float lado;

public:
	Octahedro(float l = 1) : lado(l) {};
};

#endif