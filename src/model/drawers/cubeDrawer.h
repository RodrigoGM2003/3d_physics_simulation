#ifndef CUBE_DRAWER_H
#define CUBE_DRAWER_H

#include "model/drawers/prismDrawer.h"


namespace model{

class CubeDrawer : public PrismDrawer{
public:

    /**
     * @brief Construct a new Cube Drawer object
     * @param size The size of the cube
     */
    CubeDrawer(float size = 1);

    ~CubeDrawer() = default;
};



};





#endif