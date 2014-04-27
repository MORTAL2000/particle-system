#ifndef SCENENODE_H
#define SCENENODE_H

#include "math/matrix4.h"

class SceneNode
{
	public:
		SceneNode();
        SceneNode(Vec3 position, Quaternion orientation);
        virtual ~SceneNode();

		// Position
        void setPosition(Vec3 position);
        Vec3 getPosition();

		// Orientation
		void setOrientation(Quaternion orientation);
		Quaternion getOrientation();

	protected:
        Matrix4 getRotationMatrix() const;
        Matrix4 getTranslationMatrix() const;

	private:
        Vec3 position;
		Quaternion orientation;
};

#endif // SCENENODE_H
