/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include "Weapon.h"
#include <iostream>
#include <string>

using namespace std;

Weapon::Weapon(const string& name, int damage):
    name_(name), damage_(damage) {
    cout << "Weapon " << name_ << " created" << endl;
}

Weapon::~Weapon() {
    cout << "Weapon " << name_ << " destroyed" << endl;
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
    os << "Weapon: " << weapon.name_ << " (Damage: " << weapon.damage_ << ")";
    return os;
}