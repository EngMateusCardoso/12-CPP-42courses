#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <algorithm>
# include <cstdlib>

# define DATABASE	1
# define INPUT		2

class BitcoinExchange {
	private:
		std::map<std::string, float>	_database;
		std::string						_min_date;
		std::string						_max_date;

		void _extractDatabase(void);	
		bool _validateHeader(std::string line, int type);
		void _validateLine(std::string line);
		bool _validateDate(std::string date);
		bool _validateValue(std::string value);
		void _trimLine(std::string &line);
		void _writeLine(std::string date, float value);
		bool _isLeapYear(int year);

		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange &operator=(BitcoinExchange const &btc);

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void readInput(std::string filename);

		class DatabaseFileNotOpenException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class InvalidDatabaseException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class InputFileNotOpenException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class InvalidInputException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class BadInputException : public std::exception {
			public:
				BadInputException(std::string line);
				virtual ~BadInputException(void) throw() {};
				virtual const char *what() const throw();
			private:
				std::string _error_message;
		};
		class NegativeNumberException : public std::exception {
			virtual const char *what() const throw();
		};
		class TooLargeNumberException : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif
