#include <gtest/gtest.h>

#include "../src/lib/ray.h"

TEST(RayTest, Ray) {
  Ray r(Vec3(1, 2, 3), Vec3(1, 2, 4));
  EXPECT_EQ(r.origin(), Vec3(1, 2, 3));
  EXPECT_EQ(r.direction(), Vec3(1, 2, 4));
  EXPECT_EQ(r.at(2), Vec3(3, 6, 11));
}
