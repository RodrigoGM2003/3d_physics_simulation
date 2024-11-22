#include "../freeglut.3.0.0.v140.1.0.2/sources/GL/glut.h"

#include "model/drawers/prismDrawer.h"


namespace model{

// Define the static member `order`
const std::vector<int> PrismDrawer::order = {
    // +X face
    1, 2, 5,    2, 6, 5,
    // +Y face
    2, 3, 6,    3, 7, 6,
    // +Z face
    4, 5, 7,    5, 6, 7,
    // -X face
    0, 4, 3,    4, 7, 3,
    // -Y face
    0, 1, 4,    1, 5, 4,
    // -Z face
    0, 3, 1,    3, 2, 1
};
const std::vector<utils::Vector3> PrismDrawer::static_normals = {
    { 1, 0, 0 }, // +X face
    { 1, 0, 0 }, // +2nd X face
    { 0, 1, 0 }, // +Y face
    { 0, 1, 0 }, // +2nd Y face
    { 0, 0, 1 }, // +Z face
    { 0, 0, 1 }, // +2nd Z face
    { -1, 0, 0 }, // -X face
    { -1, 0, 0 }, // -2nd X face
    { 0, -1, 0 }, // -Y face
    { 0, -1, 0 }, // -2nd Y face
    { 0, 0, -1 }, // -Z face
    { 0, 0, -1 } // -2nd Z face
};

const std::vector<int>& PrismDrawer::getOrder() const{
    std::cout<<"PrismDrawer::getOrder()"<<std::endl;
    return order;
}

const std::vector<utils::Vector3>& PrismDrawer::getStaticNormals() const{
    return static_normals;
}

PrismDrawer::PrismDrawer(float height, float width, float depth){
    this->height = height;
    this->width = width;
    this->depth = depth;

    this->color = utils::Color(1.0f, 1.0f, 1.0f, 1.0f);

    this->vertices = {
        { -width / 2, -height / 2, -depth / 2 },
        {  width / 2, -height / 2, -depth / 2 },
        {  width / 2,  height / 2, -depth / 2 },
        { -width / 2,  height / 2, -depth / 2 },
        { -width / 2, -height / 2,  depth / 2 },
        {  width / 2, -height / 2,  depth / 2 },
        {  width / 2,  height / 2,  depth / 2 },
        { -width / 2,  height / 2,  depth / 2 }
    };
}

};