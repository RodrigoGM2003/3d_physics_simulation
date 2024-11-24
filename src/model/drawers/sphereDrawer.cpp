#include "model/drawers/sphereDrawer.h"



namespace model{

// Define the static member `order`
const std::vector<int> SphereDrawer::order = {
    // Define the draw order for the sphere
};

// Define the static member `static_normals`
const std::vector<utils::Vector3> SphereDrawer::static_normals = {
    // Define the static normals for the sphere
};

SphereDrawer::SphereDrawer(float radius)
    : radius(radius) {}


const std::vector<int>& SphereDrawer::getOrder() const{
    return order;
}

const std::vector<utils::Vector3>& SphereDrawer::getStaticNormals() const{
    return static_normals;
}




};

