#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <chrono>
#include <vector>
#include <memory>


#include "view/renderer.h"
#include "model/bodies/body.h"

using namespace std::chrono;

namespace controller {

class Controller {
    //TODO: Add simulator
    // Simulator simulator;

    // steady_clock::time_point lastUpdateTime;

    std::vector<std::shared_ptr<model::Body>> bodies;


public:
    Controller();

    void initSimulator();

    void draw();

    void update(int dt);

    static Controller* getInstance();

private:
    static Controller* currentInstance;
};

void InitSimulator();

void Draw();

void Update(int dt);

};


#endif