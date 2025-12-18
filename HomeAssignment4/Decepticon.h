// Decepticon.h
#ifndef TRANSFORMERS_DECEPTICON_H
#define TRANSFORMERS_DECEPTICON_H

#include "Transformer.h"
#include <string>

// наследник Десептикон
class Decepticon : public Transformer {
 public:
  Decepticon(const std::string& name, int height, int weight, int power_level,
             Weapon* weapon, Alliance* alliance, const std::string& flying_form,
             bool has_wings);
  Decepticon(const std::string& name);
  Decepticon(const std::string& name, const std::string& flying_form);
  Decepticon(const Decepticon& other);

  std::string GetFlyingForm() const;
  bool GetHasWings() const;

  void SetFlyingForm(const std::string& flying_form);
  void SetHasWings(bool has_wings);

  /*
  std::string Terrorize();
  std::string Attack() override;
  std::string Transform() override;
  */
  
  void SpecialAbility() const override;
  void ShowInfo() const override;
  void BattleCry() const override;
  void Transform() const override;

  virtual void Terrorize() const;

 private:
  std::string flying_form_;
  bool has_wings_;
};

#endif