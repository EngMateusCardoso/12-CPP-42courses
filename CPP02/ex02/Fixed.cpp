#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	this->_value = 0;	
}

Fixed::Fixed(int const value) {
	this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(float const value) {
	this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed::~Fixed(void) { }

Fixed &Fixed::operator=(const Fixed &src) {
	this->_value = src.getRawBits();
	return *this;
}


int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}


float Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const {
	return (this->_value >> this->_fractionalBits);
}

bool Fixed::operator>(Fixed const &rhs) const {
	return (this->_value > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const {
	return (this->_value < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return (this->_value <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const {
	return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return (this->_value != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &o, Fixed const &src) {
	o << src.toFloat();
	return (o);
}
