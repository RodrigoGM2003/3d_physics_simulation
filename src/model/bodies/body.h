#ifndef BODY_H
#define BODY_H


#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "utils/utils.h"
#include "utils/vector3.h"
#include "utils/quaternion.h"


namespace model{

// class Body
// {
// public:
//     utils::Vector3 position;
//     float side;

//     Body(utils::Vector3 position = utils::Vector3(0, 0, 0));
//     void draw();
// };

class Body{
protected:
    utils::Vector3 position;
    utils::Quaternion orientation;

public:
    /**
     * @brief Start the parameters of the body
     * @param startData The data to start the body
     */
    virtual void start(const std::string& startData) = 0;

    /**
     * @brief Update the body
     * @param deltaTime The time passed since the last update
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief Draw the body
     */
    virtual void draw() = 0;

    /**
     * @brief Get the position of the body
     */
    virtual utils::Vector3 getPosition() const;

    /**
     * @brief Set the position of the body
     * @param p The new position of the body
     */
    virtual void setPosition(const utils::Vector3& p);

     /**
     * @brief Get the orientation of the body
     */
    virtual utils::Quaternion getOrientation() const;
 
    /**
     * @brief Set the Orientation of the body
     * @param o The new orientation of the body
     */
    virtual void setOrientation(const utils::Quaternion& o);

    ~Body() = default;
};

}



#endif