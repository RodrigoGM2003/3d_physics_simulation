#include <math.h>
#include <stdexcept>

#include "utils/vector3.h"

utils::Vector3::Vector3() : x(0), y(0), z(0) {}
utils::Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

utils::Vector3 utils::Vector3::normalize() const {
    float len = length();

    if (len > 0) 
        return Vector3(x / len, y / len, z / len);
    
    return *this;
}

utils::Vector3 utils::Vector3::operator+(const utils::Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

utils::Vector3 utils::Vector3::operator-(const utils::Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

utils::Vector3 utils::Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

float utils::Vector3::dot(const utils::Vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

utils::Vector3 utils::Vector3::cross(const utils::Vector3& other) const {
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}


bool utils::Vector3::operator==(const utils::Vector3& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool utils::Vector3::operator!=(const utils::Vector3& other) const {
        return !(*this == other);
}

utils::Vector3 utils::Vector3::operator-() const {
    return Vector3(-x, -y, -z);
}

utils::Vector3& utils::Vector3::operator+=(const utils::Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

utils::Vector3& utils::Vector3::operator-=(const utils::Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

utils::Vector3& utils::Vector3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

float utils::Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

float utils::Vector3::lengthSquared() const {
    return x * x + y * y + z * z;
}

utils::Vector3 utils::Vector3::operator/(float scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
        return *this;
    }
    return Vector3(x / scalar, y / scalar, z / scalar);
}

utils::Vector3& utils::Vector3::operator/=(float scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero");
        return *this;
    }
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

bool utils::Vector3::isZero() const {
    return x == 0 && y == 0 && z == 0;
}

float utils::Vector3::distance(const utils::Vector3& a, const utils::Vector3& b) {
    return (a - b).length();
}