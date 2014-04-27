#ifndef SCENENODE_H
#define SCENENODE_H

#include "math/matrix4.h"

class SceneNode
{
	public:
		SceneNode();
		SceneNode(Vec4 position, Quaternion orientation);
		virtual ~SceneNode();

		// Position
		void setPosition(Vec4 position);
		Vec4 getPosition();

		// Orientation
		void setOrientation(Quaternion orientation);
		Quaternion getOrientation();

	protected:
		virtual Matrix4 getRotationMatrix() = 0;
		virtual Matrix4 getTranslationMatrix() = 0;

	private:
		Vec4 position;
		Quaternion orientation;
};

#endif // SCENENODE_H
