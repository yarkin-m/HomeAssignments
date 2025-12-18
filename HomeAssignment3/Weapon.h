#ifndef TRANSFORMERS_WEAPON_H
#define TRANSFORMERS_WEAPON_H

#include <string>

// композиции
class Weapon {
 public:
  Weapon(const std::string& name, int damage);
  ~Weapon();

  std::string GetName() const;
  int GetDamage() const;

  void SetName(const std::string& name);
  void SetDamage(int damage);

 private:
  std::string name_;
  int damage_;
};

#endif 