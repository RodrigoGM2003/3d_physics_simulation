#include <cmath>

#include "utils/utils.h"

/**
 * @brief Computes the normal of a triangle given its vertices
 * @param first The first vertex of the triangle
 * @param second The second vertex of the triangle
 * @param third The third vertex of the triangle
 * 
 * @return The normal of the triangle
 */
utils::Vector3 utils::triangleNormal(const utils::Vector3& first, const utils::Vector3& second, const utils::Vector3& third) {
    utils::Vector3 u = second - first;
    utils::Vector3 v = third - first;

    return u.cross(v).normalize();
}