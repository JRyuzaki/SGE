#ifndef __VECTOR_2__
#define __VECTOR_2__

using Vector2 = struct 	Vector2;

struct Vector2{
	double x{0};
	double y{0};

	Vector2() = default;
	Vector2(const double x, const double y);
	Vector2(const Vector2 &other);

	Vector2 dotProduct(const Vector2 &other) const;

	Vector2 operator -(const Vector2 &other) const;
	Vector2 operator +(const Vector2 &other) const;
	Vector2 operator*(const double a) const;
	Vector2 operator /(const double a) const;
};
#endif
