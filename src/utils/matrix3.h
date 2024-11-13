#ifndef MATRIX3_H
#define MATRIX3_H

#include <cmath>
#include <iostream>
#include <stdexcept>
#include "Vector3.h" // Assume you have a Vector3 class


namespace utils {
/**
 * @brief A class representing a 3x3 real matrix
 */
class Matrix3 {
public:
    /**
     * @brief The matrix values
     */
    float m[3][3];

    /**
     * @brief Creates an identity matrix
     * @return The identity matrix
     */
    static Matrix3 identity();

    /**
     * @brief Creates a zero matrix
     * @return The zero matrix
     */
    static Matrix3 zero();

    /**
     * @brief Creates a rotation matrix around the X axis
     * @param angle The angle of rotation in degrees
     * @return The rotation matrix
     */
    static Matrix3 rotationX(float angle);

    /**
     * @brief Creates a rotation matrix around the Y axis
     * @param angle The angle of rotation in degrees
     * @return The rotation matrix
     */
    static Matrix3 rotationY(float angle);

    /**
     * @brief Creates a rotation matrix around the Z axis
     * @param angle The angle of rotation in degrees
     * @return The rotation matrix
     */
    static Matrix3 rotationZ(float angle);

    /**
     * @brief Creates a scaling matrix
     * @param scaleX The scaling factor along the X axis
     * @param scaleY The scaling factor along the Y axis
     * @param scaleZ The scaling factor along the Z axis
     * @return The scaling matrix
     */
    static Matrix3 scaling(float scaleX, float scaleY, float scaleZ);

    /**
     * @brief Default constructor
     * @details Initializes the matrix as the identity matrix
     */
    Matrix3();

    /**
     * @brief Constructor with parameters
     * @param values The values of the matrix
     */
    Matrix3(float values[3][3]);

    /**
     * @brief Constructor with parameters
     * @param vx The value at position (x, x)
     */
    Matrix3(float v00, float v01, float v02, 
            float v10, float v11, float v12, 
            float v20, float v21, float v22);


    /**
     * @brief Operator to add two matrices
     * @param other The matrix to add
     * @return The result of the addition
     */
    Matrix3 operator+(const Matrix3& other) const;

    /**
     * @brief Operator to add a matrix to the current matrix
     * @param other The matrix to add
     * @return The current matrix
     */
    Matrix3& operator+=(const Matrix3& other);

    /**
     * @brief Operator to subtract two matrices
     * @param other The matrix to subtract
     * @return The result of the subtraction
     */
    Matrix3 operator-(const Matrix3& other) const;

    /**
     * @brief Operator to subtract a matrix from the current matrix
     * @param other The matrix to subtract
     * @return The current matrix
     */
    Matrix3& operator-=(const Matrix3& other);

    /**
     * @brief Operator to multiply a matrix by a scalar
     * @param scalar The scalar to multiply by
     * @return The result of the multiplication
     */
    Matrix3 operator*(float scalar) const;

    /**
     * @brief Operator to multiply the current matrix by a scalar
     * @param scalar The scalar to multiply by
     * @return The current matrix
     */
    Matrix3& operator*=(float scalar);

    /**
     * @brief Operator to multiply a matrix by a vector
     * @param vec The vector to multiply by
     * @return The result of the multiplication
     */
    Vector3 operator*(const utils::Vector3& vec) const;

    /**
     * @brief Operator to multiply two matrices
     * @param other The matrix to multiply by
     * @return The result of the multiplication
     */
    Matrix3 operator*(const Matrix3& other) const;

    /**
     * @brief Operator to compare two matrices
     * @param other The other matrix
     * @return True if the matrices are equal, false otherwise
     */
    bool operator==(const Matrix3& other) const;

    /**
     * @brief Operator to compare two matrices
     * @param other The other matrix
     * @return True if the matrices are different, false otherwise
     */
    bool operator!=(const Matrix3& other) const;

    /**
     * @brief Operator to negate a matrix
     * @return The negated matrix
     */
    Matrix3 operator-() const;


    /**
     * @brief Computes the determinant of the matrix
     * @return The determinant of the matrix
     */
    float determinant() const;

    /**
     * @brief Transposes the matrix
     * @return The transposed matrix
     */
    Matrix3 transpose() const;

    /**
     * @brief Computes the inverse of the matrix
     * @return The inverse of the matrix
     */
    Matrix3 inverse() const;

    /**
     * @brief Computes the trace of the matrix
     * @return The trace of the matrix
     */
    float trace() const;
};

} // namespace utils

#endif // MATRIX3_H