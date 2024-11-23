#ifndef SPHERE_DRAWER_H
#define SPHERE_DRAWER_H

#include "model/drawers/drawer.h"

namespace model{

class SphereDrawer : public Drawer{
protected:

    static const std::vector<int> order; /**< The draw order of the vertices*/

    static const std::vector<utils::Vector3> static_normals; /**< The normals of the prism*/

    float radius; /**< The dimensions of the prism*/


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

    /**
     * @brief Construct a new Prism Drawer object
     * @param height The height of the prism
     * @param width The width of the prism
     * @param depth The depth of the prism
     */
    SphereDrawer(float radius = 1);

    ~SphereDrawer() = default;
};


};




#endif