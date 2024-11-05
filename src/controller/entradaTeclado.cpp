#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h" // Libreria de utilidades de OpenGL
#include "controller/entradaTeclado.h"
#include "controller/mouse.h"
#include "model/modelo.h"
#include "view/renderer.h"


float rotxCamara = 30, rotyCamara = 45;
float dCamara = 10;

/**
 * @brief Funcion de captura de eventos pulsacion de tecla correspondiente a caracter alfanumerico
 * @param k codigo ascii del caracter
 * @param x posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @param y posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @return void
 * 
 * Esta funcion es llamada por el sistema cuando se pulsa una tecla normal
 */
void letra(unsigned char k, int x, int y)
{

	switch (k)
	{
	case '+': // acerca la cámara
		dCamara -= 5.0;
		break;
	case '-': // aleja la cámara
		dCamara += 5.0;
		break;

	case 'p':
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;
	case 'l':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 'f':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;

	case 27: // Escape  Terminar
		exit(0);
	default:
		return;
	}
	view::setCamera(rotxCamara, rotyCamara, dCamara);

} 

/**
 * @brief Funcion de captura de eventos pulsacion de caracteres especiales y de control
 * @param k codigo ascii del caracter
 * @param x posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @param y posicion del cursor en coordenadas de pantalla cuando se pulso la tecla
 * @return void
 * 
 * Esta funcion es llamada por el sistema cuando se pulsa una tecla especial
 */
void especial(int k, int x, int y)
{

	switch (k)
	{
	case GLUT_KEY_UP:
		rotxCamara += 5.0; // Cursor arriba + rotacion x
		if (rotxCamara > 360)
			rotxCamara -= 360;
		break;
	case GLUT_KEY_DOWN:
		rotxCamara -= 5.0;
		if (rotxCamara < 0)
			rotxCamara += 360;
		break;
	case GLUT_KEY_LEFT:
		rotyCamara += 5.0;
		if (rotyCamara > 360)
			rotyCamara -= 360;
		break;
	case GLUT_KEY_RIGHT:
		rotyCamara -= 5.0;
		if (rotyCamara < 0)
			rotyCamara += 360;
		break;
	case GLUT_KEY_PAGE_DOWN: // acerca la cámara
		dCamara -= 5.0;
		break;
	case GLUT_KEY_PAGE_UP: // aleja la cámara
		dCamara += 5.0;
		break;
	default:
		return;
	}
	view::setCamera(rotxCamara, rotyCamara, dCamara);
}
