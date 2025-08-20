
#include "HumanA.hpp"

HumanA::~HumanA() {}

const std::string &HumanA::getName() const { return name; }

const Weapon &HumanA::getWeapon() const { return weapon; }

void HumanA::attack() const {
  std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
