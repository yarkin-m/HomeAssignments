#include "transformers/Decepticon.h"

namespace transformers {

Decepticon::Decepticon(const std::string& name, int height, int weight,
                       int power_level, Weapon* weapon, Alliance* alliance,
                       const std::string& flight_mode, int aggression_level,
                       bool has_stealth)
    : Transformer(name, height, weight, power_level, weapon, alliance),
      flight_mode_(flight_mode), aggression_level_(aggression_level),
      has_stealth_(has_stealth) {}

const std::string& Decepticon::GetFlightMode() const { return flight_mode_; }
int Decepticon::GetAggressionLevel() const { return aggression_level_; }
bool Decepticon::GetHasStealth() const { return has_stealth_; }

void Decepticon::SetFlightMode(const std::string& flight_mode) {
  flight_mode_ = flight_mode;
}

void Decepticon::SetAggressionLevel(int aggression_level) {
  aggression_level_ = aggression_level;
}

void Decepticon::SetHasStealth(bool has_stealth) { has_stealth_ = has_stealth; }

std::string Decepticon::Attack() const {
  return name_ + " attacks with aggression!";
}

std::string Decepticon::GetType() const { return "Decepticon"; }

}