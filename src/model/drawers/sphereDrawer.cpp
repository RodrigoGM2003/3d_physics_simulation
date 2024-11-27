#include "model/drawers/sphereDrawer.h"
#include "utils/constants.h"
#include "utils/utils.h"
#include <unordered_map>

#include <cstdint> // Include this header for uint64_t



namespace model {

std::vector<int> SphereDrawer::order = {};

std::vector<utils::Vector3> SphereDrawer::static_vertices = {};

std::vector<utils::Vector3> SphereDrawer::static_normals = {};

bool SphereDrawer::initialized = false;

void SphereDrawer::initData() {
    if (initialized)
        return;


    auto auxVertices = utils::parseIcoVertices(utils::sphereIcoVertices, 60);

    for(int sub = 0; sub < utils::SPHERE_SUBDIVISIONS; sub++){

        for (int i = 0; i < auxVertices.size(); i += 3) {
            auto newVertices = std::vector<utils::Vector3>();
            newVertices.push_back(auxVertices[i]);
            newVertices.push_back(auxVertices[i + 1]);
            newVertices.push_back(auxVertices[i + 2]);

            newVertices.push_back(utils::slerp(auxVertices[i], auxVertices[i + 1], 0.5));
            newVertices.push_back(utils::slerp(auxVertices[i + 1], auxVertices[i + 2], 0.5));
            newVertices.push_back(utils::slerp(auxVertices[i + 2], auxVertices[i], 0.5));

            int offset = static_vertices.size();
            std::vector<int> newOrder = {
                0, 3, 5,
                3, 1, 4,
                5, 4, 2,
                3, 4, 5
            };
            for (auto& index : newOrder) 
                index += offset;
            for(int vertex = 0; vertex < 6; vertex++){
                bool found = false;
                int j = 0;
                for (; j < static_vertices.size() && !found; j++) {
                    auto existingVertex = static_vertices[j];
                    found = std::abs(utils::Vector3::distance(newVertices[vertex], 
                                                    existingVertex)) < 1e-6;
                }
                if (found){
                    for (auto& o : newOrder)
                        if (o == vertex)
                            o = j;
                }
                else{
                    static_vertices.push_back(newVertices[vertex]);
                }
            }
            for (auto& index : newOrder) 
                order.push_back(index);
        }
    }

    static_normals.reserve(order.size() / 3); // Reserve space for 20 faces (order.size() / 3)

    // Iterate through each triangle in the order vector
    for (int i = 0; i < order.size(); i += 3) {
        // Get the three vertices of the triangle
        auto v0 = static_vertices[order[i]];
        auto v1 = static_vertices[order[i + 1]];
        auto v2 = static_vertices[order[i + 2]];

        // Calculate the normal for the triangle
        static_normals.push_back(utils::triangleNormal(v0, v1, v2));
    }
    std::cout<<"ME CAGO EN US MURCIELAGOS"<<std::endl;
    initialized = true;
}

// Constructor
SphereDrawer::SphereDrawer(float radius) {
    initData();
    this->radius = radius;
    this->vertices = static_vertices; // Start with unit sphere vertices
    

    std::cout<<vertices[order[0]]<< " "<<vertices[order[1]]<< " "<<vertices[order[2]]<<std::endl;
    std::cout<<static_normals[0]<<std::endl;

    for(auto& vertex : this->vertices)
        vertex *= radius;

    this->color = utils::Color(1.0f, 1.0f, 1.0f, 1.0f);
}

// Getters for static data
const std::vector<int>& SphereDrawer::getOrder() const {
    return order;
}

const std::vector<utils::Vector3>& SphereDrawer::getStaticNormals() const {
    return static_normals;
}

};






