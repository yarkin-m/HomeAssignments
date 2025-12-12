#include "tests/TransformerTest.h"
#include <iostream>
#include <cassert>

namespace tests {

void TransformerTest::RunAllTests() {
  std::cout << "Running Transformer tests...\n";
  TestConstructor();
  TestGetMethods();
  TestSetMethods();
  TestTransformMethod();
  TestIntroduceMethod();
  TestGetTypeMethod();
  TestIsPowerfulMethod();
  TestCompositionAndAssociation();
  std::cout << "All Transformer tests passed!\n";
}

void TransformerTest::TestConstructor() {
  transformers::Transformer transformer;
  assert(transformer.GetName() == "Unknown");
  assert(transformer.GetHeight() == 10);
  assert(transformer.GetWeight() == 30);
  assert(transformer.GetPowerLevel() == 100);
  assert(transformer.GetWeapon() == nullptr);
  assert(transformer.GetAlliance() == nullptr);
  
  transformers::Transformer custom("Optimus", 12, 35, 150);
  assert(custom.GetName() == "Optimus");
  assert(custom.GetHeight() == 12);
  assert(custom.GetWeight() == 35);
  assert(custom.GetPowerLevel() == 150);
}

void TransformerTest::TestGetMethods() {
  transformers::Transformer transformer("Megatron", 13, 40, 160);
  assert(transformer.GetName() == "Megatron");
  assert(transformer.GetHeight() == 13);
  assert(transformer.GetWeight() == 40);
  assert(transformer.GetPowerLevel() == 160);
}

void TransformerTest::TestSetMethods() {
  transformers::Transformer transformer;
  transformer.SetName("Bumblebee");
  transformer.SetHeight(8);
  transformer.SetWeight(25);
  transformer.SetPowerLevel(90);
  
  assert(transformer.GetName() == "Bumblebee");
  assert(transformer.GetHeight() == 8);
  assert(transformer.GetWeight() == 25);
  assert(transformer.GetPowerLevel() == 90);
}

void TransformerTest::TestTransformMethod() {
  transformers::Transformer transformer("Starscream");
  std::string transform = transformer.Transform();
  assert(transform.find("Starscream") != std::string::npos);
  assert(transform.find("transforming") != std::string::npos);
}

void TransformerTest::TestIntroduceMethod() {
  transformers::Transformer transformer("Ironhide");
  std::string introduce = transformer.Introduce();
  assert(introduce.find("Ironhide") != std::string::npos);
  assert(introduce.find("Transformer") != std::string::npos);
}

void TransformerTest::TestGetTypeMethod() {
  transformers::Transformer transformer;
  assert(transformer.GetType() == "Generic Transformer");
}

void TransformerTest::TestIsPowerfulMethod() {
  transformers::Transformer weak("Weak", 10, 30, 80);
  transformers::Transformer powerful("Powerful", 10, 30, 120);
  
  assert(!weak.IsPowerful());
  assert(powerful.IsPowerful());
}

void TransformerTest::TestCompositionAndAssociation() {
  transformers::Weapon sword("Sword", 40, "Melee");
  transformers::Alliance autobots("Autobots", "Optimus", 150);
  
  transformers::Transformer transformer("Test", 10, 30, 100, &sword, &autobots);
  
  assert(transformer.GetWeapon() != nullptr);
  assert(transformer.GetWeapon()->GetName() == "Sword");
  assert(transformer.GetAlliance() != nullptr);
  assert(transformer.GetAlliance()->GetName() == "Autobots");
}

}