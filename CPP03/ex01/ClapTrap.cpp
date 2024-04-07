#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap '" << this->_name << "' is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap '" << this->_name << "' is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << "A copy of ClapTrap '" << this->_name << "' is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor: ClapTrap '" << this->_name << "' is dead!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap '" << this->_name << "' cannot attacks is dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap '" << this->_name << "' cannot attacks is out of energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap '" << this->_name << "' attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap '" << this->_name << "' is out of energy!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap '" << this->_name << "' is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap '" << this->_name << "' takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap '" << this->_name << "' is dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap '" << this->_name << "' cannot be repaired is dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap '" << this->_name << "' cannot be repaired without energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap '" << this->_name << "' is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}
