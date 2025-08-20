#include "Weapon.hpp"
#include <iostream>
#include <string>

#pragma once

class HumanA {
private:
  std::string name;
  Weapon &weapon;

public:
  HumanA(const std::string &name, Weapon &weapon)
      : name(name), weapon(weapon) {}
  ~HumanA();

  const std::string &getName() const;

  const Weapon &getWeapon() const;

  void attack() const;
};
