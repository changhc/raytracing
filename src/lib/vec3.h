#ifndef VEC3_H
#define VEC3_H

class Vec3 {
  double e[3];

public:
  Vec3() : e{0, 0, 0} {}
  Vec3(double x, double y, double z) : e{x, y, z} {}
  double x() const;
  double y() const;
  double z() const;

  Vec3 operator-();
  Vec3 &operator+=(const Vec3 &other);
  Vec3 operator+(const Vec3 &other);
  Vec3 operator-(const Vec3 &other);
  Vec3 &operator-=(const Vec3 &other);
  Vec3 operator*(double s);
  Vec3 &operator*=(double s);
  Vec3 operator/(double s);
  Vec3 &operator/=(double s);
  double dot(const Vec3 &other);
  Vec3 cross(const Vec3 &other);
  double norm() const;
};

#endif
