#include <GL/gl.h>
#include <math.h>

#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"
#include "view/renderer.h"
#include "model/bodies/body.h"
#include "utils/color.h"
#include "model/modelo.h"
#include "model/drawers/prismDrawer.h"
#include "utils/vector3.h"
#include "utils/quaternion.h"

namespace view{
    Ejes ejes = Ejes();
    // model::Body bod = model::Body(utils::Vector3(2, 2, 2));
    model::PrismDrawer body = model::PrismDrawer();
    utils::Quaternion q = utils::Quaternion(1, 0, 0, 0);
    utils::Vector3 p = utils::Vector3(0, 0, 0);

    float view_rotx = 30, view_roty = 45;
    float D = 10;
    float windowWidth, windowHeight;
}

void view::viewTransform() {
    // Moves the camera
	glTranslatef(0, 0, -view::D);

    // Rotates the camera
	glRotatef(view::view_rotx, 1.0, 0.0, 0.0);
	glRotatef(view::view_roty, 0.0, 1.0, 0.0);
}

void view::setCamera(float ax, float ay, float d) {
    // Rotates and moves the camera
    view::view_rotx = ax;
	view::view_roty = ay;

	D = d;
}

void view::setProjection(float fovY) {
    // Sets the projection matrix
    float aspectRatio = view::windowWidth > 0 ? static_cast<float>(view::windowHeight) / view::windowWidth : 1.0f;
    float nearPlane = 1.5f;
    float farPlane = 1500.0f;
    float top = nearPlane * tan(fovY * M_PI / 360.0); // Convert FOV from degrees to radians
    float bottom = -top;
    float right = top * aspectRatio;
    float left = -right;

    glFrustum(left, right, bottom, top, nearPlane, farPlane);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void view::initializeWindow(GLsizei width, GLsizei height) {
    // Stablishes the window size and the viewport
    view::windowWidth = width;
    view::windowHeight = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float fovY = 90.0f;
    setProjection(fovY);
}

void view::renderScene() {
	static GLfloat pos[4] = {5.0, 10.0, 10.0, 0.0}; // Light position

	utils::Color backGround = utils::Color(0.1f, 0.1f, 0.1f, 1.0f);

	glPushMatrix(); // Push the current geometric transformation

	glClearColor(backGround.rgba[0], backGround.rgba[1], backGround.rgba[2], backGround.rgba[3]); // Set the background color to black

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Initialize the color buffer and Z-Buffer

	viewTransform(); // Load the visualization transformation

	glLightfv(GL_LIGHT0, GL_POSITION, pos); // Light declaration. Placed here is fixed in the scene

	ejes.draw(); // Draw the axes


    body.setColor(utils::Color(1.0f, 1.0f, 1.0f, 1.0f));

    // q = q * utils::Quaternion(.1, 2, 0.0, 0.0);
    q.inPlaceNormalize();

    // p += utils::Vector3(0.01, 0.0, 0.00);

    body.draw(p, q);


	// bod.draw();

    // simulator.draw(); // Draw the current state of the simulator

	glPopMatrix(); // Pop the geometric transformation

	glutSwapBuffers(); // Swap the drawing and visualization buffer
};
