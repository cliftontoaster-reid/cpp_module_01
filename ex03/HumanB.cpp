
#include "HumanB.hpp"

HumanB::~HumanB() {}

const std::string &HumanB::getName() const { return name; }

const Weapon *HumanB::getWeapon() const { return weapon; }

void HumanB::setWeapon(Weapon &w) { weapon = &w; }

void HumanB::attack() const {
  if (weapon)
    std::cout << name << " attacks with their " << weapon->getType()
              << std::endl;
  else
    std::cout << name << " attacks with their bare hands" << std::endl;
}
