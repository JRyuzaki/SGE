#include <Math/Vector3.hpp>

Vector3::Vector3(const double x, const double y, const double z){
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector3::Vector3(const Vector2 position_2d, const double z){
  this->x = position_2d.x;
  this->y = position_2d.y;
  this->z = z;
}

Vector3::Vector3(const Vector3 &other){
  this->x = other.x;
  this->y = other.y;
  this->z = other.z;
}

Vector3 Vector3::dotProduct(const Vector3 &other) const{
  return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
}

Vector3 Vector3::operator -(const Vector3 &other) const{
  return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::operator +(const Vector3 &other) const{
  return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

double Vector3::operator *(const Vector3 &other) const{
  return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3 Vector3::operator *(const double a) const{
  return Vector3(this->x * a, this->y * a, this->z * a);
}

Vector3 Vector3::operator /(const double a) const{
  return Vector3(this->x / a, this->y / a, this->z / a);
}
