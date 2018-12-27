#pragma once
namespace engine {
	namespace math {

		class Vector3 {
		public:
			float x, y, z;
			Vector3 normalize();
			Vector3 clone();
			Vector3 set(float x, float y, float z);
			Vector3 set(Vector3 vec);
			float magnitude();
			float dot(Vector3 other);
			Vector3 scalar(float s);
			static Vector3 normalize(Vector3 vector);
			static float magnitude(Vector3 vector);
			static float dot(Vector3 vec, Vector3 vec2);
			static Vector3 scalar(Vector3 vec, float s);
			static Vector3 identity();

			Vector3 operator+(Vector3 a);
			Vector3 operator-(Vector3 a);
			Vector3 operator*(float a);
			float operator*(Vector3 a);

			Vector3 operator+=(Vector3 a);
			Vector3 operator-=(Vector3 a);
			Vector3 operator*=(float a);

			bool operator==(Vector3 a);
			bool operator!=(Vector3 a);
		private:
			Vector3();
		};

	}
}