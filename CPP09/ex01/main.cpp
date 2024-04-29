#include "RPN.hpp"

int main(int argc, char **argv) {
	RPN rpn;

	if (argc != 2) {
		std::cout << "Error: invalid number of arguments."<< std::endl;
		std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
		return (1);
	}
	try {
		std::cout << rpn.calculate(argv[1]) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
