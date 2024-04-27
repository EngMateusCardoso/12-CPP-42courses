#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("presidential pardon", 25, 5) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : Form(copy) {
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
	if (!Form::getSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > Form::getGradeExec())
		throw Form::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
