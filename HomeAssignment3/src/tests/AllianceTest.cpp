#include "tests/AllianceTest.h"
#include <iostream>
#include <cassert>

namespace tests {

void AllianceTest::RunAllTests() {
  std::cout << "Running Alliance tests...\n";
  TestConstructor();
  TestGetMethods();
  TestSetMethods();
  TestGetInfoMethod();
  TestIsLargeMethod();
  std::cout << "All Alliance tests passed!\n";
}

void AllianceTest::TestConstructor() {
  transformers::Alliance alliance;
  assert(alliance.GetName() == "Unaffiliated");
  assert(alliance.GetLeader() == "None");
  assert(alliance.GetMemberCount() == 0);
  
  transformers::Alliance custom("Autobots", "Optimus Prime", 150);
  assert(custom.GetName() == "Autobots");
  assert(custom.GetLeader() == "Optimus Prime");
  assert(custom.GetMemberCount() == 150);
}

void AllianceTest::TestGetMethods() {
  transformers::Alliance alliance("Decepticons", "Megatron", 120);
  assert(alliance.GetName() == "Decepticons");
  assert(alliance.GetLeader() == "Megatron");
  assert(alliance.GetMemberCount() == 120);
}

void AllianceTest::TestSetMethods() {
  transformers::Alliance alliance;
  alliance.SetName("Dinobots");
  alliance.SetLeader("Grimlock");
  alliance.SetMemberCount(50);
  
  assert(alliance.GetName() == "Dinobots");
  assert(alliance.GetLeader() == "Grimlock");
  assert(alliance.GetMemberCount() == 50);
}

void AllianceTest::TestGetInfoMethod() {
  transformers::Alliance alliance("Autobots", "Optimus Prime", 150);
  std::string info = alliance.GetInfo();
  assert(info.find("Autobots") != std::string::npos);
  assert(info.find("Optimus Prime") != std::string::npos);
  assert(info.find("150") != std::string::npos);
}

void AllianceTest::TestIsLargeMethod() {
  transformers::Alliance small("Small", "Leader", 50);
  transformers::Alliance large("Large", "Leader", 150);
  
  assert(!small.IsLarge());
  assert(large.IsLarge());
}

}