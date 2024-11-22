#include "model/bodies/rigidBodies/prismRigidBody.h"
#include "model/drawers/prismDrawer.h"
#include "utils/matrix3.h"


namespace model{

PrismRigidBody::PrismRigidBody(
    float mass, 
    bool isStatic, 
    float height, 
    float width, 
    float depth,
    const utils::Color color,
    const float elasticity,
    const float friction
)
    : RigidBody(
        std::make_shared<PrismDrawer>(height, width, depth),
        /*TODO: PrismCollider*/
        mass, 
        isStatic,
        color
    ), 
    height(height), 
    width(width), 
    depth(depth){
    // updateInertiaTensor();
}

void PrismRigidBody::start(const std::string& startData){
    std::cout<<startData<<std::endl;
    setPosition(utils::Vector3(5, 0, 0));
    setOrientation(utils::Quaternion::Identity);
    setVelocity(utils::Vector3(0, 0, 0));
    setAngularVelocity(utils::Vector3(0, 0, 0));
    setAcceleration(utils::Vector3(0, 0, 0));
    setAngularAcceleration(utils::Vector3(0, 0, 0));
}

void PrismRigidBody::updateInertiaTensor(){
    if (isStatic) {
        inertiaTensor = utils::Matrix3::zero();  // Zero tensor for static objects
        inverseInertiaTensor = utils::Matrix3::zero();
        return;
    }

    float h2 = height * height;
    float w2 = width * width;
    float d2 = depth * depth;
    float massFactor = (mass / 12.0f);

    inertiaTensor = utils::Matrix3(
        massFactor * (h2 + d2), 0, 0,
        0, massFactor * (w2 + d2), 0,
        0, 0, massFactor * (w2 + h2)
    );

    inverseInertiaTensor = inertiaTensor.inverse();  // Assuming utils::Matrix3 has an inverse function
}



};