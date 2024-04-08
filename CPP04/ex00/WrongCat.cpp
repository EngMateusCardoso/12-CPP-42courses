#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &wrongCat) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	this->type = wrongCat.type;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat: Meow Meow ..." << std::endl;
}
