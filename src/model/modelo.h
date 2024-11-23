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