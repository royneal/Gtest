/*
 * @copyright Royneal Rayess
 * @file test.cpp
 * @auther Royneal Rayess
 * @ver1.0.0.0
 *
 * @brief A unit test to examine
 *        PID controller class
 *
 */

#include <gtest/gtest.h>
#include <pidController.hpp>


/*
 * @brief test set to examine individual
 *        computational steps
 */
TEST(PidControllerTest, PIDElementsTest) {
  Pid_controller c(0.01, 0.001, 0.01);
  EXPECT_NEAR(c.compute_step(10), 10, 0.001);
  EXPECT_EQ(c.clipper(1), 1);
  EXPECT_EQ(c.clipper(10), 10);
}

/*
 * @brief test set to examine corner cases
 */
TEST(PidControllerTest, PIDpreformaceTest) {
  Pid_controller c(0.01, 0.001, 0.01);
  c.compute(5, 0);
  EXPECT_NEAR(c.get_current_state(), 5, 0.001);
  c.compute(5, 10);
  EXPECT_NEAR(c.get_current_state(), 5, 0.001);
}

/*
 * @brief test set to examine resilience to input error
 */
TEST(PidControllerTest, PIDExceptionsTest) {
  Pid_controller c(0.01, 0.001, 0.01);
  EXPECT_ANY_THROW(c.compute(-5, 0));
  EXPECT_ANY_THROW(c.compute(-5, -5));
  EXPECT_ANY_THROW(c.compute(5, -5));
  EXPECT_ANY_THROW(c.compute_step(-5));
}
