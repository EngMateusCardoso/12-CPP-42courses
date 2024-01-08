#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phonebook;
	std::string input;
	bool on = true;

	while (on) {
		std::cout << "------------- Command list -------------" << std::endl;
		std::cout << "- ADD (save a new contact)" << std::endl;
		std::cout << "- SEARCH (display a specific contact)" << std::endl;
		std::cout << "- EXIT (exit the program)" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Enter a command: ";
		std::cin >> input;
		if (input == "ADD\0")
			phonebook.addContact();
		else if (input == "SEARCH\0")
			phonebook.searchContact();
		else if (input == "EXIT\0")
			on = false;
		else
			std::cout << "Invalid command. Try again." << std::endl;
	}
	return 0;
}
