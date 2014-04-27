#include "scenenode.h"

SceneNode::SceneNode()
{
}

SceneNode::SceneNode(Vec3 position, Quaternion orientation) : position(position), orientation(orientation)
{}

SceneNode::~SceneNode()
{

}

void SceneNode::setPosition(Vec3 position)
{
	this->position = position;
}

Vec3 SceneNode::getPosition()
{
	return this->position;
}

void SceneNode::setOrientation(Quaternion orientation)
{
	this->orientation = orientation;
}

Quaternion SceneNode::getOrientation()
{
	return this->orientation;
}

Matrix4 SceneNode::getRotationMatrix() const
{
    return Matrix4::createRotation(orientation);
}

Matrix4 SceneNode::getTranslationMatrix() const
{
    return Matrix4::createTranslation(-position);
}
