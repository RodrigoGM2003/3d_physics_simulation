#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view/renderer.h"

namespace controller {

class Controller {
public:
    Controller();

    void initSimulator();

    void draw();

    void update();

    static Controller* getInstance();

private:
    static Controller* currentInstance;
};

void Draw();

void Update(int dt);

}; // namespace controller


#endif