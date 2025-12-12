#include "tests/WeaponTest.h"
#include <iostream>
#include <cassert>

namespace tests {

void WeaponTest::RunAllTests() {
  std::cout << "Running Weapon tests...\n";
  TestConstructor();
  TestGetMethods();
  TestSetMethods();
  TestAttackMethod();
  TestIsPowerfulMethod();
  std::cout << "All Weapon tests passed!\n";
}

void WeaponTest::TestConstructor() {
  transformers::Weapon weapon;
  assert(weapon.GetName() == "Unknown");
  assert(weapon.GetDamage() == 10);
  assert(weapon.GetType() == "Energy");
  
  transformers::Weapon custom("Blaster", 50, "Plasma");
  assert(custom.GetName() == "Blaster");
  assert(custom.GetDamage() == 50);
  assert(custom.GetType() == "Plasma");
}

void WeaponTest::TestGetMethods() {
  transformers::Weapon weapon("Sword", 40, "Melee");
  assert(weapon.GetName() == "Sword");
  assert(weapon.GetDamage() == 40);
  assert(weapon.GetType() == "Melee");
}

void WeaponTest::TestSetMethods() {
  transformers::Weapon weapon;
  weapon.SetName("Cannon");
  weapon.SetDamage(70);
  weapon.SetType("Explosive");
  
  assert(weapon.GetName() == "Cannon");
  assert(weapon.GetDamage() == 70);
  assert(weapon.GetType() == "Explosive");
}

void WeaponTest::TestAttackMethod() {
  transformers::Weapon weapon("Blaster", 50, "Energy");
  std::string attack = weapon.Attack();
  assert(attack.find("Blaster") != std::string::npos);
  assert(attack.find("50") != std::string::npos);
}

void WeaponTest::TestIsPowerfulMethod() {
  transformers::Weapon weak("Weak", 30, "Energy");
  transformers::Weapon powerful("Powerful", 70, "Plasma");
  
  assert(!weak.IsPowerful());
  assert(powerful.IsPowerful());
}

}