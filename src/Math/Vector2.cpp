#include <Math/Vector2.hpp>

Vector2::Vector2(const double x, const double y){
  this->x = x;
  this->y = y;
}

Vector2::Vector2(const Vector2 &other){
  this->x = other.x;
  this->y = other.y;
}

Vector2 Vector2::dotProduct(const Vector2 &other) const{
  return Vector2(this->x * other.x, this->y * other.y);
}

Vector2 Vector2::operator-(const Vector2 &other) const{
  return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator+(const Vector2 &other) const{
  return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator*(const double a) const{
  return Vector2(this->x * a, this->y * a);
}

Vector2 Vector2::operator/(const double a) const{
  return Vector2(this->x / a, this->y / a);
}
