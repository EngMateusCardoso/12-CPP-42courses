#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog const &copy) : Animal(copy) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &Dog) {
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = Dog.type;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Dog: Au Au Au ..." << std::endl;
}
