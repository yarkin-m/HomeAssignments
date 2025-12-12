#ifndef TRANSFORMERS_DINOBOT_H_
#define TRANSFORMERS_DINOBOT_H_

#include "transformers/Transformer.h"
#include <string>

namespace transformers {

class Dinobot : public Transformer {
 public:
  Dinobot(const std::string& name = "Dinobot",
          int height = 8,
          int weight = 25,
          int power_level = 90,
          Weapon* weapon = nullptr,
          Alliance* alliance = nullptr,
          const std::string& dinosaur_form = "T-Rex",
          int roar_power = 80,
          bool can_swim = false);
  
  const std::string& GetDinosaurForm() const;
  int GetRoarPower() const;
  bool GetCanSwim() const;
  
  void SetDinosaurForm(const std::string& dinosaur_form);
  void SetRoarPower(int roar_power);
  void SetCanSwim(bool can_swim);
  
  std::string Roar() const;
  std::string GetType() const override;

 private:
  std::string dinosaur_form_;
  int roar_power_;
  bool can_swim_;
};

}

#endif