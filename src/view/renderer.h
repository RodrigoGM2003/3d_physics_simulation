#ifndef RENDERER_H
#define RENDERER_H

#include <GL/gl.h>
#include <memory>

#include "model/modelo.h"
#include "model/bodies/body.h"


namespace view{

    /**
     * @brief Applies the view transformation to the current matrix
     */
    void viewTransform();

    /**
     * @brief Sets the camera position and orientation
     * @param ax The angle in the x axis
     * @param ay The angle in the y axis
     * @param d The distance from the camera to the origin
     */
    void setCamera(float ax, float ay, float d);

    /**
     * @brief Sets the projection matrix
     * @param fovY The field of view in the y axis
     */
    void setProjection(float fovY = 60.0f);

    /**
     * @brief Initializes the window with the given width and height
     * @param width The width of the window
     * @param height The height of the window
     */
    void initializeWindow(GLsizei width, GLsizei height);

    /**
     * @brief Renders the scene (draw function)
     */
    void renderScene(const std::vector<std::shared_ptr<model::Body>>& bodies);
};



#endif