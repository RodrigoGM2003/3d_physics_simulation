#ifndef AXIS_DRAWER_H
#define AXIS_DRAWER_H

#include "model/drawers/drawer.h"

namespace model{

class AxisDrawer : public Drawer{

    static const std::vector<int> order; /**< The draw order of the vertices*/

    float length; /**< The length of the axis*/

    /**
     * @brief Get the order of the vertices
     * @return The order of the vertices
     */
    const std::vector<int>& getOrder() const override;

    /**
     * @brief Get the static normals of the prism
     * @return The static normals of the prism
     */
    const std::vector<utils::Vector3>& getStaticNormals() const override;

public:

    void draw(const utils::Vector3& position, const utils::Quaternion& orientation) const override;


    /**
     * @brief Construct a new Prism Drawer object
     * @param height The height of the prism
     * @param width The width of the prism
     * @param depth The depth of the prism
     */
    AxisDrawer(utils::Vector3 axis, float length = 1);

    ~AxisDrawer() = default;
};


};



#endif