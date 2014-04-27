#include "camera.h"

Camera::Camera()
{
}

Camera::Camera(Vec3 position, Vec3 rotation, float aspectRatio, float fovAngle, float nearPlane, float farPlane)
{
}

Camera::~Camera()
{

}

Matrix4 Camera::getViewMatrix()
{
	buildViewMatrix();
	return this->viewMatrix;
}

Matrix4 Camera::getProjectionMatrix()
{
	buildProjectionMatrix();
	return this->projectionMatrix;
}

void Camera::setAspectRatio(float ratio)
{
	this->aspectRatio = ratio;
}

void Camera::setFOV(float angle)
{
	this->fovAngle = angle;
}

void Camera::setPlanes(float near, float far)
{
	this->nearPlane = near;
	this->farPlane = far;
}

void Camera::lookAt(Vec3 direction)
{

}

void Camera::buildViewMatrix()
{

}

void Camera::buildProjectionMatrix()
{

}
