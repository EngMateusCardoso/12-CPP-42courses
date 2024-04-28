#include "easyfind.hpp"

int main() {
	// Create a vector, a list and a deque of ints
	std::vector<int>	vec;
	std::list<int>		lst;
	std::deque<int>		deq;

	// Add some values to vector
	vec.push_back(10);
	vec.push_back(23);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(20);

	// Add some values to list
	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	// Add some values to deque
	deq.push_back(10);
	deq.push_back(23);
	deq.push_back(3);
	deq.push_back(17);
	deq.push_back(20);

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Vector test:" << std::endl;
	try {
		std::cout << *easyfind(vec, 3) << std::endl;
		std::cout << *easyfind(vec, 10) << std::endl;
		std::cout << *easyfind(vec, 20) << std::endl;
		std::cout << *easyfind(vec, 23) << std::endl;
		std::cout << *easyfind(vec, 17) << std::endl;
		std::cout << *easyfind(vec, 100) << std::endl;
		std::cout << *easyfind(vec, 17) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Not found" << std::endl;
	}

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "List test:" << std::endl;
	try {
		std::cout << *easyfind(lst, 3) << std::endl;
		std::cout << *easyfind(lst, 10) << std::endl;
		std::cout << *easyfind(lst, 20) << std::endl;
		std::cout << *easyfind(lst, 23) << std::endl;
		std::cout << *easyfind(lst, 17) << std::endl;
		std::cout << *easyfind(lst, 100) << std::endl;
		std::cout << *easyfind(lst, 17) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Not found" << std::endl;
	}

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Deque test:" << std::endl;
	try {
		std::cout << *easyfind(deq, 3) << std::endl;
		std::cout << *easyfind(deq, 10) << std::endl;
		std::cout << *easyfind(deq, 20) << std::endl;
		std::cout << *easyfind(deq, 23) << std::endl;
		std::cout << *easyfind(deq, 17) << std::endl;
		std::cout << *easyfind(deq, 100) << std::endl;
		std::cout << *easyfind(deq, 17) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Not found" << std::endl;
	}
	return (0);
}
