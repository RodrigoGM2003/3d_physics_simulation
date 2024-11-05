#include <GL/gl.h>

#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"
#include "controller/controller.h"


controller::Controller::Controller() {
    currentInstance = this;  // Store the current instance
}



void controller::Controller::draw() {
    view::renderScene();
}

void controller::Controller::update() {

    // Update the scene
    // simulator.update();
    glutPostRedisplay();
	glutTimerFunc(30, controller::Update, 0); 
}

controller::Controller* controller::Controller::getInstance() {
    return currentInstance;
}


void controller::Draw() {
    Controller::getInstance()->draw();
}

void controller::Update(int dt) {
    Controller::getInstance()->update();
}