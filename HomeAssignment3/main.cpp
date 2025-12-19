/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#include <iostream>
#include <memory>
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"

using namespace std;

int main() {

  Alliance* autobotAlliance = new Alliance("Автоботы", "Оптимус Прайм");
  Alliance* decepticonAlliance = new Alliance("Десептиконы", "Мегатрон");
  
  auto axe = std::make_unique<Weapon>("Топор", 80);
  auto cannon = std::make_unique<Weapon>("Пушка", 120);
  auto sword = std::make_unique<Weapon>("Меч", 90);
  
  Autobot* optimus = new Autobot("Оптимус Прайм", 15, 8, 200, 
                                 std::move(axe), autobotAlliance, 
                                 "грузовик", 95);
  
  Decepticon* megatron = new Decepticon("Мегатрон", 14, 9, 180, 
                                        std::move(cannon), decepticonAlliance, 
                                        "самолет", true);
  
  Dinobot* grimlock = new Dinobot("Гримлок", 12, 10, 220, 
                                  std::move(sword), autobotAlliance, 
                                  "тираннозавр", 150);
  
  cout << "\nТЕСТИРОВАНИЕ" << endl;
  
  cout << "\n1. Информация о трансформерах:" << endl;
  cout << optimus->GetInfo() << endl;
  cout << megatron->GetInfo() << endl;
  cout << grimlock->GetInfo() << endl;
  
  cout << "\n2. Трансформации:" << endl;
  cout << optimus->Transform() << endl;
  cout << megatron->Transform() << endl;
  cout << grimlock->Transform() << endl;
  
  cout << "\n3. Атаки:" << endl;
  cout << optimus->Attack() << endl;
  cout << megatron->Attack() << endl;
  cout << grimlock->Attack() << endl;
  
  cout << "\n4. Специальные способности:" << endl;
  cout << optimus->ProtectHumans() << endl;
  cout << megatron->Terrorize() << endl;
  cout << grimlock->Roar() << endl;
  
  cout << "\n5. Тест get/set методов:" << endl;
  optimus->SetPowerLevel(250);
  cout << "Новая мощность Оптимуса: " << optimus->GetPowerLevel() << endl;
  
  cout << "\n6. Тест композиции и ассоциации:" << endl;
  cout << "Оружие Оптимуса: " << optimus->GetWeapon()->GetName() 
            << " (урон: " << optimus->GetWeapon()->GetDamage() << ")" << endl;
  cout << "Альянс Мегатрона: " << megatron->GetAlliance()->GetName() 
            << " (лидер: " << megatron->GetAlliance()->GetLeader() << ")" << endl;
  
  cout << "\nУНИЧТОЖЕНИЕ ОБЪЕКТОВ" << endl;
  delete optimus;
  delete megatron;
  delete grimlock;
  delete autobotAlliance;
  delete decepticonAlliance;
  
  return 0;
}