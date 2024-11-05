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
    utils::Vector3 triangleNormal(const utils::Vector3& first, const utils::Vector3& second, const utils::Vector3& third);


    /**
     * @brief Converts degrees to radians
     * @param degrees The angle in degrees
     * @return The angle in radians
     */
    inline float utils::deg2rad(float degrees) {
        return degrees * M_PI / 180.0;
    }

    /**
     * @brief Converts radians to degrees
     * @param radians The angle in radians
     * @return The angle in degrees
     */
    inline float utils::rad2deg(float radians) {
        return radians * 180.0 / M_PI;
    }

        /**
     * @brief Interpolates between two quaternions using spherical linear interpolation (SLERP).
     * @param q1 The starting quaternion.
     * @param q2 The ending quaternion.
     * @param t The interpolation factor [0, 1].
     * @return The interpolated quaternion.
     */
    static Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t) {
        float dot = q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z;
        const float threshold = 0.9995f;

        if (fabs(dot) > threshold) {
            Quaternion result = Quaternion(
                q1.w + t * (q2.w - q1.w),
                q1.x + t * (q2.x - q1.x),
                q1.y + t * (q2.y - q1.y),
                q1.z + t * (q2.z - q1.z)
            ).normalize();
            return result;
        }

        dot = std::clamp(dot, -1.0f, 1.0f);
        float theta_0 = acos(dot);
        float theta = theta_0 * t;

        Quaternion q3 = (q2 - q1 * dot).normalize();
        return q1 * cos(theta) + q3 * sin(theta);
    }
}

#endif