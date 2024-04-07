#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap") {
	std::cout << "FragTrap '" << this->_name << "' was created from ClapTrap!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap '" << this->_name << "' was created from ClapTrap!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	std::cout << "A copy of FragTrap '" << this->_name << "' was created!" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor: FragTrap '" << this->_name << "' is dead!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &assign) {
	this->_name = assign._name;
	this->_hitPoints = assign._hitPoints;
	this->_energyPoints = assign._energyPoints;
	this->_attackDamage = assign._attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap '" << this->_name << "' is asking for a high five!" << std::endl;
}
