/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#ifndef TRANSFORMERS_AUTOBOT_H
#define TRANSFORMERS_AUTOBOT_H

#include "Transformer.h"
#include <string>
#include <memory>  

// наследник Автобот
class Autobot : public Transformer {
 public:
  Autobot(const std::string& name, int height, int weight, int power_level, 
          std::unique_ptr<Weapon> weapon, Alliance* alliance,  
          const std::string& vehicle_form, int courage_level);

  std::string GetVehicleForm() const;
  int GetCourageLevel() const;

  void SetVehicleForm(const std::string& vehicle_form);
  void SetCourageLevel(int courage_level);

  std::string ProtectHumans();
  
  std::string Transform() override;

 private:
  std::string vehicle_form_;
  int courage_level_;
};

#endif