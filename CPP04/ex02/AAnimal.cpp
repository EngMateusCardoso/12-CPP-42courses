#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Generic animal") {
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &animal) {
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = animal.type;
	return *this;
}

std::string AAnimal::getType( void ) const {
	return (this->type);
}
