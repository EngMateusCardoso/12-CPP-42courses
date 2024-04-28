#include "Base.hpp"

int main() {
	std::cout << "--------------------- DYNAMIC CAST TEST ----------------------" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Test " << i + 1 << "..." << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << "--------------------------------------------------------------" << std::endl;
	}
	std::cout << "Test 11..." << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	Base *base = new Base;
	identify(base);
	identify(*base);
	delete base;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "---------------------- END OF TEST ---------------------------" << std::endl;
	return (0);
}
