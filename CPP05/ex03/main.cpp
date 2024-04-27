#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << std::endl;
	std::cout << "BUREAUCRAT TEST: " << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Catches exception with increments ->" << std::endl;
	try {
		Bureaucrat bureaucrat1("João", 2);
		std::cout << bureaucrat1;
		bureaucrat1.incrementGrade();
		std::cout << bureaucrat1;
		bureaucrat1.incrementGrade();
		std::cout << bureaucrat1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Catches exception with decrements ->" << std::endl;
	try {
		Bureaucrat bureaucrat2("Pedro", 149);
		std::cout << bureaucrat2;
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat2;
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat2;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Too high exception in the constructor ->" << std::endl;
	try {
		Bureaucrat bureaucrat3("Paulo", 0);
		std::cout << bureaucrat3;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Too low exception in the constructor ->" << std::endl;
	try {
		Bureaucrat bureaucrat4("Joaquim", 151);
		std::cout << bureaucrat4;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "FORM TEST: " << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "ShrubberyCreationForm test: ----------------------------------" << std::endl;
	try {
		Bureaucrat bureaucrat("Jardineiro", 138);
		std::cout << bureaucrat;
		ShrubberyCreationForm form("home");
		std::cout << form;
		bureaucrat.executeForm(form); 
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form); 
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.executeForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "RobotomyRequestForm test: ------------------------------------" << std::endl;
	try {
		Bureaucrat bureaucrat("Tec de Robótica", 46);
		std::cout << bureaucrat;
		RobotomyRequestForm form("Robô");
		std::cout << form;
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.executeForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "PresidentialPardonForm test: ---------------------------------" << std::endl;
	try {
		Bureaucrat bureaucrat("Presidente", 6);
		std::cout << bureaucrat;
		PresidentialPardonForm form("Ladrão");
		std::cout << form;
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.executeForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "INTERN TEST: " << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Intern shrubbery creation: -----------------------------------" << std::endl;
    try {
        Bureaucrat bureaucrat("Jardineiro", 137);
        std::cout << bureaucrat;
        Intern intern;
        Form *form;
        form = intern.makeForm("shrubbery creation", "Jardim");
        std::cout << *form;
        bureaucrat.signForm(*form);
        std::cout << *form;
        bureaucrat.executeForm(*form);
        delete form;   
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Intern robotomy request: -------------------------------------" << std::endl;
    try {
        Bureaucrat bureaucrat("Tec de Robótica", 45);
        std::cout << bureaucrat;
        Intern intern;
        Form *form;
        form = intern.makeForm("robotomy request", "Robô");
        std::cout << *form;
        bureaucrat.signForm(*form);
        std::cout << *form;
        bureaucrat.executeForm(*form);
        delete form;   
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Intern presidential pardon: ----------------------------------" << std::endl;
    try {
        Bureaucrat bureaucrat("Presidente", 5);
        std::cout << bureaucrat;
        Intern intern;
        Form *form;
        form = intern.makeForm("presidential pardon", "Ladrão");
        std::cout << *form;
        bureaucrat.signForm(*form);
        std::cout << *form;
        bureaucrat.executeForm(*form);
        delete form;   
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Intern form does not exist: ----------------------------------" << std::endl;
    try {
        Intern intern;
        Form *form;
        form = intern.makeForm("does not exist", "Ladrão");
        std::cout << *form;
        delete form;   
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "End" << std::endl;
}
