#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie *Zombie::newZombie(std::string name) { return new Zombie(name); }

void Zombie::announce() const {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void Zombie::randomChump(std::string name) {
  Zombie zombie(name);
  zombie.announce();
}
