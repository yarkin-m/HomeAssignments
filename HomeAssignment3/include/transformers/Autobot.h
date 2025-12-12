#ifndef TRANSFORMERS_AUTOBOT_H_
#define TRANSFORMERS_AUTOBOT_H_

#include "transformers/Transformer.h"
#include <string>

namespace transformers {

class Autobot : public Transformer {
 public:
  Autobot(const std::string& name = "Autobot",
          int height = 10,
          int weight = 30,
          int power_level = 100,
          Weapon* weapon = nullptr,
          Alliance* alliance = nullptr,
          const std::string& vehicle_mode = "Truck",
          int courage_level = 50,
          bool is_leader = false);
  
  const std::string& GetVehicleMode() const;
  int GetCourageLevel() const;
  bool GetIsLeader() const;
  
  void SetVehicleMode(const std::string& vehicle_mode);
  void SetCourageLevel(int courage_level);
  void SetIsLeader(bool is_leader);
  
  std::string Defend() const;
  std::string GetType() const override;
  std::string Introduce() const override;

 private:
  std::string vehicle_mode_;
  int courage_level_;
  bool is_leader_;
};

}

#endif