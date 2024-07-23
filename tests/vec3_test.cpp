#include <gtest/gtest.h>

#include "../src/lib/vec3.h"

TEST(Vec3Test, Initialiser) {
  Vec3 v(1.0, 2.0, 3.0);
  EXPECT_EQ(v.x(), 1.0);
}

TEST(Vec3Test, PlusOperator) {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 s = v + v;
  EXPECT_EQ(s.x(), 2.0);
  EXPECT_EQ(s.y(), 4.0);
  EXPECT_EQ(s.z(), 6.0);

  s += v;
  EXPECT_EQ(s.x(), 3.0);
  EXPECT_EQ(s.y(), 6.0);
  EXPECT_EQ(s.z(), 9.0);
}

TEST(Vec3Test, MinusOperator) {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 s = v - v;
  EXPECT_EQ(s.x(), 0.0);
  EXPECT_EQ(s.y(), 0.0);
  EXPECT_EQ(s.z(), 0.0);

  s -= v;
  EXPECT_EQ(s.x(), -1.0);
  EXPECT_EQ(s.y(), -2.0);
  EXPECT_EQ(s.z(), -3.0);

  v = -v;
  EXPECT_EQ(v.x(), -1.0);
  EXPECT_EQ(v.y(), -2.0);
  EXPECT_EQ(v.z(), -3.0);
}

TEST(Vec3Test, MultiplyOperator) {
  Vec3 v(1.0, 2.0, 3.0);
  Vec3 s = v * 1.5;
  EXPECT_EQ(s.x(), 1.5);
  EXPECT_EQ(s.y(), 3.0);
  EXPECT_EQ(s.z(), 4.5);

  Vec3 t = 1.5 * v;
  EXPECT_EQ(s.x(), t.x());
  EXPECT_EQ(s.y(), t.y());
  EXPECT_EQ(s.z(), t.z());

  v *= 1.5;
  EXPECT_EQ(v.x(), 1.5);
  EXPECT_EQ(v.y(), 3.0);
  EXPECT_EQ(v.z(), 4.5);
}

TEST(Vec3Test, DivideOperator) {
  Vec3 v(2.0, 4.0, 6.0);
  Vec3 s = v / 2.0;
  EXPECT_EQ(s.x(), 1.0);
  EXPECT_EQ(s.y(), 2.0);
  EXPECT_EQ(s.z(), 3.0);

  v /= 2.0;
  EXPECT_EQ(v.x(), 1.0);
  EXPECT_EQ(v.y(), 2.0);
  EXPECT_EQ(v.z(), 3.0);
}

TEST(Vec3Test, Norm) {
  Vec3 v(1.0, 2.0, 2.0);
  EXPECT_EQ(v.norm(), 3.0);
}

TEST(Vec3Test, Dot) {
  Vec3 v(1.0, 2.0, 2.0);
  EXPECT_EQ(v.dot(v), 9.0);
}

TEST(Vec3Test, Cross) {
  Vec3 u(1.0, 2.0, 3.0), v(4.0, 5.0, 6.0);
  Vec3 c = u.cross(v);
  EXPECT_EQ(c.x(), -3.0);
  EXPECT_EQ(c.y(), 6.0);
  EXPECT_EQ(c.z(), -3.0);
}

TEST(Vec3Test, UnitVector) {
  Vec3 u(2.0, 0.0, 0.0);
  Vec3 c = unit_vector(u);
  EXPECT_EQ(c.x(), 1.0);
  EXPECT_EQ(c.y(), 0.0);
  EXPECT_EQ(c.z(), 0.0);
}
