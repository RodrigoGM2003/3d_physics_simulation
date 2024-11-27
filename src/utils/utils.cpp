#include <cmath>

#include "utils/utils.h"

namespace utils {

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

Vector3 slerp(const Vector3& v1, const Vector3& v2, float t) {
    // Ensure both vectors are normalized
    Vector3 v1_norm = v1.normalize();
    Vector3 v2_norm = v2.normalize();

    // Compute the dot product (cosine of the angle between the vectors)
    float dot = std::clamp(v1_norm.dot(v2_norm), -1.0f, 1.0f);

    // Calculate the angle (theta)
    float theta = std::acos(dot);

    // Handle edge cases
    if (std::abs(theta) < 1e-5) {
        // If the angle is very small, linear interpolation is sufficient
        return (v1_norm * (1.0f - t) + v2_norm * t).normalize();
    }

    // Perform SLERP
    float sinTheta = std::sin(theta);
    float weight1 = std::sin((1.0f - t) * theta) / sinTheta;
    float weight2 = std::sin(t * theta) / sinTheta;

    return (v1_norm * weight1 + v2_norm * weight2).normalize();
}

std::vector<Vector3> parseIcoVertices(const float* vertices, int n) {
    std::vector<Vector3> result;

    n = n * 3;

    for(int i = 0; i < n; i+=3)
        result.push_back(Vector3(vertices[i], vertices[i+1], vertices[i+2]));

    return result;
}

}; // namespace utils