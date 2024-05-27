#ifndef COLOUR_H
#define COLOUR_H

#include "vec3.h"
#include <iostream>

typedef Vec3 Colour;
void WriteColour(std::ostream &s, const Colour &c) {
  auto r = c.x();
  auto g = c.y();
  auto b = c.z();

  int ri = int(255.9999 * r);
  int gi = int(255.9999 * g);
  int bi = int(255.9999 * b);
  s << ri << ' ' << gi << ' ' << bi << '\n';
}

#endif
