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
            cout << "Autobot " << name << " created" << endl;
}

Autobot::Autobot(const string& name): 
      Transformer(name),  
      vehicle_form_("car"),
      courage_level_(50) {
    cout << "Autobot " << GetName() << " created (simple constructor)" << endl;
}

Autobot::Autobot(const string& name, const string& vehicle_form)
    : Transformer(name, 150), 
      vehicle_form_(vehicle_form),
      courage_level_(75) {
    cout << "Autobot " << GetName() << " created (form: " << vehicle_form_ << ")" << endl;
}

Autobot::Autobot(const Autobot& other): 
      Transformer(other), 
      vehicle_form_(other.vehicle_form_),
      courage_level_(other.courage_level_) {
    cout << "Copy of autobot " << GetName() << " created" << endl;
}

string Autobot::GetVehicleForm() const {
    return vehicle_form_;
}

int Autobot::GetCourageLevel() const {
  return courage_level_;
}

//setters
void Autobot::SetVehicleForm(const string& vehicle_form) {
  vehicle_form_ = vehicle_form;
}

void Autobot::SetCourageLevel(int courage_level) {
  courage_level_ = courage_level;
}

//virtual methods
void Autobot::SpecialAbility() const {
    std::cout << "Autobot::SpecialAbility() - Autobot class" << endl;
    std::cout << GetName() << " uses Matrix of Leadership!" << endl;
}

void Autobot::ShowInfo() const {
    cout << "Autobot::ShowInfo() - Autobot class" << endl;
    cout << GetName() << " - Autobot. Form: " << vehicle_form_ << ", Courage: " << courage_level_ << endl;
}

void Autobot::BattleCry() const {
    cout << "Autobot::BattleCry() - Autobot class" << endl;
    cout << GetName() << ": 'Autobots, attack! For freedom!'" << endl;
}

void Autobot::Transform() const {
    cout << "Autobot::Transform() - Autobot class" << endl;
    cout << GetName() << " transforms into " << vehicle_form_ << endl;
}

void Autobot::ProtectHumans() const {
    cout << "Autobot::ProtectHumans() - Autobot class" << endl;
    cout << GetName() << " protects humans with courage " << courage_level_ << endl;
}

//additional methods
/*
string Autobot::ProtectHumans() {
  return GetName() + " protects people with courage level " + to_string(courage_level_);
}

string Autobot::Transform() {
  return GetName() + " transforms into " + vehicle_form_;
}*/