#ifndef TESTS_AUTOBOT_TEST_H_
#define TESTS_AUTOBOT_TEST_H_

#include "transformers/Autobot.h"

namespace tests {

class AutobotTest {
 public:
  static void RunAllTests();
  
 private:
  static void TestConstructor();
  static void TestGetMethods();
  static void TestSetMethods();
  static void TestDefendMethod();
  static void TestGetTypeMethod();
  static void TestIntroduceMethod();
  static void TestInheritance();
};

}

#endif