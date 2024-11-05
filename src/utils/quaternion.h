#ifndef QUATERNION_H
#define QUATERNION_H

#include <cmath>
#include <algorithm> // For std::clamp

#include "utils/vector3.h"
#include "utils/matrix3.h"

namespace utils {

/**
 * @brief A class representing a quaternion for 3D rotations.
 */
class Quaternion {
public:
    float w, x, y, z;

    /**
     * @brief Default constructor, initializes as identity quaternion (1, 0, 0, 0).
     */
    Quaternion() : w(1), x(0), y(0), z(0) {}

    /**
     * @brief Constructor with parameters.
     * @param w The real part of the quaternion.
     * @param x The x component of the imaginary part.
     * @param y The y component of the imaginary part.
     * @param z The z component of the imaginary part.
     */
    Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

    /**
     * @brief Creates a quaternion from an angle-axis representation.
     * @param angle The angle in degrees.
     * @param axis The axis of rotation (should be normalized).
     * @return The resulting quaternion.
     */
    static Quaternion fromAxisAngle(float angle, const Vector3& axis) {
        float halfAngle = angle * 0.5f * (M_PI / 180.0f);
        float sinHalfAngle = sin(halfAngle);
        return Quaternion(cos(halfAngle), axis.x * sinHalfAngle, axis.y * sinHalfAngle, axis.z * sinHalfAngle);
    }

    /**
     * @brief Creates a quaternion representing rotation between two vectors.
     * @param from The initial vector.
     * @param to The target vector.
     * @return The resulting quaternion.
     */
    static Quaternion fromTwoVectors(const Vector3& from, const Vector3& to) {
        Vector3 f = from.normalize();
        Vector3 t = to.normalize();
        Vector3 crossProd = f.cross(t);
        float dotProd = f.dot(t);
        float w = sqrt(from.lengthSquared() * to.lengthSquared()) + dotProd;
        return Quaternion(w, crossProd.x, crossProd.y, crossProd.z).normalize();
    }

    /**
     * @brief Normalizes the quaternion.
     * @return The normalized quaternion.
     */
    Quaternion normalize() const {
        float len = sqrt(w * w + x * x + y * y + z * z);
        return Quaternion(w / len, x / len, y / len, z / len);
    }

    /**
     * @brief Converts the quaternion to a rotation matrix.
     * @return The resulting 3x3 rotation matrix.
     */
    Matrix3 toMatrix() const {
        Matrix3 matrix;
        matrix.m[0][0] = 1 - 2 * (y * y + z * z);
        matrix.m[0][1] = 2 * (x * y - z * w);
        matrix.m[0][2] = 2 * (x * z + y * w);
        matrix.m[1][0] = 2 * (x * y + z * w);
        matrix.m[1][1] = 1 - 2 * (x * x + z * z);
        matrix.m[1][2] = 2 * (y * z - x * w);
        matrix.m[2][0] = 2 * (x * z - y * w);
        matrix.m[2][1] = 2 * (y * z + x * w);
        matrix.m[2][2] = 1 - 2 * (x * x + y * y);
        return matrix;
    }

    /**
     * @brief Operator for quaternion multiplication.
     * @param other The other quaternion.
     * @return The resulting quaternion.
     */
    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    /**
     * @brief Multiplies the quaternion by a scalar.
     * @param scalar The scalar to multiply by.
     * @return The scaled quaternion.
     */
    Quaternion operator*(float scalar) const {
        return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Adds the component-wise addition of two quaternions.
     * @param other The other quaternion.
     * @return The resulting quaternion.
     */
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
    }

    /**
     * @brief Subtracts one quaternion from another.
     * @param other The quaternion to subtract.
     * @return The resulting quaternion.
     */
    Quaternion operator-(const Quaternion& other) const {
        return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
    }

    /**
     * @brief Rotates a vector by this quaternion.
     * @param vec The vector to rotate.
     * @return The rotated vector.
     */
    Vector3 rotate(const Vector3& vec) const {
        Quaternion vecQuat(0, vec.x, vec.y, vec.z);
        Quaternion result = (*this) * vecQuat * conjugate();
        return Vector3(result.x, result.y, result.z);
    }

    /**
     * @brief Conjugate of the quaternion (negates the imaginary part).
     * @return The conjugate quaternion.
     */
    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }


};

} // namespace utils

#endif // QUATERNION_H