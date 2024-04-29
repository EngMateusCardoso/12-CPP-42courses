#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <deque> 
# include <list>
# include <cstring>
# include <algorithm>
# include <cctype>
# include <cstdlib>
# include <limits.h>
# include <stdexcept>

# define ARG_ERR		"Error: invalid arguments\nUsage: ./PmergeMe [number1] [number2] [number3] ..."
# define ONLYNBR_ERR	"Error: invalid arguments\nOnly positive integers can be process"
# define CHAR_ERR		"Error: invalid arguments\nCannot process characters"

class PmergeMe {
	private:
		std::deque<int>	_deque;
		std::list<int>	_list;

		bool	_isNumber(char *arg);
		void	_isValid(int argc, char **argv);

		void	_mergeInsertionSort(std::deque<int> &array, int start, int end);
		void	_mergeInsertionSort(std::list<int> &array, int start, int end);

		void	_sortAndCreateDeque(int argc, char *argv[]);
		void	_sortAndCreateList(int argc, char *argv[]);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);

		void sort(int argc, char *argv[]);
};

template<typename T>
void	printContainer(T &container, std::string str) {
	std::cout << str << ":\t";
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif
