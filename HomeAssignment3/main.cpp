#include <iostream>
#include "transformers/Weapon.h"
#include "transformers/Alliance.h"
#include "transformers/Transformer.h"
#include "transformers/Autobot.h"
#include "transformers/Decepticon.h"
#include "transformers/Dinobot.h"
#include "tests/WeaponTest.h"
#include "tests/AllianceTest.h"
#include "tests/TransformerTest.h"
#include "tests/AutobotTest.h"
#include "tests/DecepticonTest.h"
#include "tests/DinobotTest.h"

int main() {
  std::cout << "=== Transformers Class Hierarchy Tests ===\n\n";
  
  std::cout << "1. Running Unit Tests:\n";
  tests::WeaponTest::RunAllTests();
  tests::AllianceTest::RunAllTests();
  tests::TransformerTest::RunAllTests();
  tests::AutobotTest::RunAllTests();
  tests::DecepticonTest::RunAllTests();
  tests::DinobotTest::RunAllTests();
  
  std::cout << "\n2. Integration Test:\n";
  
  transformers::Weapon sword("Energon Sword", 45, "Melee");
  transformers::Weapon blaster("Ion Blaster", 60, "Energy");
  
  transformers::Alliance autobots("Autobots", "Optimus Prime", 150);
  transformers::Alliance decepticons("Decepticons", "Megatron", 120);
  
  transformers::Transformer* transformers[3];
  
  transformers::Autobot optimus("Optimus Prime", 12, 35, 150, &sword, &autobots,
                                "Truck", 95, true);
  transformers::Decepticon megatron("Megatron", 13, 40, 160, &blaster, 
                                    &decepticons, "Tank", 90, false);
  transformers::Dinobot grimlock("Grimlock", 9, 28, 140, &sword, &autobots,
                                 "T-Rex", 85, true);
  
  transformers[0] = &optimus;
  transformers[1] = &megatron;
  transformers[2] = &grimlock;
  
  std::cout << "\nPolymorphism demonstration:\n";
  for (int i = 0; i < 3; ++i) {
    std::cout << transformers[i]->GetName() << " type: " 
              << transformers[i]->GetType() << "\n";
    std::cout << transformers[i]->Transform() << "\n";
    std::cout << transformers[i]->Introduce() << "\n\n";
  }
  
  std::cout << "Composition and Association:\n";
  std::cout << "Optimus's weapon: " << optimus.GetWeapon()->GetName() << "\n";
  std::cout << "Megatron's alliance: " 
            << megatron.GetAlliance()->GetName() << "\n";
  
  std::cout << "\n=== All tests completed successfully! ===\n";
  
  return 0;
}