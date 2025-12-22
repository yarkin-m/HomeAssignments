/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include <iostream>
#include "Alliance.h"
#include "Weapon.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include <vector>
#include <memory>

using namespace std;
/*
void TestConstructorOverloading() {
    cout << "Constructor overloading test" << endl;
    
    cout << "\n1. TRANSFORMER CONSTRUCTORS:" << endl;
    cout << "1.1 Simple constructor (name only):" << endl;
    Transformer t1("Simple Transformer");
    cout << "   " << t1 << endl;

    cout << "\n1.2 Constructor with name and power:" << endl;
    Transformer t2("Powerful", 500);
    cout << "   " << t2 << endl;

    cout << "\n1.3 Copy constructor:" << endl;
    Transformer t3 = t2;  
    cout << "   Original: " << t2.GetName() << endl;
    cout << "   Copy: " << t3 << endl;
    
    cout << "\n1.4 Deep Copy check (modify original):" << endl;
    t2.SetPowerLevel(999);
    cout << "   Original power: " << t2.GetPowerLevel() << endl;
    cout << "   Copy power: " << t3.GetPowerLevel() << " (not changed!)" << endl;
    

    // AUTOBOTS
    cout << "\n\n2. AUTOBOT CONSTRUCTORS:" << endl;
    
    cout << "2.1 Simple constructor:" << endl;
    Autobot a1("Bumblebee");
    cout << "   " << a1 << endl;
    cout << "   Form: " << a1.GetVehicleForm() << endl;
    cout << "   Courage: " << a1.GetCourageLevel() << endl;
    
    cout << "\n2.2 Constructor with name and form:" << endl;
    Autobot a2("Jazz", "sports car");
    cout << "   " << a2 << endl;
    cout << "   Form: " << a2.GetVehicleForm() << endl;
    
    cout << "\n2.3 Copy constructor:" << endl;
    Autobot a3 = a2;
    cout << "   Copy: " << a3 << endl;
    cout << "   Copy form: " << a3.GetVehicleForm() << endl;
    


    // DECEPTICONS
    cout << "\n\n3. DECEPTICON CONSTRUCTORS:" << endl;
    
    cout << "3.1 Simple constructor:" << endl;
    Decepticon d1("Starscream");
    cout << "   " << d1 << endl;
    cout << "   Form: " << d1.GetFlyingForm() << endl;
    cout << "   Wings: " << (d1.GetHasWings() ? "yes" : "no") << endl;
    
    cout << "\n3.2 Constructor with name and form:" << endl;
    Decepticon d2("Soundwave", "cassette player");
    cout << "   " << d2 << endl;
    cout << "   Form: " << d2.GetFlyingForm() << endl;
    
    cout << "\n3.3 Copy constructor:" << endl;
    Decepticon d3 = d1;
    cout << "   Copy: " << d3 << endl;
    cout << "   Copy form: " << d3.GetFlyingForm() << endl;
    


    // DINOBOTS
    cout << "\n\n4. DINOBOT CONSTRUCTORS:" << endl;
    cout << string(30, '-') << endl;
    
    cout << "4.1 Simple constructor:" << endl;
    Dinobot dn1("Slag");
    cout << "   " << dn1 << endl;
    cout << "   Form: " << dn1.GetDinosaurForm() << endl;
    cout << "   Roar power: " << dn1.GetRoarPower() << endl;
    
    cout << "\n4.2 Constructor with name and form:" << endl;
    Dinobot dn2("Snarl", "sabertooth");
    cout << "   " << dn2 << endl;
    cout << "   Form: " << dn2.GetDinosaurForm() << endl;
    
    cout << "\n4.3 Copy constructor:" << endl;
    Dinobot dn3 = dn1;
    cout << "   Copy: " << dn3 << endl;
    cout << "   Copy form: " << dn3.GetDinosaurForm() << endl;
    

    // Different constructors
    cout << "\n\n5. ARRAY OF OBJECTS (different constructors):" << endl;
    
    Transformer* army[6];
    
    army[0] = new Transformer("Basic1");
    army[1] = new Transformer("Basic2", 350);
    
    army[2] = new Autobot("Ratchet");
    army[3] = new Autobot("Ironhide", "SUV");
    
    army[4] = new Decepticon("Shockwave");
    army[5] = new Dinobot("Swoop");
    
    cout << "\nArmy information:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "  " << i+1 << ". " << *army[i] << endl;
    }
    
    cout << "\nCleaning memory..." << endl;
    for (int i = 0; i < 6; i++) {
        delete army[i];
    }
    
    // Complex copying
    cout << "\n\n6. COMPLEX COPY (with weapons and alliances):" << endl;

    Alliance* testAlliance = new Alliance("Test", "Leader");
    auto testWeapon = std::make_unique<Weapon>("Test weapon", 75);
    
    Autobot original("Original", 12, 6, 180, std::move(testWeapon), testAlliance, "truck", 85);
    cout << "Created original: " << original << endl;
    cout << "Original weapon: " << original.GetWeapon()->GetName() << endl;
    
    Autobot copy = original;
    cout << "Created copy: " << copy << endl;
    
    cout << "\nDeep Copy weapon check:" << endl;
    cout << "Original weapon address: " << original.GetWeapon() << endl;
    cout << "Copy weapon address: " << copy.GetWeapon() << endl;
    
    copy.GetWeapon()->SetDamage(100);
    cout << "\nChanging copy weapon damage to 100..." << endl;
    cout << "Original weapon damage: " << original.GetWeapon()->GetDamage() << " (not changed!)" << endl;
    cout << "Copy weapon damage: " << copy.GetWeapon()->GetDamage() << endl;
    
    delete testAlliance;
  }
*/
void TestVirtualMethods() {

    cout << "VIRTUAL METHODS TEST" << endl;
    
    cout << "\n1. DIRECT METHOD CALLS:" << endl;
    
    Autobot optimus("Optimus Prime", "truck");
    Decepticon megatron("Megatron", "airplane");
    Dinobot grimlock("Grimlock", "tyrannosaurus");
    
    cout << "\nA) Autobot methods:" << endl;
    optimus.ShowInfo();
    optimus.BattleCry();
    optimus.Transform();
    optimus.SpecialAbility(); 
    optimus.Repair();          
    optimus.ProtectHumans();   
    
    cout << "\nB) Decepticon methods:" << endl;
    megatron.ShowInfo();
    megatron.BattleCry();
    megatron.Transform();
    megatron.SpecialAbility();
    megatron.Repair();
    megatron.Terrorize();
    
    cout << "\nC) Dinobot methods:" << endl;
    grimlock.ShowInfo();
    grimlock.BattleCry();
    grimlock.Transform();
    grimlock.SpecialAbility();
    grimlock.Repair();
    grimlock.Roar();
    
    cout << "\n\n2. CALL THROUGH BASE CLASS POINTER:" << endl;
    
    Transformer* army[3];
    army[0] = &optimus;
    army[1] = &megatron;
    army[2] = &grimlock;
    
    for (int i = 0; i < 3; i++) {
        cout << "\nFighter #" << (i + 1) << ":" << endl;
        army[i]->ShowInfo();       
        army[i]->BattleCry();      
        army[i]->Transform();      
        army[i]->SpecialAbility(); 
        army[i]->Repair();         
    }
    
    cout << "\n\n3. VECTOR OF 9 OBJECTS (3 of each type):" << endl;
    
    vector<Transformer*> bigArmy;
    

    bigArmy.push_back(new Autobot("Optimus", "truck"));
    bigArmy.push_back(new Autobot("Bumblebee", "car"));
    bigArmy.push_back(new Autobot("Jazz", "sports car"));
    
    bigArmy.push_back(new Decepticon("Megatron", "gun"));
    bigArmy.push_back(new Decepticon("Starscream", "fighter jet"));
    bigArmy.push_back(new Decepticon("Soundwave", "cassette player"));
    
    bigArmy.push_back(new Dinobot("Grimlock", "tyrannosaurus"));
    bigArmy.push_back(new Dinobot("Slag", "triceratops"));
    bigArmy.push_back(new Dinobot("Snarl", "sabertooth"));
    

    for (size_t i = 0; i < bigArmy.size(); i++) {
        cout << "\n--- Fighter #" << (i + 1) << " ---" << endl;
        bigArmy[i]->ShowInfo();
        bigArmy[i]->BattleCry();
        bigArmy[i]->SpecialAbility();
        
        if (i % 3 == 0) {
            bigArmy[i]->Transform();
        }
    }
    
    for (auto soldier : bigArmy) {
        delete soldier;
    }
}

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
  /*
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
  */
  cout << "\nTests 1-4 for assignment 3" << endl;
  cout << "\n5. Test get/set methods:" << endl;
  optimus->SetPowerLevel(250);
  cout << "New power level of Optimus: " << optimus->GetPowerLevel() << endl;
  
  cout << "\n6. Test composition and association:" << endl;
  cout << "Optimus's weapon: " << optimus->GetWeapon()->GetName() 
            << " (damage: " << optimus->GetWeapon()->GetDamage() << ")" << endl;
  cout << "Megatron's alliance: " << megatron->GetAlliance()->GetName() 
            << " (leader: " << megatron->GetAlliance()->GetLeader() << ")" << endl;
  
  cout << "\nTest operator <<" << endl;
  cout << "Autobot alliance: " << *autobotAlliance << endl;      
  cout << "Weapon: " << *optimus->GetWeapon() << endl;  // Используем оружие Оптимуса      
  cout << "Optimus Prime: "<< *optimus << endl;
  
  //TestConstructorOverloading();

  TestVirtualMethods();
  
  cout << "\nDESTROYING OBJECTS" << endl;
  delete optimus;
  delete megatron;
  delete grimlock;
  delete autobotAlliance;
  delete decepticonAlliance;
  
  return 0;
}