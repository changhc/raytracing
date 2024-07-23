#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
public:
  Ray() {}

  Ray(const Vec3 &origin, const Vec3 &direction)
      : orig(origin), dir(direction) {}

  const Vec3 &origin() const { return orig; }
  const Vec3 &direction() const { return dir; }

  Vec3 at(double t) { return orig + dir * t; }

private:
  Vec3 orig;
  Vec3 dir;
};

#endif
