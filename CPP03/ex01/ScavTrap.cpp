#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap '" << this->_name << "' was created from ClapTrap!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap '" << this->_name << "' was created from ClapTrap!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
	std::cout << "A copy of ScavTrap '" << this->_name << "' was created!" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor: ScavTrap '" << this->_name << "' is dead!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &assign) {
	this->_name = assign._name;
	this->_hitPoints = assign._hitPoints;
	this->_energyPoints = assign._energyPoints;
	this->_attackDamage = assign._attackDamage;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap '" << this->_name << "' cannot attacks is dead!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap '" << this->_name << "' cannot attacks is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap '" << this->_name << "' attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;	
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap '" << this->_name << "' is out of energy!" << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap '" << this->_name << "' cannot guard gate is dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap '" << this->_name << "' has entered in Gate keeper mode!"<< std::endl;
}
