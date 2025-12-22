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
            cout << "Dinobot " << name << " created" << endl;
}

Dinobot::Dinobot(const string& name): 
      Transformer(name),  
      dinosaur_form_("T-rex"),
      roar_power_(70) {
    cout << "Dinobot " << GetName() << " created (simple constructor)" << endl;
}

Dinobot::Dinobot(const string& name, const string& dinosaur_form): 
      Transformer(name),  
      dinosaur_form_(dinosaur_form),
      roar_power_(70) {
    cout << "Dinobot " << GetName() << " created" << endl;
}

Dinobot::Dinobot(const Dinobot& other): 
      Transformer(other),  
      dinosaur_form_(other.dinosaur_form_),
      roar_power_(other.roar_power_) {
    cout << "Copy of dinobot " << GetName() << " created" << endl;
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
    cout << "Dinobot::SpecialAbility() - Dinobot class" << endl;
    cout << GetName() << " uses Ancient Dinosaur Power!" << endl;
}

void Dinobot::ShowInfo() const {
    cout << "Dinobot::ShowInfo() - Dinobot class" << endl;
    cout << GetName() << " - Dinobot. Dinosaur form: " << dinosaur_form_ 
              << ", Roar power: " << roar_power_ << endl;
}

void Dinobot::BattleCry() const {
    cout << "Dinobot::BattleCry() - Dinobot class" << endl;
    cout << GetName() << ": 'R-R-R-R-R! I am the king of dinosaurs!'" << endl;
}

void Dinobot::Transform() const {
    cout << "Dinobot::Transform() - Dinobot class" << endl;
    cout << GetName() << " transforms into " << dinosaur_form_ << endl;
}

void Dinobot::Roar() const {
    cout << "Dinobot::Roar() - Dinobot class" << endl;
    cout << GetName() << " roars with power " << roar_power_ << " decibels!" << endl;
}

/*
string Dinobot::Roar() {
  return GetName() + " roars with power " + to_string(roar_power_) +
         " decibels";
}

string Dinobot::Transform() {
  return GetName() + " transforms into " + dinosaur_form_;
}*/