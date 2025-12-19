/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 4
 */
#ifndef TRANSFORMERS_TRANSFORMER_H
#define TRANSFORMERS_TRANSFORMER_H

#include <string>
#include "Weapon.h"
#include "Alliance.h"

// Базовый класс
class Transformer {
 public:
  Transformer(const std::string& name, int height, int weight, int power_level,
              Weapon* weapon, Alliance* alliance);
  Transformer(const std::string& name);
  Transformer(const std::string& name, int power_level);
  Transformer(const Transformer& other);

  virtual ~Transformer();
  friend std::ostream& operator<<(std::ostream& os, const Transformer& transformer);

  std::string GetName() const;
  int GetHeight() const;
  int GetWeight() const;
  int GetPowerLevel() const;
  Weapon* GetWeapon() const;
  Alliance* GetAlliance() const;

  void SetName(const std::string& name);
  void SetHeight(int height);
  void SetWeight(int weight);
  void SetPowerLevel(int power_level);
  void SetWeapon(Weapon* weapon);
  void SetAlliance(Alliance* alliance);

  virtual void SpecialAbility() const = 0;

  /*
  virtual std::string Transform();
  virtual std::string Attack();
  */

  virtual void ShowInfo() const;
  virtual void BattleCry() const;
  virtual void Transform() const;
  virtual void Repair() const;
  
  std::string GetInfo() const;

 protected:
  std::string name_;
  int height_;       
  int weight_;        
  int power_level_;   
  Weapon* weapon_;    // композиция 
  Alliance* alliance_; // ассоциация 
};

#endif  