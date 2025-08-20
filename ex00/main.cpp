#include "Zombie.hpp"

int main(void)
{
  Zombie *zombie = Zombie::newZombie("Zombie1");
  zombie->announce();
  delete zombie;

  Zombie::randomChump("Zombie2");

  return 0;
}
