#include <cmath>

#include "utils/utils.h"

namespace utils {

/**
 * @brief Computes the normal of a triangle given its vertices
 * @param first The first vertex of the triangle
 * @param second The second vertex of the triangle
 * @param third The third vertex of the triangle
 * 
 * @return The normal of the triangle
 */
Vector3 triangleNormal(const Vector3& first, const Vector3& second, const Vector3& third) {
    Vector3 u = second - first;
    Vector3 v = third - first;

    return u.cross(v).normalize();
}

Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t) {
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