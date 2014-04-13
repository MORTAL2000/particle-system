#ifndef QUATERNION_H
#define QUATERNION_H

#include <cmath>

class Quaternion
{
public:
    float x, y, z, w;
    Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
    Quaternion(Quaternion &q);
    Quaternion operator*(Quaternion &q);
    Quaternion& divideByScalar(float scalar);
    Quaternion operator/(float scalar);
    Quaternion conjugate();
    Quaternion& normalize();
    float length();
};

#endif // QUATERNION_H
