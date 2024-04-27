#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", 25, 5) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy) {
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &op) {
	if (this != &op) {
		this->_target = op._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!AForm::getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > AForm::getGradeExec())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
