#ifndef __VECTOR_3__
#define __VECTOR_3__

#include <Math/Vector2.hpp>

using Vector3 = struct Vector3;

struct Vector3{
	double x{0};
	double y{0};
	double z{0};

	Vector3(const double x, const double y, const double z);
	Vector3(const Vector2 position_2d, const double z);
	Vector3(const Vector3 &other);

	Vector3 dotProduct(const Vector3 &other) const;

	Vector3 operator -(const Vector3 &other) const;
	Vector3 operator +(const Vector3 &other) const;
	double operator *(const Vector3 &other) const;
	Vector3 operator*(const double a) const;
	Vector3 operator/(const double a) const;
};
#endif
