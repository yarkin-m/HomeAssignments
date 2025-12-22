/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include "Decepticon.h"
#include <iostream>
#include <string>

using namespace std;

Decepticon::Decepticon(const string& name, int height, int weight,int power_level, Weapon* weapon, Alliance* alliance,
        const string& flying_form, bool has_wings): 
    Transformer(name, height, weight, power_level, weapon, alliance),
    flying_form_(flying_form),
    has_wings_(has_wings) {
        cout << "Decepticon " << name << " created" << endl;
}

Decepticon::Decepticon(const string& name): 
      Transformer(name),  
      flying_form_("airplane"),
      has_wings_(true) {
    cout << "Decepticon " << GetName() << " created (simple constructor)" << endl;
}

Decepticon::Decepticon(const string& name, const string& flying_form): 
      Transformer(name),  
      flying_form_(flying_form),
      has_wings_(true) {
    cout << "Decepticon " << GetName() << " created" << endl;
}

Decepticon::Decepticon(const Decepticon& other): 
      Transformer(other), 
      flying_form_(other.flying_form_),
      has_wings_(other.has_wings_) {
    cout << "Copy of decepticon " << GetName() << " created" << endl;
}


string Decepticon::GetFlyingForm() const {
  return flying_form_;
}

bool Decepticon::GetHasWings() const {
  return has_wings_;
}


void Decepticon::SetFlyingForm(const string& flying_form) {
  flying_form_ = flying_form;
}

void Decepticon::SetHasWings(bool has_wings) {
  has_wings_ = has_wings;
}


void Decepticon::SpecialAbility() const {
    cout << "Decepticon::SpecialAbility() - Decepticon class" << endl;
    cout << GetName() << " uses Dark Energon!" << endl;
}

void Decepticon::ShowInfo() const {
    cout << "Decepticon::ShowInfo() - Decepticon class" << endl;
    cout << GetName() << " - Decepticon. Flying form: " << flying_form_ 
              << ", Wings: " << (has_wings_ ? "yes" : "no") << endl;
}

void Decepticon::BattleCry() const {
    cout << "Decepticon::BattleCry() - Decepticon class" << endl;
    cout << GetName() << ": 'Decepticons, destroy the Autobots!'" << endl;
}

void Decepticon::Transform() const {
    cout << "Decepticon::Transform() - Decepticon class" << endl;
    cout << GetName() << " transforms into " << flying_form_ << endl;
}

void Decepticon::Terrorize() const {
    cout << "Decepticon::Terrorize() - Decepticon class" << endl;
    cout << GetName() << " spreads fear and destruction!" << endl;
}

/*
string Decepticon::Terrorize() {
  return GetName() + " spreads terror with aerial form " + flying_form_;
}

string Decepticon::Attack() {
  string wing_info = has_wings_ ? " with wings" : " without wings";
  return GetName() + " attacks" + wing_info;
}

string Decepticon::Transform() {
  return GetName() + " transforms into " + flying_form_;
}*/