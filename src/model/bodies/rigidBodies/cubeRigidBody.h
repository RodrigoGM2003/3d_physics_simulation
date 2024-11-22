#ifndef CUBE_RIGIDBODY_H
#define CUBE_RIGIDBODY_H

#include "model/bodies/rigidBodies/prismrigidbody.h"

namespace model{
class CubeRigidBody : public PrismRigidBody{
public:
    /**
     * @brief Construct a new Cube Rigid Body object
     * @param mass The mass of the body
     * @param isStatic If the body is static
     * @param side The side of the cube
     */
    CubeRigidBody(
        float mass = 1.0f, 
        bool isStatic = false, 
        float side = 1.0f,
        const utils::Color color = utils::Color(1.0f, 1.0f, 1.0f),
        const float elasticity = 0.5f,
        const float friction = 0.5f
    );

    /**TODO:
     * @brief Start the parameters of the body
     * @param startData The data to start the body
     */
    void start(const std::string& startData) override;

    ~CubeRigidBody() = default;

protected:
};

};


#endif