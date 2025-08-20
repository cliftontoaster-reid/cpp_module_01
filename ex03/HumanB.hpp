#include "Weapon.hpp"
#include <iostream>
#include <string>

#pragma once

class HumanB {
private:
  std::string name;
  Weapon *weapon;

public:
  HumanB(const std::string &name, Weapon *weapon = NULL)
      : name(name), weapon(weapon) {}
  ~HumanB();

  const std::string &getName() const;

  const Weapon *getWeapon() const;

  void setWeapon(Weapon &w);

  void attack() const;
};
