#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	std::cout << "----> Subject main test" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << "----> My main test" << std::endl;
	std::cout << "----> Test array requested in subject" << std::endl;

	const Animal* animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++) {
		std::cout << "Type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		std::cout << "Idea: " << ((Cat*)animals[i])->getIdea(42) << std::endl;
	}
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
	std::cout << "----> Test deep copies" << std::endl;
	Cat kitty;
	Dog puppy;
	{
		Cat catcopy(kitty);
		Dog dogcopy(puppy);
		kitty.makeSound();
		std::cout << "Idea: " << kitty.getIdea(24) << std::endl;
		std::cout << "Idea: " << kitty.getIdea(42) << std::endl;
		std::cout << "Idea: " << kitty.getIdea(84) << std::endl;
		puppy.makeSound();
		std::cout << "Idea: " << puppy.getIdea(24) << std::endl;
		std::cout << "Idea: " << puppy.getIdea(42) << std::endl;
		std::cout << "Idea: " << puppy.getIdea(84) << std::endl;
	}
	kitty.makeSound();
	std::cout << "Idea: " << kitty.getIdea(24) << std::endl;
	std::cout << "Idea: " << kitty.getIdea(42) << std::endl;
	std::cout << "Idea: " << kitty.getIdea(84) << std::endl;
	puppy.makeSound();
	std::cout << "Idea: " << puppy.getIdea(24) << std::endl;
	std::cout << "Idea: " << puppy.getIdea(42) << std::endl;
	std::cout << "Idea: " << puppy.getIdea(84) << std::endl;
	return (0);
}
