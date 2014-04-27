#include "scenenode.h"

SceneNode::SceneNode()
{
}

SceneNode::SceneNode(Vec4 position, Quaternion orientation) : position(position), orientation(orientation)
{}

SceneNode::~SceneNode()
{

}

void SceneNode::setPosition(Vec4 position)
{
	this->position = position;
}

Vec4 SceneNode::getPosition()
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
