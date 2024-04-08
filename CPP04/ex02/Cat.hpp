#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain *_brain;

	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat();

		Cat &operator=(Cat const &cat);

		void	    makeSound(void) const;
        std::string getIdea(int i) const;
};

#endif
