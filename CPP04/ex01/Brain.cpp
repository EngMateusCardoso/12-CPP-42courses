#include "Brain.hpp"

Brain::Brain() {
	std::string goodIdeas[3] = {"Play", "Eat", "Sleep"};
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = goodIdeas[rand() % 3];
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &brain) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = brain.getIdea(i);
	return (*this);
}

std::string Brain::getIdea(int i) const {
	return (this->_ideas[i]);
}

void Brain::setIdea(int i, std::string idea) {
	this->_ideas[i] = idea;
}
