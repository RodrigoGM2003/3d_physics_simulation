#include <GL/gl.h>
#include <chrono>

#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"
#include "controller/controller.h"
#include "model/bodies/rigidBodies/prismRigidBody.h"
#include "model/bodies/rigidBodies/cubeRigidBody.h"
#include "model/bodies/auxBodies/axisBody.h"


namespace controller {

Controller::Controller() {
    currentInstance = this;  // Store the current instance
    bodies = std::vector<std::shared_ptr<model::Body>>();
}


void Controller::initSimulator() {
    std::cout << "Initializing simulator" << std::endl;

    auto xAxis = std::make_shared<model::AxisBody>(utils::Vector3(1.0f, 0.0f, 0.0f), 30.0f, utils::Color(1.0f, 0.0f, 0.0f, 1.0f));
    auto yAxis = std::make_shared<model::AxisBody>(utils::Vector3(0.0f, 1.0f, 0.0f), 30.0f, utils::Color(0.0f, 1.0f, 0.0f, 1.0f));
    auto zAxis = std::make_shared<model::AxisBody>(utils::Vector3(0.0f, 0.0f, 1.0f), 30.0f, utils::Color(0.0f, 0.0f, 1.0f, 1.0f));

    bodies.push_back(xAxis);
    bodies.push_back(yAxis);
    bodies.push_back(zAxis);

    std::shared_ptr<model::PrismRigidBody> myBody = std::make_shared<model::PrismRigidBody>(
        1.0f, 
        false, 
        2.0f, 
        3.0f, 
        5.0f, 
        utils::Color(0.0f, 0.5f, 0.5f, 1.0f), 
        0.5f, 
        0.5f
    );

    bodies.push_back(myBody);

    auto myBody2 = std::make_shared<model::CubeRigidBody>(
        1.0f, 
        false, 
        2.0f, 
        utils::Color(0.5f, 0.0f, 0.5f, 1.0f), 
        0.5f, 
        0.5f
    );

    myBody2->setPosition(utils::Vector3(4.0f, 0.0f, 0.0f));

    bodies.push_back(myBody2);


    // lastUpdateTime = steady_clock::now();
    // std::cout<<"Last update time: "<<lastUpdateTime.time_since_epoch().count()<<std::endl;
    // std::cout<<"Check"<<std::endl;
}

void Controller::draw() {
    view::renderScene(bodies);
}

void Controller::update(int dt) {
    //TODO: FIX THIS
    // Calcula el tiempo actual
    // steady_clock::time_point currentTime = steady_clock::now();

    // // // Calcula el tiempo transcurrido en milisegundos
    // auto elapsedTime = duration_cast<milliseconds>(currentTime - lastUpdateTime).count();

    // // // Actualiza el simulador con el tiempo transcurrido
    // std::cout << "Tiempo transcurrido desde la última actualización: " << elapsedTime << " ms\n";

    // // Aquí iría la lógica del simulador, utilizando elapsedTime
    for (const auto& body : bodies) {
        body->update(1);
    }

    // // Actualiza el tiempo del último frame
    // lastUpdateTime = currentTime;

    // Update the scene
    // simulator.update();
    glutPostRedisplay();

	glutTimerFunc(30, Update, 0); 
}

Controller* Controller::getInstance() {
    return currentInstance;
}


void Draw() {
    Controller::getInstance()->draw();
}

void Update(int dt) {
    Controller::getInstance()->update(dt);
}

void InitSimulator() {
    Controller::getInstance()->initSimulator();
}

};