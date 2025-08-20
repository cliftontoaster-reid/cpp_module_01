#include "Zombie.hpp"
#include <iostream>
#include <string>

void Zombie::announce() const {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
