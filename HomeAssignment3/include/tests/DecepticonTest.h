#ifndef TESTS_DECEPTICON_TEST_H_
#define TESTS_DECEPTICON_TEST_H_

#include "transformers/Decepticon.h"

namespace tests {

class DecepticonTest {
 public:
  static void RunAllTests();
  
 private:
  static void TestConstructor();
  static void TestGetMethods();
  static void TestSetMethods();
  static void TestAttackMethod();
  static void TestGetTypeMethod();
  static void TestInheritance();
};

}

#endif