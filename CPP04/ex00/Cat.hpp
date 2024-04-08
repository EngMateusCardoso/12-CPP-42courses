#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat();

		Cat &operator=(Cat const &cat);

		void	makeSound(void) const;

};

#endif
