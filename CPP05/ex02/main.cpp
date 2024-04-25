#include "Bureaucrat.hpp"

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
    std::cout << "Too low signForm exception, increment and sign ->" << std::endl;
    try {
		Form form1("Form1", 2, 2);
        std::cout << form1;
        Bureaucrat bureaucrat5("Maria", 3);
        std::cout << bureaucrat5;
        bureaucrat5.signForm(form1);
        std::cout << form1;
        bureaucrat5.incrementGrade();
        std::cout << bureaucrat5;
        bureaucrat5.signForm(form1);
        std::cout << form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "Sign, decrement and too low signForm exception ->" << std::endl;
    try {
        Form form2("Form2", 100, 100);
        std::cout << form2;
        Bureaucrat bureaucrat6("Bruno", 100);
        std::cout << bureaucrat6;
        bureaucrat6.signForm(form2);
        std::cout << form2;
        bureaucrat6.decrementGrade();
        std::cout << bureaucrat6;
		bureaucrat6.signForm(form2);
		std::cout << form2;
	} catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << "End" << std::endl;
}
