#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
	private:
		unsigned int		_n;
		std::vector<int>	_vec;
		Span();

	public:
		Span(unsigned int n);
		Span(Span const &copy);
		~Span();
		Span &operator=(Span const &span);

		void	addNumber(int n);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

		class FullSpanException : public std::exception {
			virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif
