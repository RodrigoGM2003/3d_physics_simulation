#ifndef RIDIGBODY_H
#define RIDIGBODY_H

#include "model/bodies/body.h"

namespace model{

class RigidBody{
protected:
    float mass;
    float inverseMass;

    // utils::Matrix3 inertiaTensor;
    // utils::Matrix3 inverseInertiaTensor;

    utils::Vector3 velocity;
    utils::Vector3 acceleration;

    utils::Vector3 angularVelocity;
    utils::Vector3 angularAcceleration;

    bool isStatic;

    //model::Collider collider;
    //model::Drawer draw;

public:
    /**
     * @brief Constructor of the rigid body
     * @param collider The collider of the body
     * @param draw The draw of the body
     * @param mass The mass of the body
     * @param velocity The velocity of the body
     * @param acceleration The acceleration of the body
     * @param angularVelocity The angular velocity of the body
     * @param angularAcceleration The angular acceleration of the body
     * @param isStatic If the body is static
     */
    RigidBody(/*Collider& collider, 
                Drawer& drawer, */
            const float mass = 1,
            // const utils::Vector3& velocity = utils::Vector3::zero(),
            // const utils::Vector3& acceleration = utils::Vector3::zero(),
            // const utils::Vector3& angularVelocity = utils::Vector3::zero(),
            // const utils::Vector3& angularAcceleration = utils::Vector3::zero(),
            const bool isStatic = false);


    float getMass() const;
    void setMass(const float mass);

    float getInverseMass() const;
    void setInverseMass(const float);

    utils::Vector3 getVelocity() const;
    void setVelocity(const utils::Vector3& velocity);

    utils::Vector3 getAcceleration() const;
    void setAcceleration(const utils::Vector3& acceleration);

    utils::Vector3 getAngularVelocity() const;
    void setAngularVelocity(const utils::Vector3& angularVelocity);

    utils::Vector3 getAngularAcceleration() const;
    void setAngularAcceleration(const utils::Vector3& angularAcceleration);

    bool getIsStatic() const;
    void setIsStatic(const bool isStatic);


    void start(const std::string& startData);

    void update(float deltaTime);

    void draw();
    void getPosition();
    void setPosition(const utils::Vector3& position);

    void ApplyForce(const utils::Vector3& force);
    void ApplyTorque(const utils::Vector3& torque);




    ~RigidBody() = default;
};
}


#endif 