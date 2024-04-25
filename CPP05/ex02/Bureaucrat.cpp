#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Default constructor called: ";
	std::cout << "Bureaucrat " << this->_name << " created with grade " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else {
		this->_grade = grade;
		std::cout << "Constructor called: ";
		std::cout << "Bureaucrat " << this->_name << " created with grade " << this->_grade << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	*this = copy;
	std::cout << "Copy constructor called: ";
	std::cout << "Bureaucrat " << this->_name << " created with grade " << this->_grade << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called: ";
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat) {
	if (this != &bureaucrat)
		this->_grade = bureaucrat._grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else {
		this->_grade--;
		std::cout << this->_name << " has been promoted to grade " << this->_grade << std::endl;
	}
}

void Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else {
		this->_grade++;
		std::cout << this->_name << " has been demoted to grade " << this->_grade << std::endl;
	}
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because ";
        std::cout << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low!");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src) {
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
