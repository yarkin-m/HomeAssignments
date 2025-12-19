/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#ifndef TRANSFORMERS_DINOBOT_H
#define TRANSFORMERS_DINOBOT_H

#include "Transformer.h"
#include <string>

// наследник Динобот
class Dinobot : public Transformer {
 public:
  Dinobot(const std::string& name, int height, int weight, int power_level, Weapon* weapon, Alliance* alliance, 
    const std::string& dinosaur_form, int roar_power);

  std::string GetDinosaurForm() const;
  int GetRoarPower() const;

  void SetDinosaurForm(const std::string& dinosaur_form);
  void SetRoarPower(int roar_power);

  std::string Roar();
  
  std::string Transform() override;

 private:
  std::string dinosaur_form_;
  int roar_power_;
};

#endif