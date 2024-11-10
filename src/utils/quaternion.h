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

    static const Quaternion Identity;


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
     * @brief Creates a quaternion from an angle-axis representation (in radians).
     * @param axis The axis of rotation (should be normalized).
     * @param angle The angle in degrees.
     * @return The resulting quaternion.
     */
    static Quaternion fromAxisAngleRads(const Vector3& axis, float angle);
    
    /**
     * @brief Creates a quaternion from an angle-axis representation (in degrees).
     * @param axis The axis of rotation (should be normalized).
     * @param angle The angle in degrees.
     * @return The resulting quaternion.
     */
    static Quaternion fromAxisAngleDeg(const Vector3& axis, float angle);
    
    
    /**
     * @brief Creates a quaternion representing rotation between two vectors.
     * @param from The initial vector.
     * @param to The target vector.
     * @return The resulting quaternion.
     */
    static Quaternion fromTwoVectors(const Vector3& from, const Vector3& to);

    /**
     * @brief Normalizes the quaternion.
     * @return The normalized quaternion.
     */
    Quaternion normalize() const;


    /**
     * @brief In-place normalization of the quaternion.
     */
    void inPlaceNormalize() ;


    /**
     * @brief Calculates the inverse of the quaternion.
     * @return The inverse quaternion.
     */
    Quaternion inverse() const;

    /**
     * @brief Calculates the dot product of two quaternions.
     * @param other The other quaternion.
     * @return The dot product.
     */
    float dot(const Quaternion& other) const;

    /**
     * @brief Converts the quaternion to a rotation matrix.
     * @return The resulting 3x3 rotation matrix.
     */
    Matrix3 toMatrix() const;

    /**
     * @brief Operator for quaternion multiplication.
     * @param other The other quaternion.
     * @return The resulting quaternion.
     */
    Quaternion operator*(const Quaternion& other) const;

    /**
     * @brief Multiplies the quaternion by a scalar.
     * @param scalar The scalar to multiply by.
     * @return The scaled quaternion.
     */
    Quaternion operator*(float scalar) const;

    /**
     * @brief Adds the component-wise addition of two quaternions.
     * @param other The other quaternion.
     * @return The resulting quaternion.
     */
    Quaternion operator+(const Quaternion& other) const;

    /**
     * @brief Subtracts one quaternion from another.
     * @param other The quaternion to subtract.
     * @return The resulting quaternion.
     */
    Quaternion operator-(const Quaternion& other) const;

    /**
     * @brief Equality operator for quaternions.
     * @param other The other quaternion.
     * @return True if the quaternions are equal, false otherwise.
     */
    bool operator==(const Quaternion& other) const;


    /**
     * @brief Inequality operator for quaternions.
     * @param other The other quaternion.
     * @return True if the quaternions are not equal, false otherwise.
     */
    bool operator!=(const Quaternion& other) const;

    /**
     * @brief Rotates a vector by this quaternion.
     * @param vec The vector to rotate.
     * @return The rotated vector.
     */
    Vector3 rotate(const Vector3& vec) const;

    /**
     * @brief Conjugate of the quaternion (negates the imaginary part).
     * @return The conjugate quaternion.
     */
    Quaternion conjugate() const;

};

} // namespace utils

#endif // QUATERNION_H