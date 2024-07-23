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

  Vec3 operator-() const;
  Vec3 &operator+=(const Vec3 &other);
  Vec3 operator+(const Vec3 &other) const;
  Vec3 operator-(const Vec3 &other) const;
  Vec3 &operator-=(const Vec3 &other);
  Vec3 operator*(double s) const;
  Vec3 &operator*=(double s);
  Vec3 operator/(double s) const;
  Vec3 &operator/=(double s);
  double dot(const Vec3 &other) const;
  Vec3 cross(const Vec3 &other) const;
  double norm() const;
};

/* Overload RHS operators */
Vec3 operator*(double s, const Vec3 &rhs);
Vec3 operator*(int s, const Vec3 &rhs);
bool operator==(const Vec3 &lhs, const Vec3 &rhs);
Vec3 unit_vector(const Vec3 &dir);

#endif
