/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#include "Dinobot.h"
#include <iostream>

using namespace std;

Dinobot::Dinobot(const string& name, int height, int weight, int power_level, 
                 std::unique_ptr<Weapon> weapon, Alliance* alliance,
                 const string& dinosaur_form, int roar_power): 
        Transformer(name, height, weight, power_level, std::move(weapon), alliance),
        dinosaur_form_(dinosaur_form),
        roar_power_(roar_power) {
            cout << "Динобот " << name << " создан" << endl;
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

string Dinobot::Roar() {
  return GetName() + " рычит с мощностью " + to_string(roar_power_) +
         " децибел";
}

string Dinobot::Transform() {
  return GetName() + " превращается в " + dinosaur_form_;
}