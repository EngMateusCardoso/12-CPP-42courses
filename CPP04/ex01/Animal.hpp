#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal();

		Animal &operator=(Animal const &animal);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
