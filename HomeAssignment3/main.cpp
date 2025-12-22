#include <iostream>
#include <memory> 
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"

using namespace std;

int main() {

  Alliance* autobotAlliance = new Alliance("Autobots", "Optimus Prime");
  Alliance* decepticonAlliance = new Alliance("Decepticons", "Megatron");
  
  auto axe = std::make_unique<Weapon>("Axe", 80);
  auto cannon = std::make_unique<Weapon>("Cannon", 120);
  auto sword = std::make_unique<Weapon>("Sword", 90);
  
  Autobot* optimus = new Autobot("Optimus Prime", 15, 8, 200, 
                                 std::move(axe), autobotAlliance, 
                                 "truck", 95);
  
  Decepticon* megatron = new Decepticon("Megatron", 14, 9, 180, 
                                        std::move(cannon), decepticonAlliance, 
                                        "airplane", true);
  
  Dinobot* grimlock = new Dinobot("Grimlock", 12, 10, 220, 
                                  std::move(sword), autobotAlliance, 
                                  "tyrannosaurus", 150);
  
  cout << "\nTESTING" << endl;
  
  cout << "\n1. Transformer information:" << endl;
  cout << optimus->GetInfo() << endl;
  cout << megatron->GetInfo() << endl;
  cout << grimlock->GetInfo() << endl;
  
  cout << "\n2. Transformations:" << endl;
  cout << optimus->Transform() << endl;
  cout << megatron->Transform() << endl;
  cout << grimlock->Transform() << endl;
  
  cout << "\n3. Attacks:" << endl;
  cout << optimus->Attack() << endl;
  cout << megatron->Attack() << endl;
  cout << grimlock->Attack() << endl;
  
  cout << "\n4. Special abilities:" << endl;
  cout << optimus->ProtectHumans() << endl;
  cout << megatron->Terrorize() << endl;
  cout << grimlock->Roar() << endl;
  
  cout << "\n5. Test get/set methods:" << endl;
  optimus->SetPowerLevel(250);
  cout << "New power level of Optimus: " << optimus->GetPowerLevel() << endl;
  
  cout << "\n6. Test composition and association:" << endl;
  cout << "Optimus's weapon: " << optimus->GetWeapon()->GetName() 
            << " (damage: " << optimus->GetWeapon()->GetDamage() << ")" << endl;
  cout << "Megatron's alliance: " << megatron->GetAlliance()->GetName() 
            << " (leader: " << megatron->GetAlliance()->GetLeader() << ")" << endl;
  
  cout << "\nDESTROYING OBJECTS" << endl;
  delete optimus;
  delete megatron;
  delete grimlock;
  delete autobotAlliance;
  delete decepticonAlliance;
  
  return 0;
}