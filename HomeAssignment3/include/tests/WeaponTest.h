#ifndef TESTS_WEAPON_TEST_H_
#define TESTS_WEAPON_TEST_H_

#include "transformers/Weapon.h"

namespace tests {

class WeaponTest {
 public:
  static void RunAllTests();
  
 private:
  static void TestConstructor();
  static void TestGetMethods();
  static void TestSetMethods();
  static void TestAttackMethod();
  static void TestIsPowerfulMethod();
};

}

#endif