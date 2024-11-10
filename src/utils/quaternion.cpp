#include "utils/quaternion.h"
#include "utils/matrix3.h"
#include "utils/utils.h"


namespace utils {


Quaternion Quaternion::fromAxisAngleRads(const Vector3& axis, float angle) {
    float halfAngle = angle * 0.5f;
    float sinHalfAngle = sin(halfAngle);
    return Quaternion(cos(halfAngle), axis.x * sinHalfAngle, axis.y * sinHalfAngle, axis.z * sinHalfAngle);
}

Quaternion Quaternion::fromAxisAngleDeg(const Vector3& axis, float angle) {
    angle = utils::deg2rad(angle);
    return fromAxisAngleRads(axis, angle); 
}

Quaternion Quaternion::fromTwoVectors(const Vector3& from, const Vector3& to) {
    Vector3 f = from.normalize();
    Vector3 t = to.normalize();
    Vector3 crossProd = f.cross(t);
    float dotProd = f.dot(t);
    float w = sqrt(from.lengthSquared() * to.lengthSquared()) + dotProd;
    return Quaternion(w, crossProd.x, crossProd.y, crossProd.z).normalize();
}

Quaternion Quaternion::normalize() const {
    float len = sqrt(w * w + x * x + y * y + z * z);
    return Quaternion(w / len, x / len, y / len, z / len);
}

void Quaternion::inPlaceNormalize() {
    float len = sqrt(w * w + x * x + y * y + z * z);
    if (len > 0) {
        w /= len;
        x /= len;
        y /= len;
        z /= len;
    }
}
Quaternion Quaternion::inverse() const {
    float normSq = w * w + x * x + y * y + z * z;

    if (normSq > 0) 
        return conjugate() * (1.0f / normSq);
    
    return *this; 
}

float Quaternion::dot(const Quaternion& other) const {
    return w * other.w + x * other.x + y * other.y + z * other.z;
}

Matrix3 Quaternion::toMatrix() const {
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

Quaternion Quaternion::operator*(const Quaternion& other) const {
    return Quaternion(
        w * other.w - x * other.x - y * other.y - z * other.z,
        w * other.x + x * other.w + y * other.z - z * other.y,
        w * other.y - x * other.z + y * other.w + z * other.x,
        w * other.z + x * other.y - y * other.x + z * other.w
    );
}

Quaternion Quaternion::operator*(float scalar) const {
    return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
}

Quaternion Quaternion::operator+(const Quaternion& other) const {
    return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
}


Quaternion Quaternion::operator-(const Quaternion& other) const {
    return Quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
}

bool Quaternion::operator==(const Quaternion& other) const {
    return w == other.w && x == other.x && y == other.y && z == other.z;
}

bool Quaternion::operator!=(const Quaternion& other) const {
    return !(*this == other);
}

Vector3 Quaternion::rotate(const Vector3& vec) const {
    Quaternion vecQuat(0, vec.x, vec.y, vec.z);
    Quaternion result = (*this) * vecQuat * conjugate();
    return Vector3(result.x, result.y, result.z);
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(w, -x, -y, -z);
}

const Quaternion Quaternion::Identity(1, 0, 0, 0);

}