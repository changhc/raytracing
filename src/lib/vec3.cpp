#include "vec3.h"
#include <cmath>

double Vec3::x() const { return e[0]; }

double Vec3::y() const { return e[1]; }

double Vec3::z() const { return e[2]; }

Vec3 Vec3::operator-() { return Vec3(-e[0], -e[1], -e[2]); }

Vec3 Vec3::operator-(const Vec3 &other) {
  return Vec3(this->x() - other.x(), this->y() - other.y(),
              this->z() - other.z());
}

Vec3 &Vec3::operator-=(const Vec3 &other) {
  this->e[0] -= other.x();
  this->e[1] -= other.y();
  this->e[2] -= other.z();
  return *this;
}

Vec3 Vec3::operator+(const Vec3 &other) {
  return Vec3(this->x() + other.x(), this->y() + other.y(),
              this->z() + other.z());
}

Vec3 &Vec3::operator+=(const Vec3 &other) {
  this->e[0] += other.x();
  this->e[1] += other.y();
  this->e[2] += other.z();
  return *this;
}

Vec3 Vec3::operator*(double s) {
  return Vec3(this->x() * s, this->y() * s, this->z() * s);
}

Vec3 &Vec3::operator*=(double s) {
  this->e[0] *= s;
  this->e[1] *= s;
  this->e[2] *= s;
  return *this;
}

Vec3 Vec3::operator/(double s) {
  return Vec3(this->x() / s, this->y() / s, this->z() / s);
}

Vec3 &Vec3::operator/=(double s) {
  this->e[0] /= s;
  this->e[1] /= s;
  this->e[2] /= s;
  return *this;
}

double Vec3::dot(const Vec3 &other) {
  return this->x() * other.x() + this->y() * other.y() + this->z() * other.z();
}

Vec3 Vec3::cross(const Vec3 &other) {
  return Vec3(this->y() * other.z() - this->z() * other.y(),
              this->z() * other.x() - this->x() * other.z(),
              this->x() * other.y() - this->y() * other.x());
}

double Vec3::norm() const {
  return std::sqrt(this->x() * this->x() + this->y() * this->y() +
                   this->z() * this->z());
}
