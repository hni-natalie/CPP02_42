/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:08:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/19 14:09:34 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractional_bits = 8;

Fixed::Fixed() {}

Fixed::Fixed( int const integer ) {
	std::cout << "Int constructor called\n";
	_value = integer << _fractional_bits; 
}

// roundf - rounds a float to the nearest integer
Fixed::Fixed( float const f ) {
	std::cout << "Float constructor called\n";
	_value = roundf(f * (1 << _fractional_bits));
}

Fixed::~Fixed() {
	std::cout << "Desturctor called\n";
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	// avoid self assignment
	if (this != &other) {
		_value = other._value;
	}
	std::cout << "Copy assignment operator called\n";

	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
}

float Fixed::toFloat() const {
	// convert _value into float first in order to get float
	return static_cast<float>(_value) / (1 << _fractional_bits);
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