#include "transformers/Dinobot.h"

namespace transformers {

Dinobot::Dinobot(const std::string& name, int height, int weight,
                 int power_level, Weapon* weapon, Alliance* alliance,
                 const std::string& dinosaur_form, int roar_power,
                 bool can_swim)
    : Transformer(name, height, weight, power_level, weapon, alliance),
      dinosaur_form_(dinosaur_form), roar_power_(roar_power),
      can_swim_(can_swim) {}

const std::string& Dinobot::GetDinosaurForm() const { return dinosaur_form_; }
int Dinobot::GetRoarPower() const { return roar_power_; }
bool Dinobot::GetCanSwim() const { return can_swim_; }

void Dinobot::SetDinosaurForm(const std::string& dinosaur_form) {
  dinosaur_form_ = dinosaur_form;
}

void Dinobot::SetRoarPower(int roar_power) { roar_power_ = roar_power; }
void Dinobot::SetCanSwim(bool can_swim) { can_swim_ = can_swim; }

std::string Dinobot::Roar() const {
  return name_ + " roars with power " + std::to_string(roar_power_) + "!";
}

std::string Dinobot::GetType() const { return "Dinobot"; }

}