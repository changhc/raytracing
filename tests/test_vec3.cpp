#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/lib/vec3.h"

TEST_CASE("Vec3 initialiser") {
  Vec3 v(1.0, 2.0, 3.0);
  REQUIRE(v.x() == 1.0);
}

TEST_CASE("Vec3 +") {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 s = v + v;
  REQUIRE(s.x() == 2.0);
  REQUIRE(s.y() == 4.0);
  REQUIRE(s.z() == 6.0);

  s += v;
  REQUIRE(s.x() == 3.0);
  REQUIRE(s.y() == 6.0);
  REQUIRE(s.z() == 9.0);
}

TEST_CASE("Vec3 -") {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 s = v - v;
  REQUIRE(s.x() == 0.0);
  REQUIRE(s.y() == 0.0);
  REQUIRE(s.z() == 0.0);

  s -= v;
  REQUIRE(s.x() == -1.0);
  REQUIRE(s.y() == -2.0);
  REQUIRE(s.z() == -3.0);

  v = -v;
  REQUIRE(v.x() == -1.0);
  REQUIRE(v.y() == -2.0);
  REQUIRE(v.z() == -3.0);
}

TEST_CASE("Vec3 *") {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 s = v * 1.5;
  REQUIRE(s.x() == 1.5);
  REQUIRE(s.y() == 3.0);
  REQUIRE(s.z() == 4.5);

  v *= 1.5;
  REQUIRE(v.x() == 1.5);
  REQUIRE(v.y() == 3.0);
  REQUIRE(v.z() == 4.5);
}

TEST_CASE("Vec3 /") {
  Vec3 v(2.0, 4.0, 6.0);
  Vec3 s = v / 2.0;
  REQUIRE(s.x() == 1.0);
  REQUIRE(s.y() == 2.0);
  REQUIRE(s.z() == 3.0);

  v /= 2.0;
  REQUIRE(v.x() == 1.0);
  REQUIRE(v.y() == 2.0);
  REQUIRE(v.z() == 3.0);
}

TEST_CASE("Vec3 norm") {
  Vec3 v(1.0, 2.0, 2.0);
  REQUIRE(v.norm() == 3.0);
}

TEST_CASE("Vec3 dot") {
  Vec3 v(1.0, 2.0, 2.0);
  REQUIRE(v.dot(v) == 9.0);
}

TEST_CASE("Vec3 cross") {
  Vec3 u(1.0, 2.0, 3.0), v(4.0, 5.0, 6.0);
  Vec3 c = u.cross(v);
  REQUIRE(c.x() == -3.0);
  REQUIRE(c.y() == 6.0);
  REQUIRE(c.z() == -3.0);
}
