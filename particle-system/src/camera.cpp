#include "camera.h"

Camera::Camera()
{
}

Camera::Camera(Vec3 position, Quaternion orientation, float aspectRatio, float fovAngle, float nearPlane, float farPlane)
    : SceneNode(position, orientation)
{
	this->aspectRatio = aspectRatio;
	this->fovAngle = fovAngle;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
}

Camera::~Camera()
{

}

Matrix4 Camera::getViewMatrix()
{
    if(needUpdate) {
        buildViewMatrix();
    }
	return this->viewMatrix;
}

Matrix4 Camera::getProjectionMatrix()
{
    if(needUpdate) {
        buildProjectionMatrix();
    }
	return this->projectionMatrix;
}

void Camera::setAspectRatio(float ratio)
{
	this->aspectRatio = ratio;
    needUpdate = true;
}

void Camera::setFOV(float angle)
{
	this->fovAngle = angle;
    needUpdate = true;
}

void Camera::setPlanes(float near, float far)
{
	this->nearPlane = near;
	this->farPlane = far;
    needUpdate = true;
}

void Camera::lookAt(Vec3 direction)
{
    // TODO : to remove
	orientation.x = direction.x;
	orientation.y = direction.y;
	orientation.z = direction.z;
    needUpdate = true;
}

Vec3 Camera::up() {
    Vec3 up = Matrix3::getInverse(getRotationMatrix()) * Vec3(0, 1, 0);
    return up;
}

Vec3 Camera::right() {
    Vec3 right = Matrix3::getInverse(getRotationMatrix()) * Vec3(1, 0, 0);
    return right;
}

Vec3 Camera::forward() {
    Vec3 forward = Matrix3::getInverse(getRotationMatrix()) * Vec3(0, 0, -1);
    return forward;
}

void Camera::buildViewMatrix()
{
    Matrix4 view = Matrix4::createView(up(), right(), forward());
    Vec3 p = view * getPosition();
    setPosition(p);
    viewMatrix = view * getTranslationMatrix();
}

void Camera::buildProjectionMatrix()
{
    float r, l, t, b, theta;
    theta = (M_PI * fovAngle / 180.0f) / 2;
    r = nearPlane * tan(theta);
    l = -r;
    t = r * aspectRatio;
    b = -t;

    projectionMatrix = Matrix4::createOrthographic(nearPlane, farPlane, r, l, t, b);

    /*float r, l, t, b, theta, width, height, depth;

	theta = (M_PI * fovAngle / 180.0f) / 2;
	r = nearPlane * tan(theta);
	l = -r;
	t = r * aspectRatio;
	b = -t;
	width = r - l;
	height = t - b;
	depth = farPlane - nearPlane;

	projectionMatrix.toZero();
	projectionMatrix.array[0] = (2 * nearPlane) / width;
	projectionMatrix.array[2] = (r + l) / width;
	projectionMatrix.array[5] = (2 * nearPlane) / height;
	projectionMatrix.array[6] = (t + b) / height;
	projectionMatrix.array[10] = - (farPlane + nearPlane) / depth;
	projectionMatrix.array[11] = - (2 * nearPlane * farPlane) / depth;
    projectionMatrix.array[14] = -1;*/
}
