#ifndef RIDIGBODY_H
#define RIDIGBODY_H

#include <memory>

#include "model/bodies/body.h"
#include "model/drawers/drawer.h"
#include "utils/matrix3.h"


namespace model{

class RigidBody : public Body{
protected:
    float mass;
    float inverseMass;

    utils::Matrix3 inertiaTensor;
    utils::Matrix3 inverseInertiaTensor;

    utils::Vector3 velocity;
    utils::Vector3 acceleration;

    utils::Vector3 angularVelocity;
    utils::Vector3 angularAcceleration;

    utils::Vector3 force;
    utils::Vector3 torque;

    bool isStatic;

    //TODO: Add collider and drawer
    //model::Collider collider;
    // const model::Drawer& drawer;
    std::shared_ptr<model::Drawer> drawer;


    /**
     * @brief Construct a new Rigid Body object
     * @param d The drawer of the body (shared pointer)
     * @param c The collider of the body (shared pointer)
     * @param mass The mass of the body
     * @param isStatic If the body is static
     */
    RigidBody(std::shared_ptr<model::Drawer> d,
        /*, TODO: const model::Collider& collider*/
        float mass = 1.0f, 
        bool isStatic = false,
        const utils::Color color = utils::Color(1.0f, 1.0f, 1.0f)
    );

public:
    /**
     * @brief Set the position of the body
     * @param position The new position of the body
     */
    void setPosition(const utils::Vector3& position) override;

    /**
     * @brief Set the orientation of the body
     * @param orientation The new orientation of the body
     */
    void setOrientation(const utils::Quaternion& orientation) override;

    /**
     * @brief Get the mass of the body
     * @return The mass of the body
     */
    float getMass() const;

    /**
     * @brief Set the mass of the body
     * @param mass The new mass of the body
     */
    void setMass(const float mass);

    /**
     * @brief Get the inverse mass of the body
     * @return The inverse mass of the body
     */
    float getInverseMass() const;

    /**
     * @brief Get the inertia tensor of the body
     * @return The inertia tensor of the body
     */
    utils::Matrix3 getInertiaTensor() const;

    /**
     * @brief Set the inertia tensor of the body
     * @param inertiaTensor The new inertia tensor of the body
     */
    void setInertiaTensor(const utils::Matrix3& inertiaTensor);

    /**
     * @brief Get the inverse inertia tensor of the body
     * @return The inverse inertia tensor of the body
     */
    utils::Matrix3 getInverseInertiaTensor() const;

    /**
     * @brief Get the velocity of the body
     * @return The velocity of the body
     */
    utils::Vector3 getVelocity() const;

    /**
     * @brief Set the velocity of the body
     * @param velocity The new velocity of the body
     */
    void setVelocity(const utils::Vector3& velocity);

    /**
     * @brief Get the acceleration of the body
     * @return The acceleration of the body
     */
    utils::Vector3 getAcceleration() const;

    /**
     * @brief Set the acceleration of the body
     * @param acceleration The new acceleration of the body
     */
    void setAcceleration(const utils::Vector3& acceleration);

    /**
     * @brief Get the angular velocity of the body
     * @return The angular velocity of the body
     */
    utils::Vector3 getAngularVelocity() const;

    /**
     * @brief Set the angular velocity of the body
     * @param angularVelocity The new angular velocity of the body
     */
    void setAngularVelocity(const utils::Vector3& angularVelocity);

    /**
     * @brief Get the angular acceleration of the body
     * @return The angular acceleration of the body
     */
    utils::Vector3 getAngularAcceleration() const;
    
    /**
     * @brief Set the angular acceleration of the body
     * @param angularAcceleration The new angular acceleration of the body
     */
    void setAngularAcceleration(const utils::Vector3& angularAcceleration);

    /**
     * @brief Get if the body is static
     * @return If the body is static
     */
    bool getIsStatic() const;
    
    /**
     * @brief Set if the body is static
     * @param isStatic If the body is static
     */
    void setIsStatic(const bool isStatic);

    /**
     * @brief Apply a force to the body
     * @param force The force to apply
     */
    void applyForce(const utils::Vector3& force);

    /**
     * @brief Apply a torque to the body
     * @param torque The torque to apply
     */
    void applyTorque(const utils::Vector3& torque);

    /**
     * @brief Apply an impulse to the body
     * @param impulse The impulse to apply
     */
    void applyImpulse(const utils::Vector3& impulse);

    /**
     * @brief Apply an angular impulse to the body
     * @param angularImpulse The angular impulse to apply
     * @param contactPoint The point where the impulse is applied
     */
    void applyAngularImpulse(const utils::Vector3& angularImpulse, const utils::Vector3& contactPoint);
    
    /**
     * @brief Apply an acceleration to the body
     * @param acceleration The acceleration to apply
     */
    void applyAcceleration(const utils::Vector3& acceleration);


    void start(const std::string& startData) = 0;

    void update(float deltaTime) override;

    void draw() override;


    ~RigidBody() = default;

private:

    /**
     * @brief Update the inertia tensor of the body
     */
    //TODO: Implement this method
    virtual void updateInertiaTensor() = 0;

    /**
     * @brief Update the inverse inertia tensor of the body
     */
    void updateCollider();

    /**
     * @brief Clear the forces of the body
     */
    void clearForces();

    /**
     * @brief Clear the torques of the body
     */
    void clearTorques();


    /**
     * @brief Integrate the linear movement of the body
     * @param deltaTime The time passed since the last integration
     */
    void integrateLinear(float deltaTime);

    /**
     * @brief Integrate the angular movement of the body
     * @param deltaTime The time passed since the last integration
     */
    void integrateAngular(float deltaTime);
};

};


#endif 