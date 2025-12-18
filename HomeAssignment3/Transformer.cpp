#include "Transformer.h"
#include <iostream>

using namespace std;

Transformer::Transformer(const string& name, int height, int weight,
                         int power_level, Weapon* weapon, Alliance* alliance): 
    name_(name),
    height_(height),
    weight_(weight),
    power_level_(power_level),
    weapon_(weapon),
    alliance_(alliance) {
        cout << "Трансформер " << name_ << " создан" << endl;
}

Transformer::~Transformer() {
  cout << "Трансформер " << name_ << " уничтожен" << endl;
  delete weapon_;
}

string Transformer::GetName() const {
  return name_;
}

int Transformer::GetHeight() const {
  return height_;
}

int Transformer::GetWeight() const {
  return weight_;
}

int Transformer::GetPowerLevel() const {
  return power_level_;
}

Weapon* Transformer::GetWeapon() const {
  return weapon_;
}

Alliance* Transformer::GetAlliance() const {
  return alliance_;
}

//setы
void Transformer::SetName(const std::string& name) {
  name_ = name;
}

void Transformer::SetHeight(int height) {
  height_ = height;
}

void Transformer::SetWeight(int weight) {
  weight_ = weight;
}

void Transformer::SetPowerLevel(int power_level) {
  power_level_ = power_level;
}

void Transformer::SetWeapon(Weapon* weapon) {
  weapon_ = weapon;
}

void Transformer::SetAlliance(Alliance* alliance) {
  alliance_ = alliance;
}

//virtualы
string Transformer::Transform() {
  return name_ + " трансформируется";
}

string Transformer::Attack() {
  return name_ + " атакует с силой " + to_string(power_level_);
}

string Transformer::GetInfo() const {
    return "Имя: " + name_ + 
         ", \nРост: " + std::to_string(height_) + "м" +
         ", \nВес: " + std::to_string(weight_) + "т" +
         ", \nМощность: " + std::to_string(power_level_) + "\n";
}