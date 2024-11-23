#include "model/bodies/auxBodies/axisBody.h"

namespace model{

AxisBody::AxisBody(const utils::Vector3& axis, float length, 
                const utils::Color& color) 
                : length(length){
    this->axis = axis.normalize();
    drawer = std::make_shared<model::AxisDrawer>(axis.normalize(), length);
    drawer->setColor(color);
}

void AxisBody::start(const std::string& startData){
    // Do nothing
}

void AxisBody::update(float deltaTime){
    // Do nothing
}

void AxisBody::draw() const{
    drawer->draw(position, orientation);
}

};

