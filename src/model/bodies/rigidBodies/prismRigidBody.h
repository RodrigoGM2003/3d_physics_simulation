#ifndef PRIISM_RIGIDBODY_H
#define PRIISM_RIGIDBODY_H

#include "model/bodies/rigidBodies/rigidbody.h"

namespace model{

class PrismRigidBody : public RigidBody{

protected:
    float height, width, depth; /**< The dimensions of the prism */

public:
    /**
     * @brief Construct a new Prism Rigid Body object
     * @param mass The mass of the body
     * @param isStatic If the body is static
     * @param height The height of the prism
     * @param width The width of the prism
     * @param depth The depth of the prism
     * @param color The color of the prism
     * @param elasticity The elasticity of the prism
     * @param friction The friction of the prism
     */
    PrismRigidBody(float mass = 1.0f, 
        bool isStatic = false, 
        float height = 1.0f, 
        float width = 1.0f,
        float depth = 1.0f,
        const utils::Color color = utils::Color(1.0f, 1.0f, 1.0f),
        const float elasticity = 0.5f,
        const float friction = 0.5f
    );

    /**TODO:
     * @brief Start the parameters of the body
     * @param startData The data to start the body
     */
    virtual void start(const std::string& startData) override = 0;

    ~PrismRigidBody() = default;

protected:
    /**TODO:
     * @brief Update the inertia tensor of the body
     */
    void updateInertiaTensor() override;
};


};



#endif