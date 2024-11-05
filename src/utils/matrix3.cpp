#include <cmath>
#include <iostream>
#include <stdexcept>
#include "utils/vector3.h" // Assume you have a Vector3 class
#include "utils/matrix3.h"
#include "utils/utils.h"


namespace utils {

Matrix3 Matrix3::identity() {
    Matrix3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = (i == j) ? 1.0f : 0.0f;
    return result;
}

Matrix3 Matrix3::rotationX(float angle) {
    float radians = utils::deg2rad(angle);

    float c = std::cos(radians);
    float s = std::sin(radians);
    Matrix3 result;
    result.m[0][0] = 1.0f;
    result.m[1][1] = c; result.m[1][2] = -s;
    result.m[2][1] = s; result.m[2][2] = c;
    return result;
}

Matrix3 Matrix3::rotationY(float angle) {
    float radians = utils::deg2rad(angle);

    float c = std::cos(radians);
    float s = std::sin(radians);
    Matrix3 result;
    result.m[0][0] = c; result.m[0][2] = s;
    result.m[1][1] = 1.0f;
    result.m[2][0] = -s; result.m[2][2] = c;
    return result;
}

Matrix3 Matrix3::rotationZ(float angle) {
    float radians = utils::deg2rad(angle);

    float c = std::cos(radians);
    float s = std::sin(radians);
    Matrix3 result;
    result.m[0][0] = c; result.m[0][1] = -s;
    result.m[1][0] = s; result.m[1][1] = c;
    result.m[2][2] = 1.0f;
    return result;
}

Matrix3 Matrix3::scaling(float scaleX, float scaleY, float scaleZ) {
    Matrix3 result;
    result.m[0][0] = scaleX;
    result.m[1][1] = scaleY;
    result.m[2][2] = scaleZ;
    return result;
}

Matrix3::Matrix3() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] = (i == j) ? 1.0f : 0.0f;
}

Matrix3::Matrix3(float values[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] = values[i][j];
}

Matrix3 Matrix3::operator+(const Matrix3& other) const {
    Matrix3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = m[i][j] + other.m[i][j];
    return result;
}

Matrix3& Matrix3::operator+=(const Matrix3& other) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] += other.m[i][j];
    return *this;
}

Matrix3 Matrix3::operator-(const Matrix3& other) const {
    Matrix3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = m[i][j] - other.m[i][j];
    return result;
}

Matrix3& Matrix3::operator-=(const Matrix3& other) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] -= other.m[i][j];
    return *this;
}

Matrix3 Matrix3::operator*(float scalar) const {
    Matrix3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = m[i][j] * scalar;
    return result;
}

Matrix3& Matrix3::operator*=(float scalar) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] *= scalar;
    return *this;
}

Vector3 Matrix3::operator*(const Vector3& vec) const {
    return Vector3(
        m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z,
        m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z,
        m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z
    );
}

Matrix3 Matrix3::operator*(const Matrix3& other) const {
    Matrix3 result;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.m[i][j] = m[i][0] * other.m[0][j] +
                             m[i][1] * other.m[1][j] +
                             m[i][2] * other.m[2][j];
        }
    }
    return result;
}

bool Matrix3::operator==(const Matrix3& other) const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (m[i][j] != other.m[i][j])
                return false;
    return true;
}

bool Matrix3::operator!=(const Matrix3& other) const {
    return !(*this == other);
}

Matrix3 Matrix3::operator-() const {
    Matrix3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = -m[i][j];
    return result;
}

float Matrix3::determinant() const {
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
            - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
            + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

Matrix3 Matrix3::transpose() const {
    Matrix3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = m[j][i];
    return result;
}

Matrix3 Matrix3::inverse() const {
    float det = determinant();
    if (std::abs(det) < 1e-6) {
        throw std::runtime_error("Matrix is not invertible");
    }
    Matrix3 result;
    result.m[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
    result.m[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
    result.m[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
    result.m[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
    result.m[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    result.m[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
    result.m[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
    result.m[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
    result.m[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;
    return result;
}

float Matrix3::trace() const {
    return m[0][0] + m[1][1] + m[2][2];
}

}; // namespace utils

