#ifndef UTILS_H
#define UTILS_H

#include "utils/vector3.h"
#include "utils/quaternion.h"

namespace utils{

    /**
     * @brief Computes the normal of a triangle given its vertices
     * @param first The first vertex of the triangle
     * @param second The second vertex of the triangle
     * @param third The third vertex of the triangle
     * 
     * @return The normal of the triangle
     */
    Vector3 triangleNormal(const Vector3& first, const Vector3& second, const Vector3& third);


    /**
     * @brief Converts degrees to radians
     * @param degrees The angle in degrees
     * @return The angle in radians
     */
    inline float deg2rad(float degrees) {
        return degrees * M_PI / 180.0;
    }

    /**
     * @brief Converts radians to degrees
     * @param radians The angle in radians
     * @return The angle in degrees
     */
    inline float rad2deg(float radians) {
        return radians * 180.0 / M_PI;
    }

    /**
     * @brief Interpolates between two quaternions using spherical linear interpolation (SLERP).
     * @param q1 The starting quaternion.
     * @param q2 The ending quaternion.
     * @param t The interpolation factor [0, 1].
     * @return The interpolated quaternion.
     */
    Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t);
}

#endif