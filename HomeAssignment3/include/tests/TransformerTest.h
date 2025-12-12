#ifndef TESTS_TRANSFORMER_TEST_H_
#define TESTS_TRANSFORMER_TEST_H_

#include "transformers/Transformer.h"
#include "transformers/Weapon.h"
#include "transformers/Alliance.h"

namespace tests {

class TransformerTest {
 public:
  static void RunAllTests();
  
 private:
  static void TestConstructor();
  static void TestGetMethods();
  static void TestSetMethods();
  static void TestTransformMethod();
  static void TestIntroduceMethod();
  static void TestGetTypeMethod();
  static void TestIsPowerfulMethod();
  static void TestCompositionAndAssociation();
};

}

#endif