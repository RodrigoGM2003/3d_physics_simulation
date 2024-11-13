#ifndef PRISM_DRAWER_H
#define PRISM_DRAWER_H

#include "model/drawers/drawer.h"

namespace model{

class PrismDrawer : public Drawer{
protected:

    //TODO: COMENTAR
    static const std::vector<int> order; /**< The draw order of the vertices*/

    static const std::vector<utils::Vector3> static_normals; /**< The normals of the prism*/

    float height, width, depth; /**< The dimensions of the prism*/


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
    PrismDrawer(float height = 1, float width = 1, float depth = 1);

    ~PrismDrawer() = default;
};


};




#endif