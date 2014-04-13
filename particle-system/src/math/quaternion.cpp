#include "quaternion.h"

Quaternion::Quaternion(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Quaternion::Quaternion(Quaternion &q) {
    x = q.x;
    y = q.y;
    z = q.z;
    w = q.w;
}

Quaternion Quaternion::operator*(Quaternion &q1) {
    Quaternion q2(*this);
    q2.w = q1.w*w - q1.x*x - q1.y*y - q1.z*z;
    q2.x = q1.w*x + q1.x*w + q1.y*z - q1.z*y;
    q2.y = q1.w*y - q1.x*z + q1.y*w + q1.z*x;
    q2.z = q1.w*z + q1.x*y - q1.y*x + q1.z*w;
    return q2;
}

Quaternion Quaternion::operator/(float scalar) {
    Quaternion q(*this);
    q.divideByScalar(scalar);
    return q;
}

Quaternion& Quaternion::divideByScalar(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
    return *this;
}

Quaternion& Quaternion::normalize() {
    return this->divideByScalar(length());
}

float Quaternion::length() {
    return sqrt(w*w + x*x + y*y + z*z);
}

Quaternion Quaternion::conjugate() {
    Quaternion q(*this);
    q.x = -q.x;
    q.y = -q.y;
    q.z = -q.z;
    return q;
}
