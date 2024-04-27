#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeSign(150), _gradeExec(150) {
    this->_signed = false;
    std::cout << "Default constructor called: ";
    std::cout << "A Aform has been created with default values." << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    this->_signed = false;
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
    else {
        std::cout << "Constructor called: ";
        std::cout << "A Aform has been created with name " << this->_name;
        std::cout << ", grade to sign " << this->_gradeSign << " and grade to execute ";
        std::cout << this->_gradeExec << std::endl;
    }
}

AForm::AForm(AForm const &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec) {
    *this = copy;
    std::cout << "A Aform has been created by copy." << std::endl;
}

AForm::~AForm() {
    std::cout << "Destructor called: ";
    std::cout << "AForm " << this->_name << " has been destroyed!" << std::endl;
}

AForm &AForm::operator=(AForm const &form) {
    if (this != &form)
        this->_signed = form._signed;
    return (*this);
}

std::string AForm::getName() const {
    return (this->_name);
}

bool AForm::getSigned() const {
    return (this->_signed);
}

int AForm::getGradeSign() const {
    return (this->_gradeSign);
}

int AForm::getGradeExec() const {
    return (this->_gradeExec);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeSign)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Form not signed!");
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
    out << "Form " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeSign() << " to sign and grade ";
    out << form.getGradeExec() << " to execute." << std::endl;
    return (out);
}
