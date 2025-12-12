#ifndef TESTS_ALLIANCE_TEST_H_
#define TESTS_ALLIANCE_TEST_H_

#include "transformers/Alliance.h"

namespace tests {

class AllianceTest {
 public:
  static void RunAllTests();
  
 private:
  static void TestConstructor();
  static void TestGetMethods();
  static void TestSetMethods();
  static void TestGetInfoMethod();
  static void TestIsLargeMethod();
};

}

#endif