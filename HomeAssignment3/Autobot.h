/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#ifndef TRANSFORMERS_AUTOBOT_H
#define TRANSFORMERS_AUTOBOT_H

#include "Transformer.h"
#include <string>
#include <memory> 

// Autobot
class Autobot : public Transformer {
 public:
  Autobot(const std::string& name, int height, int weight, int power_level, std::unique_ptr<Weapon> weapon, Alliance* alliance, 
          const std::string& vehicle_form, int courage_level);
  Autobot(const std::string& name);
  Autobot(const std::string& name, const std::string& vehicle_form);
  Autobot(const Autobot& other);

  std::string GetVehicleForm() const;
  int GetCourageLevel() const;

  void SetVehicleForm(const std::string& vehicle_form);
  void SetCourageLevel(int courage_level);

  void SpecialAbility() const override;
  void ShowInfo() const override;
  void BattleCry() const override;
  void Transform() const override;
  virtual void ProtectHumans() const;

  //std::string ProtectHumans();
  
  //std::string Transform() override;

 private:
  std::string vehicle_form_;
  int courage_level_;
};

#endif