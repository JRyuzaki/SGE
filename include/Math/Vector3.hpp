#ifndef __VECTOR_3__
#define __VECTOR_3__

#include "Vector2.hpp"

using Vector3 = struct Vector3;

struct Vector3{
	double x{0};
	double y{0};
	double z{0};

	Vector3(double x, double y, double z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	Vector3(Vector2 position_2d, double z){
		this->x = position_2d.x;
		this->y = position_2d.y;
		this->z = z;
	}
	
	Vector3(const Vector3 &other){
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}
	
	const Vector3 dotProduct(const Vector3 &other) const {
		return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
	}
	
	Vector3 operator -(const Vector3 &other){
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}
	
	Vector3 operator +(const Vector3 &other){
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}
	
	double operator *(const Vector3 &other){
		return this->x * other.x + this->y * other.y + this->z * other.z;
	}
	
	Vector3 operator*(const double a){
		return Vector3(this->x * a, this->y * a, this->z * a);
	}
	
	Vector3 operator/(const double a){
		return Vector3(this->x / a, this->y / a, this->z / a);
	}
};
#endif
