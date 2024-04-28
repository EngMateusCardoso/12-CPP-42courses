#include "Data.hpp"

Data::Data(void) {
	std::cout << "Data instance created!" << std::endl;
}

Data::Data(std::string dataString, int dataNumber) : _dataString(dataString), _dataNumber(dataNumber) {
	std::cout << "Data instance created with string: " << dataString;
	std::cout << " and number: " << dataNumber << std::endl;
}

Data::Data(Data const &copy) {
	std::cout << "Data instance created by copy!" << std::endl;
	*this = copy; 
}

Data::~Data(void) {
	std::cout << "Data instance destroyed!" << std::endl;
}

Data &Data::operator=(Data const &data) {
	if (this != &data) {
		_dataString = data._dataString;
		_dataNumber = data._dataNumber;
	}
	return (*this);
}

// Getters
std::string Data::getDataString(void) const {
	return (_dataString);
}

int Data::getDataNumber(void) const {
	return (_dataNumber);
}

// Setters
void Data::setDataString(std::string private_data) {
	_dataString = private_data;
}

void Data::setDataNumber(int private_number) {
	_dataNumber = private_number;
}
