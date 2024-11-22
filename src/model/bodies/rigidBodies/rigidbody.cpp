#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"

#include "model/bodies/rigidBodies/rigidbody.h"

namespace model{

RigidBody::RigidBody(std::shared_ptr<model::Drawer> d,
            /*, TODO: const model::Collider& collider*/
            float mass, bool isStatic, const utils::Color color
            )
            : drawer(std::move(d)) /*, collider(collider)*/{
    this->setMass(mass);
    this->setIsStatic(isStatic);
    drawer->setColor(color);
}


void RigidBody::setPosition(const utils::Vector3& position){
    this->position = position;
    //TODO:: Update collider
    // updateCollider();
}

void RigidBody::setOrientation(const utils::Quaternion& orientation){
    this->orientation = orientation;

    //TODO: ASK CHATGPT ABOUT THIS
    this->orientation.inPlaceNormalize();

    //TODO: Update collider
    updateCollider();
}


float RigidBody::getMass() const{
    return mass;
}

void RigidBody::setMass(const float mass){
    this->mass = mass;
    this->inverseMass = 1 / mass;
}

float RigidBody::getInverseMass() const{
    return inverseMass;
}

utils::Matrix3 RigidBody::getInertiaTensor() const{
    return inertiaTensor;
}

void RigidBody::setInertiaTensor(const utils::Matrix3& inertiaTensor){
    this->inertiaTensor = inertiaTensor;
    this->inverseInertiaTensor = inertiaTensor.inverse();
}

utils::Matrix3 RigidBody::getInverseInertiaTensor() const{
    return inverseInertiaTensor;
}

utils::Vector3 RigidBody::getVelocity() const{
    return velocity;
}

void RigidBody::setVelocity(const utils::Vector3& velocity){
    this->velocity = velocity;
}

utils::Vector3 RigidBody::getAcceleration() const{
    return acceleration;
}

void RigidBody::setAcceleration(const utils::Vector3& acceleration){
    this->acceleration = acceleration;
}

utils::Vector3 RigidBody::getAngularVelocity() const{
    return angularVelocity;
}

void RigidBody::setAngularVelocity(const utils::Vector3& angularVelocity){
    this->angularVelocity = angularVelocity;
}

utils::Vector3 RigidBody::getAngularAcceleration() const{
    return angularAcceleration;
}

void RigidBody::setAngularAcceleration(const utils::Vector3& angularAcceleration){
    this->angularAcceleration = angularAcceleration;
}

bool RigidBody::getIsStatic() const{
    return isStatic;
}

void RigidBody::setIsStatic(const bool isStatic){
    this->isStatic = isStatic;
    inverseMass = isStatic ? 0 : 1 / mass;
}

void RigidBody::applyForce(const utils::Vector3& force){
    if(isStatic) return;

    this->force += force;
}

void RigidBody::applyTorque(const utils::Vector3& torque){
    if(isStatic) return;

    this->torque += torque;
}

void RigidBody::applyImpulse(const utils::Vector3& impulse){
    if(isStatic) return;

    velocity += impulse * inverseMass;
}

void RigidBody::applyAngularImpulse(const utils::Vector3& angularImpulse, const utils::Vector3& contactPoint){
    if(isStatic) return;

    //TODO: Apply angular impulse
}

void RigidBody::applyAcceleration(const utils::Vector3& acceleration){
    if(isStatic) return;

    this->acceleration += acceleration;
}


void RigidBody::update(float deltaTime){
    integrateLinear(deltaTime);
    integrateAngular(deltaTime);

    clearForces();
    clearTorques();

    updateCollider();
}


void RigidBody::draw(){
    
    // std::cout<<"Position: "<<position.x<<", "<<position.y<<", "<<position.z<<std::endl;
    // std::cout<<"Orientation: "<<orientation.w<<", "<<orientation.x<<", "<<orientation.y<<", "<<orientation.z<<std::endl;
    drawer->draw(position, orientation);
    std::cout<<"Drawed"<<std::endl;
}

void RigidBody::updateCollider(){
    //TODO: Update collider
    // collider.updateState(position, orientation);
    // collider.updateSwepAABB();
}

void RigidBody::clearForces(){
    force = utils::Vector3(0, 0, 0);
}

void RigidBody::clearTorques(){
    torque = utils::Vector3(0, 0, 0);
}

void RigidBody::integrateLinear(float deltaTime){
    if(isStatic) return;

    acceleration = force * inverseMass;
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
};

void RigidBody::integrateAngular(float deltaTime){
    if(isStatic) return;

    angularAcceleration = inverseInertiaTensor * torque;
    angularVelocity += angularAcceleration * deltaTime;

    float angle = angularVelocity.length() * deltaTime;

    utils::Quaternion rotation = utils::Quaternion::fromAxisAngleRads(angularVelocity, angle);
    orientation = rotation * orientation;
    orientation.inPlaceNormalize();
}

};