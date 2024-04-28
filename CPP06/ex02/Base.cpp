#include "Base.hpp"

Base::~Base() {}

Base *generate() {
	int i = std::rand() % 3;

	switch (i) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "It's an A class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's a B class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's a C class" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "It's an A class" << std::endl;
		(void)a;
		return ;
	} catch (std::exception &e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "It's a B class" << std::endl;
		(void)b;
		return ;
	} catch (std::exception &e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "It's a C class" << std::endl;
		(void)c;
	} catch (std::exception &e) {
		std::cout << "Unknown class" << std::endl;
	}
}
