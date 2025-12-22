/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#include "Transformer.h"
#include <iostream>
#include <memory>

using namespace std;

Transformer::Transformer(const string& name, int height, int weight,
                         int power_level, std::unique_ptr<Weapon> weapon, Alliance* alliance): 
    name_(name),
    height_(height),
    weight_(weight),
    power_level_(power_level),
    weapon_(std::move(weapon)),
    alliance_(alliance) {
        cout << "Transformer " << name_ << " created" << endl;
}

Transformer::~Transformer() {
  cout << "Transformer " << name_ << " destroyed" << endl;
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
  return weapon_.get(); 
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

void Transformer::SetWeapon(std::unique_ptr<Weapon> weapon) {
  weapon_ = std::move(weapon);
}

void Transformer::SetAlliance(Alliance* alliance) {
  alliance_ = alliance;
}

//virtual methods
string Transformer::Transform() {
  return name_ + " transforms";
}

string Transformer::Attack() {
  if (weapon_) {
    return name_ + " attacks with " + weapon_->GetName() + 
           " for " + to_string(weapon_->GetDamage()) + " damage";
  }
  return name_ + " attacks with power " + to_string(power_level_);
}

string Transformer::GetInfo() const {
    string info = "Name: " + name_ + 
                ", \nHeight: " + std::to_string(height_) + "m" +
                ", \nWeight: " + std::to_string(weight_) + "t" +
                ", \nPower: " + std::to_string(power_level_);
    
    if (weapon_) {
        info += ", \nWeapon: " + weapon_->GetName() + 
               " (damage: " + std::to_string(weapon_->GetDamage()) + ")";
    }
    
    if (alliance_) {
        info += ", \nAlliance: " + alliance_->GetName() +
               " (leader: " + alliance_->GetLeader() + ")";
    }
    
    return info + "\n";
}