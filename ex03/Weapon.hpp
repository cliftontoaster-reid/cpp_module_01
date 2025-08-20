#include <string>

#pragma once

class Weapon {
private:
  std::string type;

public:
  Weapon(const std::string &type) : type(type) {}
  ~Weapon() {};

  const std::string &getType() const;
  void setType(const std::string &newType);
};
