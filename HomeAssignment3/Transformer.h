/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 3
 */
#ifndef TRANSFORMERS_TRANSFORMER_H
#define TRANSFORMERS_TRANSFORMER_H

#include <string>
#include <memory>  
#include "Weapon.h"
#include "Alliance.h"

// Base class
class Transformer {
 public:
  Transformer(const std::string& name, int height, int weight, int power_level,
              std::unique_ptr<Weapon> weapon, Alliance* alliance);  
  virtual ~Transformer();

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
  void SetWeapon(std::unique_ptr<Weapon> weapon);  
  void SetAlliance(Alliance* alliance);

  virtual std::string Transform();
  virtual std::string Attack();
  
  std::string GetInfo() const;

 protected:
  std::string name_;
  int height_;       
  int weight_;        
  int power_level_;   
  std::unique_ptr<Weapon> weapon_;    // composition
  Alliance* alliance_; // association
};

#endif