#include "model/drawers/icoDrawer.h"
#include "utils/constants.h"
#include "utils/utils.h"


namespace model{

const std::vector<utils::Vector3> IcoDrawer::static_vertices = {
    {0, utils::GOLDEN_RATIO, 1},    //0
    {0, utils::GOLDEN_RATIO, -1},   //1
    {utils::GOLDEN_RATIO, 1, 0},    //2
    {-utils::GOLDEN_RATIO, 1, 0},   //3
    {1, 0, utils::GOLDEN_RATIO},    //4
    {-1, 0, utils::GOLDEN_RATIO},  //5
    {1, 0, -utils::GOLDEN_RATIO},   //6
    {-1, 0, -utils::GOLDEN_RATIO}, //7
    {utils::GOLDEN_RATIO, -1, 0},   //8
    {-utils::GOLDEN_RATIO, -1, 0},  //9
    {0, -utils::GOLDEN_RATIO, 1},   //10
    {0, -utils::GOLDEN_RATIO, -1}   //11
};


// Define the static member `order`
const std::vector<int> IcoDrawer::order = {
    0, 2, 1, //F0
    0, 1, 3, //F1
    0, 3, 5, //F2
    0, 5, 4, //F3
    0, 4, 2, //F4
    2, 4, 8, //F5
    2, 8, 6, //F6
    2, 6, 1, //F7
    1, 6, 7, //F8
    1, 7, 3, //F9
    3, 7, 9, //F10
    3, 9, 5, //F11
    10, 4, 5, //F12
    10, 5, 9, //F13
    10, 9, 11, //F14
    10, 11, 8, //F15
    10, 8, 4, //F16
    11, 9, 7, //F17
    11, 7, 6, //F18
    11, 6, 8 //F19
};


const std::vector<utils::Vector3> IcoDrawer::static_normals = []() {
    std::vector<utils::Vector3> normals;
    normals.reserve(order.size() / 3); // Reserve space for 20 faces (order.size() / 3)

    // Iterate through each triangle in the order vector
    for (int i = 0; i < order.size(); i += 3) {
        // Get the three vertices of the triangle
        auto v0 = static_vertices[order[i]];
        auto v1 = static_vertices[order[i + 1]];
        auto v2 = static_vertices[order[i + 2]];

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

    this->vertices = {
        {0, utils::GOLDEN_RATIO, 1},    //0
        {0, utils::GOLDEN_RATIO, -1},   //utils::GOLDEN_RATIO
        {utils::GOLDEN_RATIO, 1, 0},    //2
        {-utils::GOLDEN_RATIO, 1, 0},   //3
        {1, 0, utils::GOLDEN_RATIO},    //4
        {-1, 0, utils::GOLDEN_RATIO},  //5
        {1, 0, -utils::GOLDEN_RATIO},   //6
        {-1, 0, -utils::GOLDEN_RATIO}, //7
        {utils::GOLDEN_RATIO, -1, 0},   //8
        {-utils::GOLDEN_RATIO, -1, 0},  //9
        {0, -utils::GOLDEN_RATIO, 1},   //utils::GOLDEN_RATIO0
        {0, -utils::GOLDEN_RATIO, -1}   //11
    };
}

};

