#ifndef PRISM_DRAWER_H
#define PRISM_DRAWER_H

#include "model/drawers/drawer.h"

namespace model{

class PrismDrawer : public Drawer{
protected:
    static const std::vector<int> order; /**< The draw order of the vertices*/

    static const std::vector<utils::Vector3> static_normals; /**< The normals of the prism*/

    float height, width, depth;



    const std::vector<int>& getOrder() const override;

    const std::vector<utils::Vector3>& getStaticNormals() const override;
public:
    PrismDrawer(float height = 1, float width = 1, float depth = 1);

    ~PrismDrawer() = default;
};


};




#endif