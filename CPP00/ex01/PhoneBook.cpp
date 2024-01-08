#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_index = -1;
	std::cout << "PhoneBook constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void	PhoneBook::addContact(void) {
	std::string input;

	this->_index++;
	if (this->_index == 8) {
		this->_index--;
		std::cout << "PhoneBook is full. The oldest Contact will be deleted." << std::endl;
		for (int i = 0; i < 7; i++)
			this->_contacts[i] = this->_contacts[i + 1];
	}
	std::cout << "Enter the first name: ";
	std::cin >> input;
	while (input.empty()) {
		std::cout << "First name cannot be empty. Enter the first name: ";
		std::cin >> input;
	}
	this->_contacts[this->_index].setFirstName(input);
	input.clear();
	std::cout << "Enter the last name: ";
	std::cin >> input;
	while (input.empty()) {
		std::cout << "Last name cannot be empty. Enter the last name: ";
		std::cin >> input;
	}
	this->_contacts[this->_index].setLastName(input);
	input.clear();
	std::cout << "Enter the nickname: ";
	std::cin >> input;
	while (input.empty()) {
		std::cout << "Nickname cannot be empty. Enter the nickname: ";
		std::cin >> input;
	}
	this->_contacts[this->_index].setNickname(input);
	input.clear();
	std::cout << "Enter the phone number: ";
	std::cin >> input;
	while (input.empty()) {
		std::cout << "Phone number cannot be empty. Enter the phone number: ";
		std::cin >> input;
	}
	this->_contacts[this->_index].setPhoneNumber(input);
	input.clear();
	std::cout << "Enter the darkest secret: ";
	std::cin >> input;
	while (input.empty()) {
		std::cout << "Darkest secret cannot be empty. Enter the darkest secret: ";
		std::cin >> input;
	}
	this->_contacts[this->_index].setDarkestSecret(input);
	input.clear();
	std::cout << "Contact saved successfully in index " << this->_index << std::endl;
	return ;
}

void	PhoneBook::searchContact(void) {
	int		index;

	if (this->_index == -1) {
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i <= this->_index; i++) {
		
		this->_contacts[i].displayContact();
	}
	std::cout << "Enter the index of the contact you want to see: ";
	std::cin >> index;
	while (std::cin.fail() || index < 0 || index > this->_index) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Invalid index. Enter the index of the contact you want to see: ";
		std::cin >> index;
	}
	this->_contacts[index].displayContact();
	return ;

}