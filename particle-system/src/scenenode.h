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

        void rotateX(float angle);
        void rotateY(float angle);
        void rotateZ(float angle);
        void translateX(float value);
        void translateY(float value);
        void translateZ(float value);
        void translate(const Vec3& translation);
        void rotate(float angle, const Vec3& axis);

    protected:
        Matrix4 rotationMatrix;
        Matrix4 translationMatrix;
        Matrix4 getRotationMatrix();
        Matrix4 getTranslationMatrix();
        Vec3 position;
		Quaternion orientation;
};

#endif // SCENENODE_H
