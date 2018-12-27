#pragma once
#include "Vector3.hpp"
namespace engine {
	namespace math {
		
		class Matrix4 {
		public:
			float m[16];
			static Matrix4 identity();
			Matrix4 setTranslation(engine::math::Vector3 pos);
			Matrix4 setRotation(engine::math::Vector3 rot);
			Matrix4 setScale(engine::math::Vector3 scale);
			Matrix4 inverse();
			Matrix4 clone();
			static Matrix4 setTranslation(Matrix4 matrix, Vector3 pos);
			static Matrix4 setRotation(Matrix4 matrix, Vector3 rot);
			static Matrix4 setScale(Matrix4 matrix, Vector3 scale);
			static Matrix4 inverse(Matrix4 matrix);
		private:
			Matrix4();
		};

	}
}
