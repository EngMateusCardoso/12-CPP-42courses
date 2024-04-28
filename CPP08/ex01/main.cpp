#include "Span.hpp"

int main() {
	std::cout << std::endl;
	std::cout << "Subject test: " << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "Test with negative numbers" << std::endl;

	Span sp1 = Span(5);
	sp1.addNumber(4);
	sp1.addNumber(2);
	sp1.addNumber(-42);
	sp1.addNumber(-21);
	sp1.addNumber(42);

	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Test with 10000 random numbers, using addNumber" << std::endl;

	Span sp2 = Span(10000);
	std::srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		sp2.addNumber(std::rand());
		
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Test with 100000 random numbers, using addNumbers" << std::endl;

	Span sp3 = Span(100000);
	std::vector<int> vec;
	std::srand(time(NULL));
	for (int i = 0; i < 100000; i++)
		sp3.addNumber(std::rand());
	sp3.addNumbers(vec.begin(), vec.end());

	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Exception test: " << std::endl;

	Span sp4 = Span(5);
	sp4.addNumber(10);
	sp4.addNumber(23);
	sp4.addNumber(3);
	sp4.addNumber(18);
	sp4.addNumber(20);

	try {
		sp4.addNumber(1);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Span sp5 = Span(5);

	try {
		std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Span sp6 = Span(5);
	sp6.addNumber(10);

	try {
		std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
	} catch(const std::exception& e) { 
		std::cerr << e.what() << std::endl;
	}
	return 0;
}