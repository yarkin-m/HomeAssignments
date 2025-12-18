#include "Transformer.h"
#include <iostream>
#include <string>

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

Transformer::Transformer(const string& name)
    : name_(name),
      height_(10),        
      weight_(5),
      power_level_(100),
      weapon_(nullptr),
      alliance_(nullptr) {
    cout << "Трансформер " << name_ << " создан (простой конструктор)" << endl;
}

Transformer::Transformer(const string& name, int power_level)
    : name_(name),
      height_(10),
      weight_(5),
      power_level_(power_level),
      weapon_(nullptr),
      alliance_(nullptr) {
    cout << "Трансформер " << name_ << " создан (мощность: " << power_level_ << ")" << endl;
}

Transformer::Transformer(const Transformer& other)
    : name_(other.name_ + " (копия)"),
      height_(other.height_),
      weight_(other.weight_),
      power_level_(other.power_level_),
      weapon_(other.weapon_ ? new Weapon(*other.weapon_) : nullptr),
      alliance_(other.alliance_) {
    cout << "Копия трансформера " << name_ << " создана" << endl;
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

/*
string Transformer::Transform() {
  return name_ + " трансформируется";
}
  
string Transformer::Attack() {
  return name_ + " атакует с силой " + to_string(power_level_);
}
*/
//virtualы
void Transformer::ShowInfo() const {
    cout << "Transformer::ShowInfo() - базовый класс" << endl;
    cout << "Имя: " << name_ << ", Мощность: " << power_level_ << endl;
}

void Transformer::BattleCry() const {
    cout << "Transformer::BattleCry() - базовый класс" << endl;
    cout << name_ << ": За свободу и справедливость!" << endl;
}

void Transformer::Transform() const {
    cout << "Transformer::Transform() - базовый класс" << endl;
    cout << name_ << " начинает трансформацию..." << endl;
}

void Transformer::Repair() const {
    cout << "Transformer::Repair() - базовый класс" << endl;
    cout << name_ << " проходит базовый ремонт" << endl;
}

string Transformer::GetInfo() const {
    return "Имя: " + name_ + 
         ", \nРост: " + std::to_string(height_) + "м" +
         ", \nВес: " + std::to_string(weight_) + "т" +
         ", \nМощность: " + std::to_string(power_level_) + "\n";
}

ostream& operator<<(std::ostream& os, const Transformer& transformer) {
    os << transformer.GetInfo();
    return os;
}