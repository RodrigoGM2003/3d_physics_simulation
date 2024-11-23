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