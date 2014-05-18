#include "scenenode.h"

SceneNode::SceneNode()
{}

SceneNode::SceneNode(Vec3 position, Quaternion orientation) : position(position), orientation(orientation)
{}

SceneNode::~SceneNode()
{}

void SceneNode::setPosition(Vec3 position)
{
	this->position = position;
}

Vec3 SceneNode::getPosition()
{
	return this->position;
}

void SceneNode::rotate(float angle, const Vec3& axis) {
    Quaternion q(angle, axis);
    orientation = orientation * q;
}

void SceneNode::rotateX(float angle) {
    Vec3 xAxis(1, 0, 0);
    rotate(angle, xAxis);
}

void SceneNode::rotateY(float angle) {
    Vec3 yAxis(0, 1, 0);
    rotate(angle, yAxis);
}

void SceneNode::rotateZ(float angle) {
    Vec3 zAxis(0, 0, 1);
    rotate(angle, zAxis);
}

void SceneNode::translateX(float value) {
    Matrix4 t = Matrix4::createTranslation(Vec3(value, 0.0, 0.0));
    position = t * position;
}

void SceneNode::translateY(float value) {
    Matrix4 t = Matrix4::createTranslation(Vec3(0.0, value, 0.0));
    position = t * position;
}

void SceneNode::translateZ(float value) {
    Matrix4 t = Matrix4::createTranslation(Vec3(0.0, 0.0, value));
    position = t * position;
}

void SceneNode::setOrientation(Quaternion orientation)
{
    this->orientation = orientation;
}

Quaternion SceneNode::getOrientation()
{
	return this->orientation;
}

Matrix4 SceneNode::getRotationMatrix()
{
    rotationMatrix = Matrix4::createRotation(orientation);
    return rotationMatrix;
}

Matrix4 SceneNode::getTranslationMatrix()
{
    translationMatrix = Matrix4::createTranslation(-position);
    return translationMatrix;
}
