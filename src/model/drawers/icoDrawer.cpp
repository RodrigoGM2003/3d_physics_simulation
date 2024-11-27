#include "model/drawers/icoDrawer.h"
#include "utils/constants.h"
#include "utils/utils.h"


namespace model{

// Define the static member `order`
const std::vector<int> IcoDrawer::order = utils::icoOrder;


const std::vector<utils::Vector3> IcoDrawer::static_normals = []() {
    std::vector<utils::Vector3> normals;
    normals.reserve(order.size() / 3); // Reserve space for 20 faces (order.size() / 3)

    auto aux = utils::parseIcoVertices(utils::unitIcoVertices, 12);    

    // Iterate through each triangle in the order vector
    for (int i = 0; i < order.size(); i += 3) {
        // Get the three vertices of the triangle
        auto v0 = aux[order[i]];
        auto v1 = aux[order[i + 1]];
        auto v2 = aux[order[i + 2]];

        // Calculate the normal for the triangle
        normals.push_back(utils::triangleNormal(v0, v1, v2));
    }

    return normals;
}();

const std::vector<int>& IcoDrawer::getOrder() const{
    return order;
}

const std::vector<utils::Vector3>& IcoDrawer::getStaticNormals() const{
    return static_normals;
}

IcoDrawer::IcoDrawer(float side){
    this->side = side;

    this->color = utils::Color(1.0f, 1.0f, 1.0f, 1.0f);

    // The length of an edge of the unit icosahedron (calculated from the vertices)
    const float original_edge_length = std::sqrt(2 + utils::GOLDEN_RATIO * utils::GOLDEN_RATIO);
    const float scale = side / original_edge_length;

    // Scale the vertices based on the side length
    this->vertices = utils::parseIcoVertices(utils::unitIcoVertices, 12);

    for (auto& vertex : this->vertices)
        vertex *= scale;
    

    std::cout<<" Distance of first vertex from origin: "<<this->vertices[0].length()<<std::endl;
}
};

