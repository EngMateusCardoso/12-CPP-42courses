#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Generic wrong animal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->type = wrongAnimal.type;
	return *this;
}

void   WrongAnimal::makeSound( void ) const {
	std::cout << "WrongAnimal: The sound of a " << this->type << " is played" << std::endl;
}

std::string WrongAnimal::getType( void ) const {
	return (this->type);
}
