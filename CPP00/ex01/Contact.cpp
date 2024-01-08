#include "Contact.hpp"

// Constructor
Contact::Contact(void) {
	std::cout << "Contact constructor called" << std::endl;
	return;
}

// Destructor
Contact::~Contact(void) {
	std::cout << "Contact destructor called" << std::endl;
	return;
}

// Getters

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

std::string Contact::getNickname(void) const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

// Setters

void		Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void		Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void		Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void		Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void		Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

// Methods

void		Contact::displayContact(void) const {
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}
