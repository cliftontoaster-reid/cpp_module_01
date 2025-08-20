#include "Zombie.hpp"

#include <cstdlib>
#include <ctime>

int main(void)
{
  std::srand(std::time(0));
  int randomZombieCount = rand() % 11 + 1;

  Zombie *zombie = Zombie::zombieHorde(randomZombieCount, "ZombieZ");

  for (int i = 0; i < randomZombieCount; ++i) {
    zombie[i].announce();
  }

  delete[] zombie;

  return 0;
}
