#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack const &copy) : std::stack<T>(copy) {};
		virtual ~MutantStack() {};

		MutantStack &operator=(MutantStack const &stack) {
			if (this != &stack)
				std::stack<T>::operator=(stack);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return (std::stack<T>::c.begin()); }
		iterator end() { return (std::stack<T>::c.end()); }
};

#endif
