#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>


namespace utils{
/**
 * @brief A class representing a 3D vector
 */
class Vector3 {
public:
    /**
     * @brief The x, y and z components of the vector
     */
    float x, y, z;

    static inline Vector3 zero() { return Vector3(0, 0, 0); }

    /**
     * @brief Default constructor
     */
    Vector3();

    /**
     * @brief Constructor with parameters
     * @param x The x component of the vector
     * @param y The y component of the vector
     * @param z The z component of the vector
     */
    Vector3(float x, float y, float z);

    /**
     * @brief Copy constructor
     * @param other The vector to copy
     * @return The vectors length
     */
    float length() const;


    /**
     * @brief Computes the squared length of the vector
     * @return The squared length of the vector
     */
    float lengthSquared() const;

    /**
     * @brief Checks if the vector is the zero vector
     * @return True if the vector is the zero vector, false otherwise
     */
    bool isZero() const;

    /**
     * @brief Normalizes the vector
     * @return The normalized vector
     */
    Vector3 normalize() const;

    /**
     * @brief Operator to add two vectors
     * @param other The vector to add
     * @return The result of the addition
     */
    Vector3 operator+(const Vector3& other) const;

    /**
     * @brief Operator to subtract two vectors
     * @param other The vector to subtract
     * @return The result of the subtraction
     */
    Vector3 operator-(const Vector3& other) const;

    /**
     * @brief Operator to multiply a vector by a scalar
     * @param scalar The scalar to multiply by
     * @return The result of the multiplication
     */
    Vector3 operator*(float scalar) const;

    /**
     * @brief Computes the dot product of two vectors
     * @param other The other vector
     * @return The dot product of the two vectors
     */
    float dot(const Vector3& other) const;

    /**
     * @brief Computes the cross product of two vectors
     * @param other The other vector
     * @return The cross product of the two vectors
     */
    Vector3 cross(const Vector3& other) const;

    /**
     * @brief Operator to compare two vectors
     * @param other The other vector
     * @return True if the vectors are equal, false otherwise
     */
    bool operator==(const Vector3& other) const;

    /**
     * @brief Operator to compare two vectors
     * @param other The other vector
     * @return True if the vectors are different, false otherwise
     */
    bool operator!=(const Vector3& other) const;

    /**
     * @brief Operator to negate a vector
     * @return The negated vector
     */
    Vector3 operator-() const;

    /**
     * @brief Combined operator to add two vectors
     * @param other The vector to add
     * @return The result of the addition
     */
    Vector3& operator+=(const Vector3& other);

    /**
     * @brief Combined operator to subtract two vectors
     * @param other The vector to subtract
     * @return The result of the subtraction
     */
    Vector3& operator-=(const Vector3& other);

    /**
     * @brief Combined operator to multiply a vector by a scalar
     * @param scalar The scalar to multiply by
     * @return The result of the multiplication
     */
    Vector3& operator*=(float scalar);
    
    /**
     * @brief Operator to divide a vector by a scalar
     * @param scalar The scalar to divide by
     * @return The result of the division
     */
    Vector3 operator/(float scalar) const;


    /**
     * @brief Combined operator to divide a vector by a scalar
     * @param scalar The scalar to divide by
     * @return The result of the division
     */
    Vector3& operator/=(float scalar);


    /**
     * @brief Computes the distance between two vectors
     * @param a The first vector
     * @param b The second vector
     * @return The distance between the two vectors
     */
    static float distance(const Vector3& a, const Vector3& b);
    

    /**
     * @brief Prints the vector to an output stream
     * @param os The output stream
     * @param v The vector to print
     * @return The output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
        
};
}


#endif