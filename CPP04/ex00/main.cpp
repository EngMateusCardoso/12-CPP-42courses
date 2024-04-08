#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "getType tests:" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << std::endl << "makeSound tests:" << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "deletion tests:" << std::endl;

	delete(meta);
	delete(i);
	delete(j);

	std::cout << std::endl << "wrongAnimal tests:" << std::endl;

	const WrongAnimal* animalcat = new WrongCat();
	const WrongCat* catcat = new WrongCat();

	std::cout << std::endl << "makeSound tests 2:" << std::endl;

	animalcat->makeSound();
	catcat->makeSound();

	std::cout << std::endl << "deletion tests 2:" << std::endl;

	delete(animalcat);
	delete(catcat);
	return (0);
}
