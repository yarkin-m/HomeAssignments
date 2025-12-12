#include "transformers/Weapon.h"

namespace transformers {

Weapon::Weapon(const std::string& name, int damage, const std::string& type)
    : name_(name), damage_(damage), type_(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::GetName() const { return name_; }
int Weapon::GetDamage() const { return damage_; }
const std::string& Weapon::GetType() const { return type_; }

void Weapon::SetName(const std::string& name) { name_ = name; }
void Weapon::SetDamage(int damage) { damage_ = damage; }
void Weapon::SetType(const std::string& type) { type_ = type; }

std::string Weapon::Attack() const {
  return name_ + " attacks with " + std::to_string(damage_) + " damage!";
}

bool Weapon::IsPowerful() const { return damage_ > 50; }

}