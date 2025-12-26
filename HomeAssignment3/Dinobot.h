/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#ifndef TRANSFORMERS_DINOBOT_H
#define TRANSFORMERS_DINOBOT_H

#include "Transformer.h"
#include <string>
#include <memory>

// Dinobot
class Dinobot : public Transformer {
 public:
  Dinobot(const std::string& name, int height, int weight, int power_level,  std::unique_ptr<Weapon> weapon, Alliance* alliance, 
    const std::string& dinosaur_form, int roar_power);
  Dinobot(const std::string& name);
  Dinobot(const std::string& name, const std::string& dinosaur_form);
  Dinobot(const Dinobot& other);


  std::string GetDinosaurForm() const;
  int GetRoarPower() const;

  void SetDinosaurForm(const std::string& dinosaur_form);
  void SetRoarPower(int roar_power);
/*
  std::string Roar();
  
  std::string Transform() override;
*/
  
  void SpecialAbility() const override;
  void ShowInfo() const override;
  void BattleCry() const override;
  void Transform() const override;
  virtual void Roar() const;

 private:
  std::string dinosaur_form_;
  int roar_power_;
};

#endif