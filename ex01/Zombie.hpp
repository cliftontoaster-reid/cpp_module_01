#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie() : name("") {}
  Zombie(std::string name) : name(name) {}
  ~Zombie() {}

  void announce() const;

  static Zombie *newZombie(std::string name);
  static Zombie* zombieHorde( int N, std::string name );
  static void randomChump(std::string name);
};
