#include "Weapon.hpp"

Weapon::Weapon(const std::string &name): _type(name) {} //| Construtor

Weapon::~Weapon() {} //| Destrutor

void Weapon::setType(const std::string &type) { this->_type = type; } //| Setter

const std::string &Weapon::getType() const { return (this->_type); } //| Getter
