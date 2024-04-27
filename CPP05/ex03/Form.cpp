#include "Form.hpp"

Form::Form() : _name("default"), _gradeSign(150), _gradeExec(150) {
	this->_signed = false;
	std::cout << "Default constructor called: ";
	std::cout << "A form has been created with default values." << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	this->_signed = false;
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	else {
		std::cout << "Constructor called: ";
		std::cout << "A form has been created with name " << this->_name;
		std::cout << ", grade to sign " << this->_gradeSign << " and grade to execute ";
		std::cout << this->_gradeExec << std::endl;
	}
}

Form::Form(Form const &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec) {
	*this = copy;
	std::cout << "A form has been created by copy." << std::endl;
}

Form::~Form() {
	std::cout << "Destructor called: ";
	std::cout << "Form " << this->_name << " has been destroyed!" << std::endl;
}

Form &Form::operator=(Form const &form) {
	if (this != &form)
		this->_signed = form._signed;
	return (*this);
}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getGradeSign() const {
	return (this->_gradeSign);
}

int Form::getGradeExec() const {
	return (this->_gradeExec);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

void Form::execute(Bureaucrat const &executor) const {
	if (!this->_signed)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->_gradeExec)
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

const char *Form::FormNotSignedException::what() const throw() {
	return ("Form not signed!");
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeSign() << " to sign and grade ";
	out << form.getGradeExec() << " to execute." << std::endl;
	return (out);
}
