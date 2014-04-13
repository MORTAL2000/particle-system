#ifndef __MATRIX3_H__
#define __MATRIX3_H__

#include "matrix4.h"

class Matrix3 {
	public:
	    union
	    {
	        float data[3][3];
	        float array[9];
	    };

	    Matrix3();
		Matrix3(float elements[9]);

        void transpose();
        void toIdentity();
        void toZero();

        static Matrix3 identity();
        static Matrix3 getInverse(const Matrix4& m);
};

#endif
