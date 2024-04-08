#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &copy) : Animal(copy) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = copy.type;
    this->_brain = new Brain(*copy._brain);
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &Dog) {
    if (this == &Dog)
        return *this;
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = Dog.type;
    this->_brain = new Brain(*Dog._brain);
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog: Au Au Au ..." << std::endl;
}

std::string Dog::getIdea(int i) const {
    return (this->_brain->getIdea(i));
}
