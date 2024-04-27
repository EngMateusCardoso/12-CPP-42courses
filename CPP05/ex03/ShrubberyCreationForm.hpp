#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	private:
		std::string _target;
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &op);

		void execute(Bureaucrat const &executor) const;
};

#endif
