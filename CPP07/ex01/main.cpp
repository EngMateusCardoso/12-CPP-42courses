#include "iter.hpp"

int main() {
	char		char_array[] = {'a', 'b', 'c', 'd', 'e'};
	int			int_array[] = {1, 2, 3, 4, 5};
	double		double_array[] = {1.11, 2.22, 3.33, 4.44, 5.55};
	float		float_array[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::string	str_array[] = {"one", "two", "three", "four", "five"};

	std::cout << "Char array: " << std::endl;
	::iter(char_array, 5, ::print<char>);
	std::cout << std::endl;
	std::cout << "Int array: " << std::endl;
	::iter(int_array, 5, ::print<int>);
	std::cout << std::endl;
	std::cout << "Double array: " << std::endl;
	::iter(double_array, 5, ::print<double>);
	std::cout << std::endl;
	std::cout << "Float array: " << std::endl;
	::iter(float_array, 5, ::print<float>);
	std::cout << std::endl;
	std::cout << "String array: " << std::endl;
	::iter(str_array, 5, ::print<std::string>);
	return (0);
}