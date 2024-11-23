#ifndef SPHERE_RIGIDBODY_H
#define SPHERE_RIGIDBODY_H

#include "model/bodies/rigidBodies/rigidbody.h"
#include "model/drawers/sphereDrawer.h"

namespace model{

class SphereRigidBody : public RigidBody{

protected:
    float radius; /**< The dimensions of the prism */

public:
    /**
     * @brief Construct a new Prism Rigid Body object
     * @param mass The mass of the body
     * @param isStatic If the body is static
     * @param radius The height of the prism
     * @param color The color of the prism
     * @param elasticity The elasticity of the prism
     * @param friction The friction of the prism
     */
    SphereRigidBody(float mass = 1.0f, 
        bool isStatic = false, 
        float radius = 1.0f,
        const utils::Color color = utils::Color(1.0f, 1.0f, 1.0f),
        const float elasticity = 0.5f,
        const float friction = 0.5f
    );

    /**TODO:
     * @brief Start the parameters of the body
     * @param startData The data to start the body
     */
    void start(const std::string& startData) override;

    ~SphereRigidBody() = default;

protected:
    /**
     * @brief Update the inertia tensor of the body
     */
    void updateInertiaTensor() override;
};


};



#endif