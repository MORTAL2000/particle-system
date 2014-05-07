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
	orientation.x = direction.x;
	orientation.y = direction.y;
	orientation.z = direction.z;
}

void Camera::buildViewMatrix()
{
	// Vertical axis of the camera
	//TODO calculate / set this axis somewhere
	Vec3 up;
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;
	up.normalize();

	Vec3 forward;
	forward.x = orientation.x - position.x;
	forward.y = orientation.y - position.y;
	forward.z = orientation.z - position.z;
	forward.normalize();

	Vec3 s = forward.cross(up);
	Vec3 u = s.cross(forward);

	viewMatrix.array[0]  = s.x;		   viewMatrix.array[1]  = s.y;		  viewMatrix.array[2]  = s.z;        viewMatrix.array[3]  = 0.0f;
	viewMatrix.array[4]  = u.x;		   viewMatrix.array[5]  = u.y;		  viewMatrix.array[6]  = u.z;        viewMatrix.array[7]  = 0.0f;
	viewMatrix.array[8]  = -forward.x; viewMatrix.array[9]  = -forward.y; viewMatrix.array[10] = -forward.z; viewMatrix.array[11] = 0.0f;
	viewMatrix.array[12] = 0.0f;	   viewMatrix.array[13] = 0.0f;		  viewMatrix.array[14] = 0.0f;		 viewMatrix.array[15] = 1.0f;

	Matrix4 t;
	t.identity();
	t.array[3]  = -position.x;
	t.array[7]  = -position.y;
	t.array[11] = -position.z;

	viewMatrix = viewMatrix * t;
}

void Camera::buildProjectionMatrix()
{
	float r, l, t, b, theta, width, height, depth;

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
	projectionMatrix.array[14] = -1;
}
