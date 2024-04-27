#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();

		Intern &operator=(Intern const &op);

		Form *makeForm(std::string name, std::string target);

		class FormDoesNotExistException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif