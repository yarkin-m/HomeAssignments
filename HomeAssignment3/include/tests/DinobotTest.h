#ifndef TESTS_DINOBOT_TEST_H_
#define TESTS_DINOBOT_TEST_H_

#include "transformers/Dinobot.h"

namespace tests {

class DinobotTest {
 public:
  static void RunAllTests();
  
 private:
  static void TestConstructor();
  static void TestGetMethods();
  static void TestSetMethods();
  static void TestRoarMethod();
  static void TestGetTypeMethod();
  static void TestInheritance();
};

}

#endif