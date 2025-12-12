#include "transformers/Transformer.h"

namespace transformers {

Transformer::Transformer(const std::string& name, int height, int weight,
                         int power_level, Weapon* weapon, Alliance* alliance)
    : name_(name), height_(height), weight_(weight), power_level_(power_level),
      weapon_(weapon), alliance_(alliance) {}

Transformer::~Transformer() {}

const std::string& Transformer::GetName() const { return name_; }
int Transformer::GetHeight() const { return height_; }
int Transformer::GetWeight() const { return weight_; }
int Transformer::GetPowerLevel() const { return power_level_; }
Weapon* Transformer::GetWeapon() const { return weapon_; }
Alliance* Transformer::GetAlliance() const { return alliance_; }

void Transformer::SetName(const std::string& name) { name_ = name; }
void Transformer::SetHeight(int height) { height_ = height; }
void Transformer::SetWeight(int weight) { weight_ = weight; }
void Transformer::SetPowerLevel(int power_level) { power_level_ = power_level; }
void Transformer::SetWeapon(Weapon* weapon) { weapon_ = weapon; }
void Transformer::SetAlliance(Alliance* alliance) { alliance_ = alliance; }

std::string Transformer::Transform() const {
  return name_ + " is transforming!";
}

std::string Transformer::Introduce() const {
  return "I am " + name_ + ", a Transformer";
}

std::string Transformer::GetType() const {
  return "Generic Transformer";
}

bool Transformer::IsPowerful() const { return power_level_ > 100; }

}