#ifndef SPHERE_DRAWER_H
#define SPHERE_DRAWER_H

#include "model/drawers/drawer.h"

namespace model{

class SphereDrawer : public Drawer{
protected:


    static bool initialized; /**< Number of subdivisions */
    static std::vector<utils::Vector3> static_vertices; /**< The vertices of the prism*/

    static std::vector<int> order; /**< The draw order of the vertices*/

    static std::vector<utils::Vector3> static_normals; /**< The normals of the prism*/

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

    static void initData();

public:

    // static bool initializeSphereData();

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

// #ifndef SPHERE_DRAWER_H
// #define SPHERE_DRAWER_H

// #include "model/drawers/drawer.h"
// #include "utils/constants.h"
// #include "utils/utils.h"
// #include <unordered_map>

// namespace model {

// class SphereDrawer : public Drawer {
// protected:
//     static const int SUBDIVISIONS; /**< Number of subdivisions */
//     static std::vector<utils::Vector3> static_vertices; /**< Vertices of the sphere */
//     static std::vector<int> order; /**< Draw order of the vertices */
//     static std::vector<utils::Vector3> static_normals; /**< Normals of the sphere */

//     float radius; /**< Radius of the sphere */

//     /**
//      * @brief Subdivides the icosahedron to approximate a sphere.
//      */
//     static void generateSphere(float radius);

//     /**
//      * @brief Get the order of the vertices.
//      * @return The order of the vertices.
//      */
//     const std::vector<int>& getOrder() const override;

//     /**
//      * @brief Get the static normals of the sphere.
//      * @return The static normals of the sphere.
//      */
//     const std::vector<utils::Vector3>& getStaticNormals() const override;

// public:
//     /**
//      * @brief Construct a new Sphere Drawer object.
//      * @param radius The radius of the sphere.
//      */
//     SphereDrawer(float radius = 1.0f);

//     ~SphereDrawer() = default;
// };

// }

// #endif