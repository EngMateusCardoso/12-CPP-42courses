#include "ScalarConverter.hpp"

const std::string ScalarConverter::_pseudoLiterals[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) { *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this != &rhs) {
		_strLiteral = rhs._strLiteral;
		_typeLiteral = rhs._typeLiteral;
	}
	return (*this);
}

void ScalarConverter::convert(std::string str) {
	if (str.empty()) {
		std::cout << "Error: empty string" << std::endl;
		return;
	}
	_strLiteral = str;
	if (defineType(str))
		return;
	switch (_typeLiteral) {
		case PSEUDO:
			printPseudo();
			break;
		case CHAR:
			convertChar();
			break;
		case INT:
			convertInt();
			break;
		case FLOAT:
			convertFloat();
			break;
		case DOUBLE:
			convertDouble();
			break;
		default:
			break;
	}
}

bool ScalarConverter::defineType(std::string str) {
	int i = 0;

	while (i < 6) {
		if (str == _pseudoLiterals[i]) {
			_typeLiteral = PSEUDO;
			return false;
		}
		i++;
	}
	if (str.length() == 1 && !isdigit(str[0])) {
		_typeLiteral = CHAR;
		return false;
	}
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	bool hasDot = false;
	bool hasDigit = false;
	while (i < (int)str.length()) {
		if(!isdigit(str[i])) {
			if (str[i] == '.' && !hasDot && hasDigit && str[i + 1] && isdigit(str[i + 1]))
				hasDot = true;
			else if (str[i] == 'f' && i == (int)str.length() - 1 && hasDot) {
				_typeLiteral = FLOAT;
				return false;
			}
			else {
				std::cout << "Error: invalid parameter" << std::endl;
				return true;
			}
		}
		hasDigit = true;
		i++;
	}
	if (hasDot)
		_typeLiteral = DOUBLE;
	else
		_typeLiteral = INT;
	return false;
}

void ScalarConverter::printPseudo() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_strLiteral == "nanf" || _strLiteral == "nan") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (_strLiteral == "+inff" || _strLiteral == "+inf") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (_strLiteral == "-inff" || _strLiteral == "-inf") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convertChar() {
	char c = _strLiteral[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertInt() {
	int i = atoi(_strLiteral.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertFloat() {
	float f = strtof(_strLiteral.c_str(), NULL);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convertDouble() {
	double d = strtod(_strLiteral.c_str(), NULL);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::printChar(char c) {
	// CHAR_MIN is -128 and CHAR_MAX is 127
	if (atol(_strLiteral.c_str()) < CHAR_MIN || atol(_strLiteral.c_str()) > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int i) {
	// INT_MIN is -2147483648 and INT_MAX is 2147483647
	if (atol(_strLiteral.c_str()) < INT_MIN || atol(_strLiteral.c_str()) > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	if ((atol(_strLiteral.c_str()) < INT_MIN || atol(_strLiteral.c_str()) > INT_MAX) 
		&& (_typeLiteral == INT))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	if ((atol(_strLiteral.c_str()) < INT_MIN || atol(_strLiteral.c_str()) > INT_MAX) 
		&& (_typeLiteral == INT))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

std::string ScalarConverter::_strLiteral = "";
int ScalarConverter::_typeLiteral = 0;
