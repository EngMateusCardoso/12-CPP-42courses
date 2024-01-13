#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_index = -1;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::addContact(void) {
	std::string input;
	bool		isValidInput;

	this->_index++;
	if (this->_index == 8) {
		this->_index--;
		std::cout << "PhoneBook is full. The oldest Contact will be deleted." << std::endl;
		for (int i = 0; i < 7; i++)
			this->_contacts[i] = this->_contacts[i + 1];
	}
	std::cout << "Enter the first name: ";
	do {
		std::getline(std::cin, input);
		isValidInput = true;
		if (input.empty()) {
			std::cout << "First name cannot be empty. Enter the first name: ";
			isValidInput = false;
		} else {
			for (size_t i = 0; i < input.length(); i++) {
				if (!std::isalpha(input[i])) {
					std::cout << "First name cannot contain non-alphabetical characters. Enter the first name: ";
					isValidInput = false;
					break;
				}
			}
		}
	} while (!isValidInput);
	this->_contacts[this->_index].setFirstName(input);
	std::cout << "Enter the last name: ";
	do {
		std::getline(std::cin, input);
		isValidInput = true;
		if (input.empty()) {
			std::cout << "Last name cannot be empty. Enter the last name: ";
			isValidInput = false;
		} else {
			for (size_t i = 0; i < input.length(); i++) {
				if (!std::isalpha(input[i])) {
					std::cout << "Last name cannot contain non-alphabetical characters. Enter the last name: ";
					isValidInput = false;
					break;
				}
			}
		}
	} while (!isValidInput);
	this->_contacts[this->_index].setLastName(input);
	std::cout << "Enter the nickname: ";
	do {
		std::getline(std::cin, input);
		isValidInput = true;
		if (input.empty()) {
			std::cout << "Nickname cannot be empty. Enter the nickname: ";
			isValidInput = false;
		} else {
			for (size_t i = 0; i < input.length(); i++) {
				if (!std::isalnum(input[i])) {
					std::cout << "Nickname cannot contain non-alphanumeric characters. Enter the nickname: ";
					isValidInput = false;
					break;
				}
			}
		}
	} while (!isValidInput);
	this->_contacts[this->_index].setNickname(input);
	std::cout << "Enter the phone number: ";
	do {
		std::getline(std::cin, input);
		isValidInput = true;
		if (input.empty()) {
			std::cout << "Phone number cannot be empty. Enter the phone number: ";
			isValidInput = false;
		} else {
			for (size_t i = 0; i < input.length(); i++) {
				if (!std::isdigit(input[i])) {
					std::cout << "Phone number cannot contain non-digit characters. Enter the phone number: ";
					isValidInput = false;
					break;
				}
			}
		}
	} while (!isValidInput);
	this->_contacts[this->_index].setPhoneNumber(input);
	std::cout << "Enter the darkest secret: ";
	do {
		std::getline(std::cin, input);
		isValidInput = true;
		if (input.empty()) {
			std::cout << "Darkest secret cannot be empty. Enter the darkest secret: ";
			isValidInput = false;
		} else {
			for (size_t i = 0; i < input.length(); i++) {
				if (!std::isalnum(input[i]) && !std::isspace(input[i])) {
					std::cout << "Darkest secret cannot contain non-alphanumeric characters. Enter the darkest secret: ";
					isValidInput = false;
					break;
				}
			}
		}
	} while (!isValidInput);
	this->_contacts[this->_index].setDarkestSecret(input);
	std::cout << "Contact saved successfully in index " << this->_index << std::endl;
	return ;
}

void	PhoneBook::searchContact(void) {
	std::string	index_input;

	if (this->_index == -1) {
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i <= this->_index; i++) {
		std::cout << std::setw(10) << i << "|";
		if (this->_contacts[i].getFirstName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].getFirstName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].getFirstName() << "|";
		if (this->_contacts[i].getLastName().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].getLastName().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->_contacts[i].getLastName() << "|";
		if (this->_contacts[i].getNickname().length() > 10)
			std::cout << std::setw(10) << this->_contacts[i].getNickname().substr(0, 9) << std::endl;
		else
			std::cout << std::setw(10) << this->_contacts[i].getNickname() << std::endl;
	}
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, index_input);
	while (index_input.empty() || index_input.length() > 1 || !std::isdigit(index_input[0]) || index_input[0] - '0' > this->_index) {
		std::cout << "Invalid index. Enter the index of the contact you want to see: ";
		std::getline(std::cin, index_input);
	}
	this->_contacts[index_input[0] - '0'].displayContact();
	return ;
}