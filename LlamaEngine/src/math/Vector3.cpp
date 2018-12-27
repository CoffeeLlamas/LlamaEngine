#include "Vector3.hpp"
#include <cmath>
namespace engine {
	namespace math {

		Vector3::Vector3() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		Vector3 Vector3::normalize() {
			return Vector3::normalize(*this);
		}

		Vector3 Vector3::normalize(Vector3 vec) {
			float m = Vector3::magnitude(vec);
			Vector3 vector = Vector3::identity();
			vector.x = vec.x / m;
			vector.y = vec.y / m;
			vector.z = vec.z / m;
			return vector;
		}

		float Vector3::magnitude() {
			return Vector3::magnitude(*this);
		}

		float Vector3::magnitude(Vector3 vec) {
			return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		}

		Vector3 Vector3::set(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
			return *this;
		}

		Vector3 Vector3::set(Vector3 vec) {
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
			return *this;
		}

		Vector3 Vector3::clone() {
			Vector3 vector = Vector3::identity();
			vector.x = this->x;
			vector.y = this->y;
			vector.z = this->z;
			return vector;
		}

		Vector3 Vector3::identity() {
			return Vector3();
		}

		Vector3 Vector3::operator+(Vector3 b) {
			Vector3 vector = Vector3::identity();
			vector.x = this->x + b.x;
			vector.y = this->y + b.y;
			vector.z = this->z + b.z;
			return vector;
		}

		Vector3 Vector3::operator-(Vector3 b) {
			Vector3 vector = Vector3::identity();
			vector.x = this->x - b.x;
			vector.y = this->y - b.y;
			vector.z = this->z - b.z;
			return vector;
		}

		Vector3 Vector3::operator*(float b) {
			return this->scalar(b);
		}

		float Vector3::operator*(Vector3 vec) {
			return this->dot(vec);
		}

		Vector3 Vector3::operator+=(Vector3 b) {
			this->x += + b.x;
			this->y += b.y;
			this->z += b.z;
			return *this;
		}

		Vector3 Vector3::operator-=(Vector3 b) {
			this->x -= b.x;
			this->y -= b.y;
			this->z -= b.z;
			return *this;
		}

		Vector3 Vector3::operator*=(float b) {
			this->set(this->scalar(b));
			return *this;
		}

		float Vector3::operator*(Vector3 vec) {
			return this->dot(vec);
		}

		bool Vector3::operator==(Vector3 b) {
			return (this->x == b.x && this->y == b.y && this->z == b.z);
		}

		bool Vector3::operator!=(Vector3 b) {
			return !(*this == b);
		}

		float Vector3::dot(Vector3 other) {
			return Vector3::dot(*this, other);
		}

		float Vector3::dot(Vector3 vec, Vector3 vec2) {
			return vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z;
		}

		Vector3 Vector3::scalar(float s) {
			return Vector3::scalar(*this, s);
		}

		Vector3 Vector3::scalar(Vector3 vec, float s) {
			Vector3 vector = Vector3::identity();
			vector.x = vec.x * s;
			vector.y = vec.y * s;
			vector.z = vec.z * s;
			return vector;
		}
	}
}