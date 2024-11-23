#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"
#include  "model/modelo.h"
#include  "controller/mouse.h"
#include  "controller/entradaTeclado.h"
#include  "view/renderer.h"
#include  "utils/color.h"
#include  "controller/controller.h"

controller::Controller* controller::Controller::currentInstance = nullptr;

int main(int argc, char *argv[])
{
	// Inicializa glu y openGL
	glutInit(&argc, argv);

	// Initialization
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1000);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Simulator");

	// Interaction functions
	glutKeyboardFunc(letra);
	glutSpecialFunc(especial);
	glutMouseFunc(clickRaton);
	glutMotionFunc(RatonMovido);

	controller::Controller controller;

	// Renderer functions
	glutReshapeFunc(view::initializeWindow);
	glutDisplayFunc(controller::Draw);


	// Idle function
	glutTimerFunc(30, controller::Update, 0);

	// Start the simulator
	controller::InitSimulator();

	// Inicializa parametros de openGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Lanza el gestor de eventos de glut
	glutMainLoop();


	return 0;
}
