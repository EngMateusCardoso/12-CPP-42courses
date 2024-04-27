#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45) {
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy) {
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &op) {
    if (this != &op) {
        this->_target = op._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!AForm::getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > AForm::getGradeExec())
        throw AForm::GradeTooLowException();
    std::cout << "** drilling noises... **"  << std::endl;
    srand(time(0));
    if (rand() % 2)
        std::cout  << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << this->_target << " robotomy failed!" << std::endl;
}
