#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &copy) {
	(void)copy;
}

PmergeMe::~PmergeMe() {
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

bool PmergeMe::_isNumber(char *arg) {
	for (size_t i = 0; i < std::strlen(arg); ++i)
		if (!isdigit(arg[i]))
			return true;
	return false;
}

void PmergeMe::_isValid(int argc, char **argv) {
	if (argc < 2)
		throw std::runtime_error(ARG_ERR);
	int size = 0;
	for (int i = 1; i < argc; ++i) {
		char *argument = argv[i];
		if (_isNumber(argument)) 
			throw std::runtime_error(CHAR_ERR);
		long number = std::atol(argument);
		if (number > INT_MAX || number <= 0) 
			throw std::runtime_error(ONLYNBR_ERR);
		++size;
	}
	return ;
}

void PmergeMe::_mergeInsertionSort(std::deque<int> &array, int start, int end) {
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;
	_mergeInsertionSort(array, start, mid);
	_mergeInsertionSort(array, mid + 1, end);

	std::deque<int> temp;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (array[i] < array[j])
			temp.push_back(array[i++]);
		else
			temp.push_back(array[j++]);
	}
	while (i <= mid)
		temp.push_back(array[i++]);
	while (j <= end)
		temp.push_back(array[j++]);
	for (int i = start; i <= end; ++i)
		array[i] = temp[i - start];
}

void PmergeMe::_mergeInsertionSort(std::list<int> &array, int start, int end) {
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;
	_mergeInsertionSort(array, start, mid);
	_mergeInsertionSort(array, mid + 1, end);

	std::list<int> temp;
	std::list<int>::iterator i = array.begin();
	std::list<int>::iterator j = array.begin();
	std::list<int>::iterator k = array.begin();
	std::list<int>::iterator l = array.begin();
	std::advance(i, start);
	std::advance(j, mid);
	std::advance(k, mid + 1);
	std::advance(l, end);
	while (i != j && k != l) {
		if (*i < *k) {
			temp.push_back(*i);
			++i;
		} else {
			temp.push_back(*k);
			++k;
		}
	}
	while (i != j) {
		temp.push_back(*i);
		++i;
	}
	while (k != l) {
		temp.push_back(*k);
		++k;
	}
	for (std::list<int>::iterator it = temp.begin(); it != temp.end(); ++it) {
		*array.begin() = *it;
		++array.begin();
	}
}

void PmergeMe::_sortAndCreateDeque(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i)
		_deque.push_back(std::atoi(argv[i]));

	printContainer(_deque, "Before");

	clock_t startTime = clock();
	_mergeInsertionSort(_deque, 0, _deque.size() - 1);
	clock_t endTime = clock();
	double dequeTime = double(endTime - startTime)/ CLOCKS_PER_SEC;

	printContainer(_deque, "After");
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque:\t";
	std::cout << std::fixed << std::setprecision(6) << dequeTime << " us" << std::endl;
}

void PmergeMe::_sortAndCreateList(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i)
		_list.push_back(std::atoi(argv[i]));

	//printContainer(_list, "Before");

	clock_t startTime = clock();
	_mergeInsertionSort(_list, 0, _list.size() - 1);
	clock_t endTime = clock();
	double listTime = double(endTime - startTime) / CLOCKS_PER_SEC;

	//printContainer(_list, "After");
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list: \t";
	std::cout << std::fixed << std::setprecision(6) << listTime << " us" << std::endl;
}

void	PmergeMe::sort(int argc, char *argv[]) {
	try {
		_isValid(argc, argv);
		_sortAndCreateDeque(argc, argv);
		_sortAndCreateList(argc, argv);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
