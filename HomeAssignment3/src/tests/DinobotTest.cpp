#include "tests/DinobotTest.h"
#include <iostream>
#include <cassert>

namespace tests {

void DinobotTest::RunAllTests() {
  std::cout << "Running Dinobot tests...\n";
  TestConstructor();
  TestGetMethods();
  TestSetMethods();
  TestRoarMethod();
  TestGetTypeMethod();
  TestInheritance();
  std::cout << "All Dinobot tests passed!\n";
}

void DinobotTest::TestConstructor() {
  transformers::Dinobot dinobot;
  assert(dinobot.GetName() == "Dinobot");
  assert(dinobot.GetDinosaurForm() == "T-Rex");
  assert(dinobot.GetRoarPower() == 80);
  assert(dinobot.GetCanSwim() == false);
  
  transformers::Dinobot custom("Grimlock", 9, 28, 140, nullptr, nullptr,
                               "T-Rex", 90, true);
  assert(custom.GetName() == "Grimlock");
  assert(custom.GetDinosaurForm() == "T-Rex");
  assert(custom.GetRoarPower() == 90);
  assert(custom.GetCanSwim() == true);
}

void DinobotTest::TestGetMethods() {
  transformers::Dinobot dinobot("Slag", 8, 26, 120, nullptr, nullptr,
                                "Triceratops", 85, false);
  assert(dinobot.GetDinosaurForm() == "Triceratops");
  assert(dinobot.GetRoarPower() == 85);
  assert(dinobot.GetCanSwim() == false);
}

void DinobotTest::TestSetMethods() {
  transformers::Dinobot dinobot;
  dinobot.SetDinosaurForm("Stegosaurus");
  dinobot.SetRoarPower(95);
  dinobot.SetCanSwim(true);
  
  assert(dinobot.GetDinosaurForm() == "Stegosaurus");
  assert(dinobot.GetRoarPower() == 95);
  assert(dinobot.GetCanSwim() == true);
}

void DinobotTest::TestRoarMethod() {
  transformers::Dinobot dinobot("Snarl");
  std::string roar = dinobot.Roar();
  assert(roar.find("Snarl") != std::string::npos);
  assert(roar.find("roars") != std::string::npos);
}

void DinobotTest::TestGetTypeMethod() {
  transformers::Dinobot dinobot;
  assert(dinobot.GetType() == "Dinobot");
}

void DinobotTest::TestInheritance() {
  transformers::Dinobot dinobot("Test", 8, 25, 90);
  
  assert(dinobot.GetHeight() == 8);
  assert(dinobot.GetWeight() == 25);
  assert(dinobot.GetPowerLevel() == 90);
  
  std::string transform = dinobot.Transform();
  assert(transform.find("Test") != std::string::npos);
}

}