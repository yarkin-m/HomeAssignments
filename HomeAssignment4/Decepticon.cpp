#include "Decepticon.h"
#include <iostream>
#include <string>

using namespace std;

Decepticon::Decepticon(const string& name, int height, int weight,int power_level, Weapon* weapon, Alliance* alliance,
        const string& flying_form, bool has_wings): 
    Transformer(name, height, weight, power_level, weapon, alliance),
    flying_form_(flying_form),
    has_wings_(has_wings) {
        cout << "Десептикон " << name << " создан" << endl;
}

Decepticon::Decepticon(const string& name): 
      Transformer(name),  
      flying_form_("самолет"),
      has_wings_(true) {
    cout << "Десептикон " << GetName() << " создан (простой конструктор)" << endl;
}

Decepticon::Decepticon(const string& name, const string& flying_form): 
      Transformer(name),  
      flying_form_(flying_form),
      has_wings_(true) {
    cout << "Десептикон " << GetName() << " создан" << endl;
}

Decepticon::Decepticon(const Decepticon& other): 
      Transformer(other), 
      flying_form_(other.flying_form_),
      has_wings_(other.has_wings_) {
    cout << "Копия десептикона " << GetName() << " создана" << endl;
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
    cout << "Decepticon::SpecialAbility() - класс Десептикон" << endl;
    cout << GetName() << " использует Темную Энергию!" << endl;
}

void Decepticon::ShowInfo() const {
    cout << "Decepticon::ShowInfo() - класс Десептикон" << endl;
    cout << GetName() << " - Десептикон. Летающая форма: " << flying_form_ 
              << ", Крылья: " << (has_wings_ ? "есть" : "нет") << endl;
}

void Decepticon::BattleCry() const {
    cout << "Decepticon::BattleCry() - класс Десептикон" << endl;
    cout << GetName() << ": 'Десептиконы, уничтожить автоботов!'" << endl;
}

void Decepticon::Transform() const {
    cout << "Decepticon::Transform() - класс Десептикон" << endl;
    cout << GetName() << " трансформируется в " << flying_form_ << endl;
}

void Decepticon::Terrorize() const {
    cout << "Decepticon::Terrorize() - класс Десептикон" << endl;
    cout << GetName() << " сеет страх и разрушение!" << endl;
}

/*
string Decepticon::Terrorize() {
  return GetName() + " сеет террор с воздушной формой " + flying_form_;
}

string Decepticon::Attack() {
  string wing_info = has_wings_ ? " с крыльями" : " без крыльев";
  return GetName() + " атакует " + wing_info;
}

string Decepticon::Transform() {
  return GetName() + " трансформируется в " + flying_form_;
}*/