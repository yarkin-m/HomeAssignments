#include "Weapon.h"
#include <iostream>
#include <string>

using namespace std;

Weapon::Weapon(const string& name, int damage):
    name_(name), damage_(damage) {
    cout << "Оружие " << name_ << " создано" << endl;
}

Weapon::~Weapon() {
    cout << "Оружие " << name_ << " уничтожено" << endl;
}

string Weapon::GetName() const {
    return name_;
}

int Weapon::GetDamage() const {
    return damage_;
}

void Weapon::SetName(const string& name) {
  name_ = name;
}

void Weapon::SetDamage(int damage) {
  damage_ = damage;
}

ostream& operator<<(ostream& os, const Weapon& weapon) {
    os << "Оружие: " << weapon.name_ << " (Урон: " << weapon.damage_ << ")";
    return os;
}