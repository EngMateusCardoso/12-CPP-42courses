#include "Array.hpp"

int main(void) {

	std::cout << std::endl;
	std::cout << "Constructor with no parameter: Creates a empty array" << std::endl;
	Array<int> emptyArray;
	std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;

	std::cout << "Constructor with an unsigned int parameter: Creates an array of size n" << std::endl;
	Array<char>			charArray(5);
	Array<int>			intArray(5);
	Array<double>		doubleArray(5);
	Array<float>		floatArray(5);
	std::cout << "Size of char array: " << charArray.size() << std::endl;
	std::cout << "Size of int array: " << intArray.size() << std::endl;
	std::cout << "Size of double array: " << doubleArray.size() << std::endl;
	std::cout << "Size of float array: " << floatArray.size() << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Operator[]: Returns a reference to the element at the index" << std::endl;
	std::cout << "Char test ->" << std::endl;
	for (unsigned int i = 0; i < charArray.size(); i++)
		charArray[i] = static_cast<char>(i + 65);
	for (unsigned int i = 0; i < charArray.size(); i++)
		std::cout << charArray[i] << std::endl;
	std::cout << "Int test ->" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = static_cast<int>(i);
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	std::cout << "Double test ->" << std::endl;
	for (unsigned int i = 0; i < doubleArray.size(); i++)
		doubleArray[i] = static_cast<double>(i + 0.42);
	for (unsigned int i = 0; i < doubleArray.size(); i++)
		std::cout << doubleArray[i] << std::endl;
	std::cout << "Float test ->" << std::endl;
	for (unsigned int i = 0; i < floatArray.size(); i++)
		floatArray[i] = static_cast<float>(i + 0.5f);
	for (unsigned int i = 0; i < floatArray.size(); i++)
		std::cout << floatArray[i] << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Copy constructor: (Deep copy)" << std::endl;
	Array<int> intArrayCopy(intArray);
	intArrayCopy[0] = 42;
	for (unsigned int i = 0; i < intArrayCopy.size(); i++)
		std::cout << intArray[i] << " - " << intArrayCopy[i] << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Assignation operator: (Deep copy)" << std::endl;
	Array<int> intArrayAssign = intArray;
	intArrayAssign[0] = 42;
	for (unsigned int i = 0; i < intArrayAssign.size(); i++)
		std::cout << intArray[i] << " - " << intArrayAssign[i] << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Exception test: " << std::endl;

	try {
		charArray[10] = 42.42;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try	{
		emptyArray[0] = 42;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
		
	return (0);
}