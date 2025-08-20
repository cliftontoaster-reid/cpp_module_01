#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie(std::string name) : name(name) {}
  static Zombie *newZombie(std::string name);
  void announce() const;
  static void randomChump(std::string name);
};
