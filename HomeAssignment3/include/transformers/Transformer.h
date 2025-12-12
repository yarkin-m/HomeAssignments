#ifndef TRANSFORMERS_TRANSFORMER_H_
#define TRANSFORMERS_TRANSFORMER_H_

#include <string>
#include "transformers/Weapon.h"
#include "transformers/Alliance.h"

namespace transformers {

class Transformer {
 public:
  Transformer(const std::string& name = "Unknown",
              int height = 10,
              int weight = 30,
              int power_level = 100,
              Weapon* weapon = nullptr,
              Alliance* alliance = nullptr);
  virtual ~Transformer();
  
  const std::string& GetName() const;
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
  
  virtual std::string Transform() const;
  virtual std::string Introduce() const;
  virtual std::string GetType() const;
  bool IsPowerful() const;

 protected:
  std::string name_;
  int height_;
  int weight_;
  int power_level_;
  Weapon* weapon_;
  Alliance* alliance_;
};

}

#endif