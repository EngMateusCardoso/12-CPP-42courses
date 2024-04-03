#include "Zombie.hpp"

//Constructor
Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout << this->_name << " awakened!" << std::endl;
}

//Destructor
Zombie::~Zombie() {
	std::cout << this->_name  << " was taken down!" << std::endl;
}

//Member function to announce the zombie
void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
