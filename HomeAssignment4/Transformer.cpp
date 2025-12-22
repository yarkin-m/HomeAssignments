/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#include "Transformer.h"
#include <iostream>
#include <string>


using namespace std;

Transformer::Transformer(const string& name, int height, int weight,
                         int power_level, std::unique_ptr<Weapon> weapon, Alliance* alliance): 
    name_(name),
    height_(height),
    weight_(weight),
    power_level_(power_level),
    weapon_(weapon),
    alliance_(alliance) {
        cout << "Transformer " << name_ << " created" << endl;
}

Transformer::Transformer(const string& name)
    : name_(name),
      height_(10),        
      weight_(5),
      power_level_(100),
      weapon_(nullptr),
      alliance_(nullptr) {
    cout << "Transformer " << name_ << " created (simple constructor)" << endl;
}

Transformer::Transformer(const string& name, int power_level)
    : name_(name),
      height_(10),
      weight_(5),
      power_level_(power_level),
      weapon_(nullptr),
      alliance_(nullptr) {
    cout << "Transformer " << name_ << " created (power: " << power_level_ << ")" << endl;
}

Transformer::Transformer(const Transformer& other)
    : name_(other.name_ + " (copy)"),
      height_(other.height_),
      weight_(other.weight_),
      power_level_(other.power_level_),
      weapon_(other.weapon_ ? new Weapon(*other.weapon_) : nullptr),
      alliance_(other.alliance_) {
    cout << "Copy of transformer " << name_ << " created" << endl;
}

Transformer::~Transformer() {
  cout << "Transformer " << name_ << " destroyed" << endl;
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

//setters
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
  return name_ + " transforms";
}
  
string Transformer::Attack() {
  return name_ + " attacks with power " + to_string(power_level_);
}
*/
//virtual methods
void Transformer::ShowInfo() const {
    cout << "Transformer::ShowInfo() - base class" << endl;
    cout << "Name: " << name_ << ", Power: " << power_level_ << endl;
}

void Transformer::BattleCry() const {
    cout << "Transformer::BattleCry() - base class" << endl;
    cout << name_ << ": For freedom and justice!" << endl;
}

void Transformer::Transform() const {
    cout << "Transformer::Transform() - base class" << endl;
    cout << name_ << " starts transformation..." << endl;
}

void Transformer::Repair() const {
    cout << "Transformer::Repair() - base class" << endl;
    cout << name_ << " undergoes basic repair" << endl;
}

string Transformer::GetInfo() const {
    return "Name: " + name_ + 
         ", \nHeight: " + std::to_string(height_) + "m" +
         ", \nWeight: " + std::to_string(weight_) + "t" +
         ", \nPower: " + std::to_string(power_level_) + "\n";
}

ostream& operator<<(std::ostream& os, const Transformer& transformer) {
    os << transformer.GetInfo();
    return os;
}