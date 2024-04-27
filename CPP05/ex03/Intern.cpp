#include "Intern.hpp"

Intern::Intern() {
	std::cout << "An intern has been created!" << std::endl;
}

Intern::Intern(Intern const &copy) {
	*this = copy;
	std::cout << "An intern has been created by copy" << std::endl;
}

Intern::~Intern() {
	std::cout << "An Intern has been destroyed!" << std::endl;
}

Intern &Intern::operator=(Intern const &op) {
	(void)op;
	return (*this);
}

Form *Intern::makeForm(std::string name, std::string target) {
	Form *form;
	int i = 0;
	std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	while (i < 3) {
		if (name == names[i])
			break;
		i++;
	}

	switch (i) {
		case 0:
			form = new RobotomyRequestForm(target);
			break;
		case 1:
			form = new PresidentialPardonForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::FormDoesNotExistException();
			return (NULL);
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

const char *Intern::FormDoesNotExistException::what() const throw() {
	return ("Form doesn't exist!");
}

