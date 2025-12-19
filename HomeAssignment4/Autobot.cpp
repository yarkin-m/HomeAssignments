/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include "Autobot.h"
#include <iostream>
#include <string>

using namespace std;

Autobot::Autobot(const string& name, int height, int weight, int power_level, Weapon* weapon, Alliance* alliance, 
    const string& vehicle_form, int courage_level):
        Transformer(name, height, weight, power_level, weapon, alliance),
        vehicle_form_(vehicle_form), courage_level_(courage_level) {
            cout << "Автобот " << name << " создан" << endl;
}

Autobot::Autobot(const string& name): 
      Transformer(name),  
      vehicle_form_("автомобиль"),
      courage_level_(50) {
    cout << "Автобот " << GetName() << " создан (простой конструктор)" << endl;
}

Autobot::Autobot(const string& name, const string& vehicle_form)
    : Transformer(name, 150), 
      vehicle_form_(vehicle_form),
      courage_level_(75) {
    cout << "Автобот " << GetName() << " создан (форма: " << vehicle_form_ << ")" << endl;
}

Autobot::Autobot(const Autobot& other): 
      Transformer(other), 
      vehicle_form_(other.vehicle_form_),
      courage_level_(other.courage_level_) {
    cout << "Копия автобота " << GetName() << " создана" << endl;
}

string Autobot::GetVehicleForm() const {
    return vehicle_form_;
}

int Autobot::GetCourageLevel() const {
  return courage_level_;
}

//setы
void Autobot::SetVehicleForm(const string& vehicle_form) {
  vehicle_form_ = vehicle_form;
}

void Autobot::SetCourageLevel(int courage_level) {
  courage_level_ = courage_level;
}

//virtualы
void Autobot::SpecialAbility() const {
    std::cout << "Autobot::SpecialAbility() - класс Автобот" << endl;
    std::cout << GetName() << " использует Матрицу Лидерства!" << endl;
}

void Autobot::ShowInfo() const {
    cout << "Autobot::ShowInfo() - класс Автобот" << endl;
    cout << GetName() << " - Автобот. Форма: " << vehicle_form_ << ", Храбрость: " << courage_level_ << endl;
}

void Autobot::BattleCry() const {
    cout << "Autobot::BattleCry() - класс Автобот" << endl;
    cout << GetName() << ": 'Автоботы, в атаку! Во имя свободы!'" << endl;
}

void Autobot::Transform() const {
    cout << "Autobot::Transform() - класс Автобот" << endl;
    cout << GetName() << " трансформируется в " << vehicle_form_ << endl;
}

void Autobot::ProtectHumans() const {
    cout << "Autobot::ProtectHumans() - класс Автобот" << endl;
    cout << GetName() << " защищает людей с храбростью " << courage_level_ << endl;
}

//доп.
/*
string Autobot::ProtectHumans() {
  return GetName() + " защищает людей с уровнем храбрости " + to_string(courage_level_);
}

string Autobot::Transform() {
  return GetName() + " трансформируется в " + vehicle_form_;
}*/