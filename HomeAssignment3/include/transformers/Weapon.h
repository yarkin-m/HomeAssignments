#ifndef TRANSFORMERS_WEAPON_H_
#define TRANSFORMERS_WEAPON_H_

#include <string>

namespace transformers {

class Weapon {
 public:
  Weapon(const std::string& name = "Unknown",
         int damage = 10,
         const std::string& type = "Energy");
  ~Weapon();
  
  const std::string& GetName() const;
  int GetDamage() const;
  const std::string& GetType() const;
  
  void SetName(const std::string& name);
  void SetDamage(int damage);
  void SetType(const std::string& type);
  
  std::string Attack() const;
  bool IsPowerful() const;

 private:
  std::string name_;
  int damage_;
  std::string type_;
};

} 

#endif