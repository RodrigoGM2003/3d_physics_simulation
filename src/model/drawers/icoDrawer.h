#ifndef ICO_DRAWER_H
#define ICO_DRAWER_H

#include "model/drawers/drawer.h"

namespace model{

class IcoDrawer : public Drawer{
protected:

    static const std::vector<utils::Vector3> static_vertices; /**< The vertices of the prism*/
    static const std::vector<int> order; /**< The draw order of the vertices*/

    static const std::vector<utils::Vector3> static_normals; /**< The normals of the prism*/

    float side; /**< Length for the side of the icosahedron*/


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
    IcoDrawer(float radius = 1);

    ~IcoDrawer() = default;
};


};




#endif