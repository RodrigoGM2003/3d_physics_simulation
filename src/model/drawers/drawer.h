#ifndef DRAWER_H
#define DRAWER_H

#include <vector>

#include "utils/vector3.h"
#include "utils/quaternion.h"
#include "utils/color.h"


namespace model{

class Drawer{
protected:
    utils::Color color; /**< The color of the drawer */

    std::vector<utils::Vector3> vertices; /**< The vertices of the object */

    /**
     * @brief Get the draw order of the object
     * @return The draw order of the object
     */
    virtual const std::vector<int>& getOrder() const = 0;

    /**
     * @brief Get the static normals of the object
     * @return The static normals of the object
     */
    virtual const std::vector<utils::Vector3>& getStaticNormals() const = 0;

public:
    /**
     * @brief Draw the object
     */
    virtual void draw(const utils::Vector3& position, const utils::Quaternion& orientation) const;

    /**
     * @brief Set the color of the drawer
     * @param color The new color of the drawer
     */
    void setColor(const utils::Color& color);

    /**
     * @brief Get the color of the drawer
     * @return The color of the drawer
     */
    utils::Color getColor() const;


    virtual ~Drawer() = default;

};


};


#endif