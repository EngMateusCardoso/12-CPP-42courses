#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
	protected:
		std::string type;

	public:
		AAnimal(void);
		AAnimal(AAnimal const &copy);
		virtual ~AAnimal();

		AAnimal &operator=(AAnimal const &animal);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
