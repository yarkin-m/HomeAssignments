/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#ifndef TRANSFORMERS_DECEPTICON_H
#define TRANSFORMERS_DECEPTICON_H

#include "Transformer.h"
#include <string>
#include <memory>  // добавлено для unique_ptr

// наследник Десептикон
class Decepticon : public Transformer {
 public:
  Decepticon(const std::string& name, int height, int weight, int power_level,
             std::unique_ptr<Weapon> weapon, Alliance* alliance,  // ИЗМЕНЕНО
             const std::string& flying_form, bool has_wings);

  std::string GetFlyingForm() const;
  bool GetHasWings() const;

  void SetFlyingForm(const std::string& flying_form);
  void SetHasWings(bool has_wings);

  std::string Terrorize();
  
  std::string Attack() override;
  std::string Transform() override;  

 private:
  std::string flying_form_;
  bool has_wings_;
};

#endif