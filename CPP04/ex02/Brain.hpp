#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <cmath>
#include <string>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(Brain const &copy);
		~Brain();

		Brain &operator=(Brain const &brain);

		std::string	getIdea(int i) const;
		void		setIdea(int i, std::string idea);
};

#endif
