#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.type;
	this->_brain = new Brain(*copy._brain);
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &cat) {
	if (this == &cat)
		return *this;
	std::cout << "Cat assignation operator called" << std::endl;
	this->type = cat.type;
	this->_brain = new Brain(*cat._brain);
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Cat: Meow Meow ..." << std::endl;
}

std::string Cat::getIdea(int i) const {
	return (this->_brain->getIdea(i));
}
