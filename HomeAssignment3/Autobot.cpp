/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#include "Autobot.h"
#include <iostream>

using namespace std;

Autobot::Autobot(const std::string& name, int height, int weight, int power_level, 
                 std::unique_ptr<Weapon> weapon, Alliance* alliance, 
                 const std::string& vehicle_form, int courage_level):
        Transformer(name, height, weight, power_level, std::move(weapon), alliance),
        vehicle_form_(vehicle_form), courage_level_(courage_level) {
            cout << "Autobot " << name << " created" << endl;
}

string Autobot::GetVehicleForm() const {
    return vehicle_form_;
}

int Autobot::GetCourageLevel() const {
  return courage_level_;
}

//setters
void Autobot::SetVehicleForm(const std::string& vehicle_form) {
  vehicle_form_ = vehicle_form;
}

void Autobot::SetCourageLevel(int courage_level) {
  courage_level_ = courage_level;
}

//additional methods
string Autobot::ProtectHumans() {
  return GetName() + " protects people with courage level " + to_string(courage_level_);
}

std::string Autobot::Transform() {
  return GetName() + " transforms into " + vehicle_form_;
}