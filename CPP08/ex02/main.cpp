#include "MutantStack.hpp"

int main() {
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "Test subject" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;
	std::cout << "Show copy: ";
	while (!s.empty())
	{
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "list test:" << std::endl;

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "back: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "size: " << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();
	++it2;
	--it2;
	while (it2 != ite2) {
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "MutantStack char test:" << std::endl;
	MutantStack<char> mstack2;
	mstack2.push('a');
	mstack2.push('b');
	std::cout << "top: " << mstack2.top() << std::endl;
	mstack2.pop();
	std::cout << "size: " << mstack2.size() << std::endl;
	mstack2.push('c');
	mstack2.push('d');
	mstack2.push('e');
	mstack2.push('f');
	MutantStack<char>::iterator it3 = mstack2.begin();
	MutantStack<char>::iterator ite3 = mstack2.end();
	++it3;
	--it3;
	std::cout << "stack: ";
	while (it3 != ite3) {
		std::cout << *it3 << " ";
		++it3;
	}
	std::stack<char> s2(mstack2);
	std::cout << std::endl;
	std::cout << "Show copy: ";
	while (!s2.empty()) {
		std::cout << s2.top() << " ";
		s2.pop();
	}
	std::cout << std::endl;
	return 0;
}
