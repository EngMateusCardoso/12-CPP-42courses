#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <stack>
# include <sstream>

class RPN {
	private:
		std::stack<double> _rpnItens;
		bool _isOperator(std::string item);
		bool _isRpnNumber(std::string item);
		void _makeOperation(char op);

	public:
		RPN();
		~RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &rpn);

		double calculate(std::string argument);

		class RPNException : public std::exception {
			public:
				RPNException(const std::string &message);
				virtual ~RPNException() throw();
				virtual const char *what() const throw();

			private:
				std::string _message;
		};
};

#endif
