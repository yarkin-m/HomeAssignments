#include "tests/AutobotTest.h"
#include <iostream>
#include <cassert>

namespace tests {

void AutobotTest::RunAllTests() {
  std::cout << "Running Autobot tests...\n";
  TestConstructor();
  TestGetMethods();
  TestSetMethods();
  TestDefendMethod();
  TestGetTypeMethod();
  TestIntroduceMethod();
  TestInheritance();
  std::cout << "All Autobot tests passed!\n";
}

void AutobotTest::TestConstructor() {
  transformers::Autobot autobot;
  assert(autobot.GetName() == "Autobot");
  assert(autobot.GetVehicleMode() == "Truck");
  assert(autobot.GetCourageLevel() == 50);
  assert(autobot.GetIsLeader() == false);
  
  transformers::Autobot custom("Optimus", 12, 35, 150, nullptr, nullptr,
                               "Truck", 95, true);
  assert(custom.GetName() == "Optimus");
  assert(custom.GetVehicleMode() == "Truck");
  assert(custom.GetCourageLevel() == 95);
  assert(custom.GetIsLeader() == true);
}

void AutobotTest::TestGetMethods() {
  transformers::Autobot autobot("Bumblebee", 8, 25, 90, nullptr, nullptr,
                                "Car", 70, false);
  assert(autobot.GetVehicleMode() == "Car");
  assert(autobot.GetCourageLevel() == 70);
  assert(autobot.GetIsLeader() == false);
}

void AutobotTest::TestSetMethods() {
  transformers::Autobot autobot;
  autobot.SetVehicleMode("Van");
  autobot.SetCourageLevel(85);
  autobot.SetIsLeader(true);
  
  assert(autobot.GetVehicleMode() == "Van");
  assert(autobot.GetCourageLevel() == 85);
  assert(autobot.GetIsLeader() == true);
}

void AutobotTest::TestDefendMethod() {
  transformers::Autobot autobot("Ironhide");
  std::string defend = autobot.Defend();
  assert(defend.find("Ironhide") != std::string::npos);
  assert(defend.find("defends") != std::string::npos);
}

void AutobotTest::TestGetTypeMethod() {
  transformers::Autobot autobot;
  assert(autobot.GetType() == "Autobot");
}

void AutobotTest::TestIntroduceMethod() {
  transformers::Autobot autobot("Optimus");
  std::string introduce = autobot.Introduce();
  assert(introduce.find("Optimus") != std::string::npos);
  assert(introduce.find("Autobot") != std::string::npos);
}

void AutobotTest::TestInheritance() {
  transformers::Autobot autobot("Test", 10, 30, 100);
  
  assert(autobot.GetHeight() == 10);
  assert(autobot.GetWeight() == 30);
  assert(autobot.GetPowerLevel() == 100);
  
  std::string transform = autobot.Transform();
  assert(transform.find("Test") != std::string::npos);
}

}