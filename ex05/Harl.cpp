#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
  std::cout << "[DEBUG]" << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout << "[INFO]" << std::endl;
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout << "[WARNING]" << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years, whereas you started working here just last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << "[ERROR]" << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  // only proceed if it's a valid level; otherwise unknown
  if (level == "DEBUG" || level == "INFO" || level == "WARNING" ||
      level == "ERROR") {
    // dispatch based on first character; switch fall-through handles increasing
    // severity
    switch (level[0]) {
    case 'D':
      debug();
      // fall through
    case 'I':
      info();
      // fall through
    case 'W':
      warning();
      // fall through
    case 'E':
      error();
      break;
    }
  } else {
    std::cout << "[UNKNOWN]" << std::endl;
    std::cout << "Probably complaining about insignificant problems"
              << std::endl;
  }
}
