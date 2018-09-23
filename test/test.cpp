#include <gtest/gtest.h>
#include <pidController.hpp>


TEST(PidControllerTest, PIDElementsTest) {
  Pid_controller c(0.01, 0.001, 0.01);
  EXPECT_NEAR(c.compute_step(10), 10, 0.001);
  EXPECT_EQ(c.clipper(1), 1);
  EXPECT_EQ(c.clipper(10), 10);
}

TEST(PidControllerTest, PIDpreformaceTest) {
  Pid_controller c(0.01, 0.001, 0.01);
  c.compute(5, 0);
  EXPECT_NEAR(c.get_current_state(), 5, 0.001);
  c.compute(5, 10);
  EXPECT_NEAR(c.get_current_state(), 5, 0.001);
}

TEST(PidControllerTest, PIDExceptionsTest) {
  Pid_controller c(0.01, 0.001, 0.01);
  EXPECT_ANY_THROW(c.compute(-5, 0));
  EXPECT_ANY_THROW(c.compute_step(-5));
}