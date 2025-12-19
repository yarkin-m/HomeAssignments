#include <iostream>
#include "Alliance.h"
#include "Weapon.h"
#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include <vector>

using namespace std;
/*
void TestConstructorOverloading() {
    cout << "Тест перегрузки" << endl;
    
    cout << "\n1. КОНСТРУКТОРЫ TRANSFORMER:" << endl;
    cout << "1.1 Простой конструктор (только имя):" << endl;
    Transformer t1("Простой трансформер");
    cout << "   " << t1 << endl;

    cout << "\n1.2 Конструктор с именем и мощностью:" << endl;
    Transformer t2("Мощный", 500);
    cout << "   " << t2 << endl;

    cout << "\n1.3 Конструктор копирования:" << endl;
    Transformer t3 = t2;  
    cout << "   Оригинал: " << t2.GetName() << endl;
    cout << "   Копия: " << t3 << endl;
    
    cout << "\n1.4 Проверка Deep Copy (изменяем оригинал):" << endl; // показать что это не swallow
    t2.SetPowerLevel(999);
    cout << "   Оригинал мощность: " << t2.GetPowerLevel() << endl;
    cout << "   Копия мощность: " << t3.GetPowerLevel() << " (не изменилась!)" << endl;
    

    //АВТОБОТЫ
    cout << "\n\n2. КОНСТРУКТОРЫ AUTOBOT:" << endl;
    
    cout << "2.1 Простой конструктор:" << endl;
    Autobot a1("Бамблби");
    cout << "   " << a1 << endl;
    cout << "   Форма: " << a1.GetVehicleForm() << endl;
    cout << "   Храбрость: " << a1.GetCourageLevel() << endl;
    
    cout << "\n2.2 Конструктор с именем и формой:" << endl;
    Autobot a2("Джаз", "спорткар");
    cout << "   " << a2 << endl;
    cout << "   Форма: " << a2.GetVehicleForm() << endl;
    
    cout << "\n2.3 Конструктор копирования:" << endl;
    Autobot a3 = a2;
    cout << "   Копия: " << a3 << endl;
    cout << "   Форма копии: " << a3.GetVehicleForm() << endl;
    


    //ДЕСЕПТИКОНЫ
    cout << "\n\n3. КОНСТРУКТОРЫ DECEPTICON:" << endl;
    
    cout << "3.1 Простой конструктор:" << endl;
    Decepticon d1("Старскрим");
    cout << "   " << d1 << endl;
    cout << "   Форма: " << d1.GetFlyingForm() << endl;
    cout << "   Крылья: " << (d1.GetHasWings() ? "есть" : "нет") << endl;
    
    cout << "\n3.2 Конструктор с именем и формой:" << endl;
    Decepticon d2("Саундвейв", "кассетник");
    cout << "   " << d2 << endl;
    cout << "   Форма: " << d2.GetFlyingForm() << endl;
    
    cout << "\n3.3 Конструктор копирования:" << endl;
    Decepticon d3 = d1;
    cout << "   Копия: " << d3 << endl;
    cout << "   Форма копии: " << d3.GetFlyingForm() << endl;
    


    //ДИНОБОТЫ
    cout << "\n\n4. КОНСТРУКТОРЫ DINOBOT:" << endl;
    cout << string(30, '-') << endl;
    
    cout << "4.1 Простой конструктор:" << endl;
    Dinobot dn1("Слэг");
    cout << "   " << dn1 << endl;
    cout << "   Форма: " << dn1.GetDinosaurForm() << endl;
    cout << "   Сила рыка: " << dn1.GetRoarPower() << endl;
    
    cout << "\n4.2 Конструктор с именем и формой:" << endl;
    Dinobot dn2("Снарл", "саблезуб");
    cout << "   " << dn2 << endl;
    cout << "   Форма: " << dn2.GetDinosaurForm() << endl;
    
    cout << "\n4.3 Конструктор копирования:" << endl;
    Dinobot dn3 = dn1;
    cout << "   Копия: " << dn3 << endl;
    cout << "   Форма копии: " << dn3.GetDinosaurForm() << endl;
    

    //Разные конструкторы
    cout << "\n\n5. МАССИВ ОБЪЕКТОВ (разные конструкторы):" << endl;
    
    Transformer* army[6];
    
    army[0] = new Transformer("Базовый1");
    army[1] = new Transformer("Базовый2", 350);
    
    army[2] = new Autobot("Рэтчет");
    army[3] = new Autobot("Айронхайд", "внедорожник");
    
    army[4] = new Decepticon("Шоквейв");
    army[5] = new Dinobot("Свип");
    
    cout << "\nИнформация о армии:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "  " << i+1 << ". " << *army[i] << endl;
    }
    
    cout << "\nОчищаем память..." << endl;
    for (int i = 0; i < 6; i++) {
        delete army[i];
    }
    
    //Сложное копирование
    cout << "\n\n6. СЛОЖНОЕ КОПИРОВАНИЕ (с оружием и альянсами):" << endl;

    Alliance* testAlliance = new Alliance("Тестовый", "Лидер");
    Weapon* testWeapon = new Weapon("Тестовое оружие", 75);
    
    Autobot original("Оригинал", 12, 6, 180, testWeapon, testAlliance, "грузовик", 85);
    cout << "Создан оригинал: " << original << endl;
    cout << "Оружие оригинала: " << original.GetWeapon()->GetName() << endl;
    
    Autobot copy = original;
    cout << "Создана копия: " << copy << endl;
    
    cout << "\nПроверка Deep Copy оружия:" << endl;
    cout << "Адрес оружия оригинала: " << original.GetWeapon() << endl;
    cout << "Адрес оружия копии: " << copy.GetWeapon() << endl;
    
    copy.GetWeapon()->SetDamage(100);
    cout << "\nИзменяем урон оружия копии на 100..." << endl;
    cout << "Урон оружия оригинала: " << original.GetWeapon()->GetDamage() << " (не изменился!)" << endl;
    cout << "Урон оружия копии: " << copy.GetWeapon()->GetDamage() << endl;
    
    delete testAlliance;
    delete testWeapon;
  }
*/
void TestVirtualMethods() {

    cout << "ТЕСТ ВИРТУАЛЬНЫХ МЕТОДОВ" << endl;
    
    cout << "\n1. ПРЯМОЙ ВЫЗОВ МЕТОДОВ:" << endl;
    
    Autobot optimus("Оптимус Прайм", "грузовик");
    Decepticon megatron("Мегатрон", "самолет");
    Dinobot grimlock("Гримлок", "тираннозавр");
    
    cout << "\nА) Autobot методы:" << endl;
    optimus.ShowInfo();
    optimus.BattleCry();
    optimus.Transform();
    optimus.SpecialAbility(); 
    optimus.Repair();          
    optimus.ProtectHumans();   
    
    cout << "\nБ) Decepticon методы:" << endl;
    megatron.ShowInfo();
    megatron.BattleCry();
    megatron.Transform();
    megatron.SpecialAbility();
    megatron.Repair();
    megatron.Terrorize();
    
    cout << "\nВ) Dinobot методы:" << endl;
    grimlock.ShowInfo();
    grimlock.BattleCry();
    grimlock.Transform();
    grimlock.SpecialAbility();
    grimlock.Repair();
    grimlock.Roar();
    
    cout << "\n\n2. ВЫЗОВ ЧЕРЕЗ УКАЗАТЕЛЬ НА БАЗОВЫЙ КЛАСС:" << endl;
    
    Transformer* army[3];
    army[0] = &optimus;
    army[1] = &megatron;
    army[2] = &grimlock;
    
    for (int i = 0; i < 3; i++) {
        cout << "\nБоец #" << (i + 1) << ":" << endl;
        army[i]->ShowInfo();       
        army[i]->BattleCry();      
        army[i]->Transform();      
        army[i]->SpecialAbility(); 
        army[i]->Repair();         
    }
    
    cout << "\n\n3. ВЕКТОР ИЗ 9 ОБЪЕКТОВ (3 каждого типа):" << endl;
    
    vector<Transformer*> bigArmy;
    

    bigArmy.push_back(new Autobot("Оптимус", "грузовик"));
    bigArmy.push_back(new Autobot("Бамблби", "машина"));
    bigArmy.push_back(new Autobot("Джаз", "спорткар"));
    
    bigArmy.push_back(new Decepticon("Мегатрон", "пистолет"));
    bigArmy.push_back(new Decepticon("Старскрим", "истребитель"));
    bigArmy.push_back(new Decepticon("Саундвейв", "кассетник"));
    
    bigArmy.push_back(new Dinobot("Гримлок", "тираннозавр"));
    bigArmy.push_back(new Dinobot("Слэг", "трицератопс"));
    bigArmy.push_back(new Dinobot("Снарл", "саблезуб"));
    

    for (size_t i = 0; i < bigArmy.size(); i++) {
        cout << "\n--- Боец #" << (i + 1) << " ---" << endl;
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

  Alliance* autobotAlliance = new Alliance("Автоботы", "Оптимус Прайм");
  Alliance* decepticonAlliance = new Alliance("Десептиконы", "Мегатрон");
  
  Weapon* axe = new Weapon("Топор", 80);
  Weapon* cannon = new Weapon("Пушка", 120);
  Weapon* sword = new Weapon("Меч", 90);
  
  Autobot* optimus = new Autobot("Оптимус Прайм", 15, 8, 200, axe, autobotAlliance, "грузовик", 95);
  
  Decepticon* megatron = new Decepticon("Мегатрон", 14, 9, 180, cannon, decepticonAlliance, "самолет", true);
  
  Dinobot* grimlock = new Dinobot("Гримлок", 12, 10, 220, sword, autobotAlliance, "тираннозавр", 150);
  
  cout << "\nТЕСТИРОВАНИЕ" << endl;
  /*
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
  */
  cout << "\nТесты 1-4 для задания 3" << endl;
  cout << "\n5. Тест get/set методов:" << endl;
  optimus->SetPowerLevel(250);
  cout << "Новая мощность Оптимуса: " << optimus->GetPowerLevel() << endl;
  
  cout << "\n6. Тест композиции и ассоциации:" << endl;
  cout << "Оружие Оптимуса: " << optimus->GetWeapon()->GetName() 
            << " (урон: " << optimus->GetWeapon()->GetDamage() << ")" << endl;
  cout << "Альянс Мегатрона: " << megatron->GetAlliance()->GetName() 
            << " (лидер: " << megatron->GetAlliance()->GetLeader() << ")" << endl;
  
  cout << "\nТест оператора <<" << endl;
  cout << "Альянс автоботов: " <<*autobotAlliance << endl;      
  cout << "Оружие: " << *sword << endl;         
  cout << "Оптимус прайм: "<< *optimus << endl;
  
  //TestConstructorOverloading();

  TestVirtualMethods();
  
  cout << "\nУНИЧТОЖЕНИЕ ОБЪЕКТОВ" << endl;
  delete optimus;
  delete megatron;
  delete grimlock;
  delete autobotAlliance;
  delete decepticonAlliance;
  
  return 0;
}