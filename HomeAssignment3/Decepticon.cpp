#include "Decepticon.h"
#include <iostream>

using namespace std;

Decepticon::Decepticon(const string& name, int height, int weight,int power_level, 
                       std::unique_ptr<Weapon> weapon, Alliance* alliance,
                       const string& flying_form, bool has_wings): 
    Transformer(name, height, weight, power_level, std::move(weapon), alliance),
    flying_form_(flying_form),
    has_wings_(has_wings) {
        cout << "Десептикон " << name << " создан" << endl;
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

string Decepticon::Terrorize() {
  return GetName() + " сеет террор с воздушной формой " + flying_form_;
}

string Decepticon::Attack() {
  string wing_info = has_wings_ ? " с крыльями" : " без крыльев";
  return GetName() + " атакует " + wing_info;
}

string Decepticon::Transform() {
  return GetName() + " трансформируется в " + flying_form_;
}