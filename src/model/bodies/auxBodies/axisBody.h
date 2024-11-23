#ifndef AXIS_BODY_H
#define AXIS_BODY_H

#include <memory>

#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"

#include "model/bodies/body.h"
#include "utils/utils.h"
#include "utils/quaternion.h"
#include "utils/color.h"
#include "model/drawers/axisDrawer.h"


namespace model{

class AxisBody : public Body{

    utils::Vector3 axis; /**< The axis of the body*/
    float length; /**< The length of the axis*/
    std::shared_ptr<model::Drawer> drawer; /**< The drawer of the body*/

public:
    AxisBody(const utils::Vector3& axis, float length = 1, 
            const utils::Color& color = utils::Color(1, 1, 1, 1));

    /**
     * @brief Start the parameters of the body
     * @param startData The data to start the body
     */
    void start(const std::string& startData) override;

    /**
     * @brief Update the body
     * @param deltaTime The time passed since the last update
     */
    void update(float deltaTime) override;

    /**
     * @brief Draw the body
     */
    void draw() const override;

    ~AxisBody() = default;
};

};

#endif