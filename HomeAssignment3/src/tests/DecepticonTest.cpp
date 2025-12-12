#include "tests/DecepticonTest.h"
#include <iostream>
#include <cassert>

namespace tests {

void DecepticonTest::RunAllTests() {
  std::cout << "Running Decepticon tests...\n";
  TestConstructor();
  TestGetMethods();
  TestSetMethods();
  TestAttackMethod();
  TestGetTypeMethod();
  TestInheritance();
  std::cout << "All Decepticon tests passed!\n";
}

void DecepticonTest::TestConstructor() {
  transformers::Decepticon decepticon;
  assert(decepticon.GetName() == "Decepticon");
  assert(decepticon.GetFlightMode() == "Jet");
  assert(decepticon.GetAggressionLevel() == 70);
  assert(decepticon.GetHasStealth() == false);
  
  transformers::Decepticon custom("Starscream", 11, 32, 130, nullptr, nullptr,
                                  "F-15", 85, true);
  assert(custom.GetName() == "Starscream");
  assert(custom.GetFlightMode() == "F-15");
  assert(custom.GetAggressionLevel() == 85);
  assert(custom.GetHasStealth() == true);
}

void DecepticonTest::TestGetMethods() {
  transformers::Decepticon decepticon("Soundwave", 10, 30, 110, nullptr, nullptr,
                                      "Cassette Player", 60, false);
  assert(decepticon.GetFlightMode() == "Cassette Player");
  assert(decepticon.GetAggressionLevel() == 60);
  assert(decepticon.GetHasStealth() == false);
}

void DecepticonTest::TestSetMethods() {
  transformers::Decepticon decepticon;
  decepticon.SetFlightMode("Helicopter");
  decepticon.SetAggressionLevel(90);
  decepticon.SetHasStealth(true);
  
  assert(decepticon.GetFlightMode() == "Helicopter");
  assert(decepticon.GetAggressionLevel() == 90);
  assert(decepticon.GetHasStealth() == true);
}

void DecepticonTest::TestAttackMethod() {
  transformers::Decepticon decepticon("Megatron");
  std::string attack = decepticon.Attack();
  assert(attack.find("Megatron") != std::string::npos);
  assert(attack.find("attacks") != std::string::npos);
}

void DecepticonTest::TestGetTypeMethod() {
  transformers::Decepticon decepticon;
  assert(decepticon.GetType() == "Decepticon");
}

void DecepticonTest::TestInheritance() {
  transformers::Decepticon decepticon("Test", 12, 40, 120);
  
  assert(decepticon.GetHeight() == 12);
  assert(decepticon.GetWeight() == 40);
  assert(decepticon.GetPowerLevel() == 120);
  
  std::string transform = decepticon.Transform();
  assert(transform.find("Test") != std::string::npos);
}

}