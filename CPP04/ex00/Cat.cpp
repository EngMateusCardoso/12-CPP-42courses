#include "Cat.hpp"

Cat::Cat(void) : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(Cat const &copy) : Animal(copy) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &cat) {
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = cat.type;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat: Meow Meow ..." << std::endl;
}
