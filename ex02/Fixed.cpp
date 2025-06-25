/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:08:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/25 13:10:25 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0) {}

Fixed::Fixed( int const integer ) {
	_value = integer << _fractional_bits; 
}

// roundf - rounds a float to the nearest integer
Fixed::Fixed( float const f ) {
	_value = roundf(f * (1 << _fractional_bits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	// avoid self assignment
	if (this != &other) {
		_value = other.getRawBits();
	}

	return *this;
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
}

float Fixed::toFloat() const {
	// convert _value into float first in order to get float
	return (float)_value / (1 << _fractional_bits);
}

int Fixed::toInt() const {
	return _value / (1 << _fractional_bits);
}

/*  
	std::ostream is the output stream type 
	customise what will be output from the class
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}

bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}

Fixed Fixed::operator+(Fixed const& other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const& other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const& other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const& other) {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_value;
	return temp;
}

Fixed& Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_value;
	return temp;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed& Fixed::min(Fixed const& f1, Fixed const& f2) {
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed& Fixed::max(Fixed const& f1, Fixed const& f2) {
	if (f1 > f2)
		return f1;
	return f2;
}