/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include "Dinobot.h"
#include <iostream>
#include <string>

using namespace std;

Dinobot::Dinobot(const string& name, int height, int weight, int power_level, Weapon* weapon, Alliance* alliance,
    const string& dinosaur_form, int roar_power): 
        Transformer(name, height, weight, power_level, weapon, alliance),
        dinosaur_form_(dinosaur_form),
        roar_power_(roar_power) {
            cout << "Динобот " << name << " создан" << endl;
}

Dinobot::Dinobot(const string& name): 
      Transformer(name),  
      dinosaur_form_("тирекс"),
      roar_power_(70) {
    cout << "Динобот " << GetName() << " создан (простой конструктор)" << endl;
}

Dinobot::Dinobot(const string& name, const string& dinosaur_form): 
      Transformer(name),  
      dinosaur_form_(dinosaur_form),
      roar_power_(70) {
    cout << "Динобот " << GetName() << " создан" << endl;
}

Dinobot::Dinobot(const Dinobot& other): 
      Transformer(other),  
      dinosaur_form_(other.dinosaur_form_),
      roar_power_(other.roar_power_) {
    cout << "Копия динобота " << GetName() << " создана" << endl;
}


string Dinobot::GetDinosaurForm() const {
  return dinosaur_form_;
}


int Dinobot::GetRoarPower() const {
  return roar_power_;
}

void Dinobot::SetDinosaurForm(const string& dinosaur_form) {
  dinosaur_form_ = dinosaur_form;
}

void Dinobot::SetRoarPower(int roar_power) {
  roar_power_ = roar_power;
}


void Dinobot::SpecialAbility() const {
    cout << "Dinobot::SpecialAbility() - класс Динобот" << endl;
    cout << GetName() << " использует Древнюю Силу Динозавров!" << endl;
}

void Dinobot::ShowInfo() const {
    cout << "Dinobot::ShowInfo() - класс Динобот" << endl;
    cout << GetName() << " - Динобот. Форма динозавра: " << dinosaur_form_ 
              << ", Сила рыка: " << roar_power_ << endl;
}

void Dinobot::BattleCry() const {
    cout << "Dinobot::BattleCry() - класс Динобот" << endl;
    cout << GetName() << ": 'Р-Р-Р-Р-Р! Я король динозавров!'" << endl;
}

void Dinobot::Transform() const {
    cout << "Dinobot::Transform() - класс Динобот" << endl;
    cout << GetName() << " превращается в " << dinosaur_form_ << endl;
}

void Dinobot::Roar() const {
    cout << "Dinobot::Roar() - класс Динобот" << endl;
    cout << GetName() << " рычит с силой " << roar_power_ << " децибел!" << endl;
}

/*
string Dinobot::Roar() {
  return GetName() + " рычит с мощностью " + to_string(roar_power_) +
         " децибел";
}

string Dinobot::Transform() {
  return GetName() + " превращается в " + dinosaur_form_;
}*/