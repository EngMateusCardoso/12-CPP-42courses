#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	private:
		std::string _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &op);

		void execute(Bureaucrat const &executor) const;
};

#endif