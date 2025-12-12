#ifndef TRANSFORMERS_DECEPTICON_H_
#define TRANSFORMERS_DECEPTICON_H_

#include "transformers/Transformer.h"
#include <string>

namespace transformers {

class Decepticon : public Transformer {
 public:
  Decepticon(const std::string& name = "Decepticon",
             int height = 12,
             int weight = 40,
             int power_level = 120,
             Weapon* weapon = nullptr,
             Alliance* alliance = nullptr,
             const std::string& flight_mode = "Jet",
             int aggression_level = 70,
             bool has_stealth = false);
  
  const std::string& GetFlightMode() const;
  int GetAggressionLevel() const;
  bool GetHasStealth() const;
  
  void SetFlightMode(const std::string& flight_mode);
  void SetAggressionLevel(int aggression_level);
  void SetHasStealth(bool has_stealth);
  
  std::string Attack() const;
  std::string GetType() const override;

 private:
  std::string flight_mode_;
  int aggression_level_;
  bool has_stealth_;
};

}

#endif