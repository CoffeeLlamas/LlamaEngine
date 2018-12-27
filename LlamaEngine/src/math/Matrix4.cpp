#include "Matrix4.hpp"
#include "Vector3.hpp"
#include <cmath>
namespace engine {
	namespace math {

		Matrix4::Matrix4() {
			for (int i = 0; i < 16; i++)
				if (i % 5 == 0)
					this->m[i] = 1;
				else
					this->m[i] = 0;
		}

		Matrix4 Matrix4::identity() {
			return Matrix4();
		}

		Matrix4 Matrix4::clone() {
			Matrix4 matrix = Matrix4::identity();
			for (int i = 0; i < 16; i++)
				matrix.m[i] = this->m[i];
			return matrix;
		}

		Matrix4 Matrix4::setTranslation(Vector3 pos) {
			return Matrix4::setTranslation(*this, pos);
		}

		Matrix4 Matrix4::setTranslation(Matrix4 matrix, Vector3 pos) {
			matrix = matrix.clone();
			matrix.m[12] = pos.x;
			matrix.m[13] = pos.y;
			matrix.m[14] = pos.z;
			return matrix;
		}

		Matrix4 Matrix4::setRotation(Vector3 rot) {
			return Matrix4::setRotation(*this, rot);
		}

		Matrix4 Matrix4::setRotation(Matrix4 matrix, Vector3 rot) {
			matrix = matrix.clone();
			matrix.m[0] = cos(rot.y) + cos(rot.z);
			matrix.m[1] = sin(rot.z);
			matrix.m[2] = -sin(rot.y);

			matrix.m[4] = -sin(rot.z);
			matrix.m[5] = cos(rot.x) + cos(rot.z);
			matrix.m[6] = sin(rot.x);

			matrix.m[8] = sin(rot.y);
			matrix.m[9] = -sin(rot.x);
			matrix.m[10] = cos(rot.x) + cos(rot.y);
			return matrix;
		}

		Matrix4 Matrix4::setScale(Vector3 scale) {
			return Matrix4::setScale(*this, scale);
		}

		Matrix4 Matrix4::setScale(Matrix4 matrix, Vector3 scale) {

		}

	}
}