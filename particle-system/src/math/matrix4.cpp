#include "matrix4.h"

Matrix4::Matrix4(void) {
    toIdentity();
}

Matrix4::Matrix4(float elements[16]) {
	memcpy(this->array, elements, 16 * sizeof(float));
}

Matrix4::~Matrix4(void)	{
    toIdentity();
}

void Matrix4::toIdentity() {
    toZero();

	array[0]  = 1.0f;
	array[5]  = 1.0f;
	array[10] = 1.0f;
	array[15] = 1.0f;
}

Matrix4& Matrix4::operator=(const Matrix4 &a) {
	if(this != &a) {
		for(int i = 0; i < 16; i++) {
			array[i] = a.array[i];
		}
	}
	
	return *this;
}


void Matrix4::toZero() {
	for(int i = 0; i < 16; i++) {
		array[i] = 0.0f;
	}
}

Vec3 Matrix4::getPositionVector() const {
	return Vec3(array[12], array[13], array[14]);
}

void Matrix4::setPositionVector(const Vec3 in) {
	array[12] = in.x;
	array[13] = in.y;
	array[14] = in.z;		
}

Vec3 Matrix4::getScalingVector() const{
	return Vec3(array[0], array[5], array[10]);
}

void Matrix4::setScalingVector(const Vec3 &in) {
	array[0]  = in.x;
	array[5]  = in.y;
	array[10] = in.z;		
}

Matrix4 Matrix4::identity() {
	Matrix4 m;

    m.toIdentity();
	return m;
}

Matrix4 Matrix4::createPerspective(float znear, float zfar, float aspect, float fov) {
	Matrix4 m;

	const float h = 1.0f / tan(fov * PI_360);
    float negDepth = znear-zfar;

	m.array[0]	 = h / aspect;
	m.array[5]	 = h;
    m.array[10] = (zfar+znear) / negDepth;
	m.array[11] = -1.0f;
    m.array[14] = 2.0f * (znear*zfar) / negDepth;
	m.array[15] = 0.0f;

	return m;
}

Matrix4 Matrix4::createOrthographic(float znear, float zfar,float right, float left, float top, float bottom) {
	Matrix4 m;

	m.array[0]	 = 2.0f / (right-left);
	m.array[5]	 = 2.0f / (top-bottom);
	m.array[10] = -2.0f / (zfar-znear);

	m.array[12]  = -(right+left) / (right-left);
	m.array[13]  = -(top+bottom) / (top-bottom);
	m.array[14]  = -(zfar+znear) / (zfar-znear);
	m.array[15]  = 1.0f;

	return m;
}

Matrix4 Matrix4::createLookAt(const Vec3 &from, const Vec3 &lookingAt) {
	Matrix4 r;
	Matrix4 m;
	Vec3 f = (lookingAt - from);
    Vec3 up = Vec3::up();

    r.setPositionVector(Vec3(-from.x, -from.y, -from.z));
    f.normalize();

    Vec3 s = f.cross(up);
    Vec3 u = s.cross(f);

	m.array[0] = s.x;
	m.array[4] = s.y;
	m.array[8] = s.z;

	m.array[1] = u.x;
	m.array[5] = u.y;
	m.array[9] = u.z;

	m.array[2]  = -f.x;
	m.array[6]  = -f.y;
	m.array[10] = -f.z;

	return m*r;
}

Matrix4 Matrix4::createRotation(float degrees, const Vec3 &inaxis) {
	Matrix4 m;

	Vec3 axis = inaxis;

    axis.normalize();

    float c = cos((float)radians(degrees));
    float s = sin((float)radians(degrees));

	m.array[0]  = (axis.x * axis.x) * (1.0f - c) + c;
	m.array[1]  = (axis.y * axis.x) * (1.0f - c) + (axis.z * s);
	m.array[2]  = (axis.z * axis.x) * (1.0f - c) - (axis.y * s);

	m.array[4]  = (axis.x * axis.y) * (1.0f - c) - (axis.z * s);
	m.array[5]  = (axis.y * axis.y) * (1.0f - c) + c;
	m.array[6]  = (axis.z * axis.y) * (1.0f - c) + (axis.x * s);

	m.array[8]  = (axis.x * axis.z) * (1.0f - c) + (axis.y * s);
	m.array[9]  = (axis.y * axis.z) * (1.0f - c) - (axis.x * s);
	m.array[10] = (axis.z * axis.z) * (1.0f - c) + c;

	return m;
}

Matrix4 Matrix4::createScale(const Vec3 &scale) {
	Matrix4 m;

	m.array[0]  = scale.x;
	m.array[5]  = scale.y;
	m.array[10] = scale.z;	

	return m;
}

Matrix4 Matrix4::createTranslation(const Vec3 &translation) {
	Matrix4 m;

	m.array[12] = translation.x;
	m.array[13] = translation.y;
	m.array[14] = translation.z;	

	return m;
}
