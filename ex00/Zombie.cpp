#include "Zombie.hpp"
#include <iostream>
#include <string>

#define ANSI_BOLD "\033[1m"
#define ANSI_RESET "\033[0m"

void Zombie::announce() const {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
  std::cout
      << name
      << " is being sent to the " ANSI_BOLD
         "infinite, merciless expanse of space — a "
         "lightless, soundless, radiation-saturated, temperature-extreme "
         "vacuum of absolute zero and scorching cosmic radiation, where "
         "microscopic particles of interstellar dust hurtle at hypersonic "
         "velocities, where temperatures can plummet to -270.45°C or spike to "
         "millions of degrees near stellar bodies, where cosmic rays bombard "
         "every cubic centimeter with lethal high-energy particles, where the "
         "slightest exposure means instantaneous death through explosive "
         "decompression, boiling blood, freezing tissue, and cellular "
         "destruction—represents the most hostile environment imaginable, a "
         "primordial realm of unimaginable violence where the laws of physics "
         "reign supreme and human existence is but a fragile, momentary "
         "illusion against the backdrop of an incomprehensibly vast and "
         "indifferent cosmic wilderness." ANSI_RESET
      << std::endl;
}