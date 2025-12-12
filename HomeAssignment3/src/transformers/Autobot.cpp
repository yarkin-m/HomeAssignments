#include "transformers/Autobot.h"

namespace transformers {

Autobot::Autobot(const std::string& name, int height, int weight,
                 int power_level, Weapon* weapon, Alliance* alliance,
                 const std::string& vehicle_mode, int courage_level,
                 bool is_leader)
    : Transformer(name, height, weight, power_level, weapon, alliance),
      vehicle_mode_(vehicle_mode), courage_level_(courage_level),
      is_leader_(is_leader) {}

const std::string& Autobot::GetVehicleMode() const { return vehicle_mode_; }
int Autobot::GetCourageLevel() const { return courage_level_; }
bool Autobot::GetIsLeader() const { return is_leader_; }

void Autobot::SetVehicleMode(const std::string& vehicle_mode) {
  vehicle_mode_ = vehicle_mode;
}

void Autobot::SetCourageLevel(int courage_level) {
  courage_level_ = courage_level;
}

void Autobot::SetIsLeader(bool is_leader) { is_leader_ = is_leader; }

std::string Autobot::Defend() const {
  return name_ + " defends with courage!";
}

std::string Autobot::GetType() const { return "Autobot"; }

std::string Autobot::Introduce() const {
  return Transformer::Introduce() + " of type Autobot";
}

}