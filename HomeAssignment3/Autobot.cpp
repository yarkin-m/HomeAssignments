/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include "Autobot.h"
#include <iostream>

using namespace std;

Autobot::Autobot(const std::string& name, int height, int weight, int power_level, Weapon* weapon, Alliance* alliance, 
    const std::string& vehicle_form, int courage_level):
        Transformer(name, height, weight, power_level, weapon, alliance),
        vehicle_form_(vehicle_form), courage_level_(courage_level) {
            cout << "Автобот " << name << " создан" << endl;
}

string Autobot::GetVehicleForm() const {
    return vehicle_form_;
}

int Autobot::GetCourageLevel() const {
  return courage_level_;
}

//setы
void Autobot::SetVehicleForm(const std::string& vehicle_form) {
  vehicle_form_ = vehicle_form;
}

void Autobot::SetCourageLevel(int courage_level) {
  courage_level_ = courage_level;
}

//доп.
string Autobot::ProtectHumans() {
  return GetName() + " защищает людей с уровнем храбрости " + to_string(courage_level_);
}

std::string Autobot::Transform() {
  return GetName() + " трансформируется в " + vehicle_form_;
}