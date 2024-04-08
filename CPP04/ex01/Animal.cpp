#include "Animal.hpp"

Animal::Animal(void) : type("Generic animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &animal) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = animal.type;
	return *this;
}

void   Animal::makeSound( void ) const {
	std::cout << "Animal: The sound of a " << this->type << " is played" << std::endl;
}

std::string Animal::getType( void ) const {
	return (this->type);
}
