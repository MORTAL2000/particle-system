#include "scenenode.h"

SceneNode::SceneNode()
{
    this->needUpdate = true;
}

SceneNode::SceneNode(Vec3 position, Quaternion orientation) : position(position), orientation(orientation)
{
    this->needUpdate = true;
}

SceneNode::~SceneNode()
{

}

void SceneNode::setPosition(Vec3 position)
{
	this->position = position;
    this->needUpdate = true;
}

Vec3 SceneNode::getPosition()
{
	return this->position;
}

void SceneNode::rotate(float angle, const Vec3& axis) {
    Quaternion q(angle, axis);
    orientation = orientation * q;
    needUpdate = true;
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

void SceneNode::setOrientation(Quaternion orientation)
{
	this->orientation = orientation;
    this->needUpdate = true;
}

Quaternion SceneNode::getOrientation()
{
	return this->orientation;
}

Matrix4 SceneNode::getRotationMatrix()
{
    if(needUpdate) {
        rotationMatrix = Matrix4::createRotation(orientation);
    }
    return rotationMatrix;
}

Matrix4 SceneNode::getTranslationMatrix()
{
    if(needUpdate) {
        translationMatrix = Matrix4::createTranslation(-position);
    }
    return translationMatrix;
}
