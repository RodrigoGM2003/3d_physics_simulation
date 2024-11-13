#include "model/bodies/rigidBodies/cuberigidbody.h"


namespace model{

CubeRigidBody::CubeRigidBody(
    float mass, 
    bool isStatic, 
    float side,
    const utils::Color color,
    const float elasticity,
    const float friction
)
    : PrismRigidBody(
        mass, 
        isStatic, 
        side, 
        side, 
        side,
        color,
        elasticity,
        friction
        ){}
    
};
