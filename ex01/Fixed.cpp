/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:08:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/25 15:42:17 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*  
	Fractional bits control the precision of the fixed-point number
	
	Converting float to fixed-point
		multiply (1 << fractional_bits)
		make its decimal part into whole number so that we can store 
		it in an int without losing precision 
		
	Converting fixed-point to float
		divide (1 << fractional_bits)

	std::cout by default only show 6 s.f. for decimal numbers
*/
int const Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( int const integer ) {
	std::cout << "Int constructor called\n";
	_value = integer << _fractional_bits; 
}

// roundf - rounds a float to the nearest integer
Fixed::Fixed( float const f ) {
	std::cout << "Float constructor called\n";
	// shifts the fractional part into int
	_value = roundf(f * (1 << _fractional_bits));
}

Fixed::~Fixed() {
	std::cout << "Desturctor called\n";
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	// avoid self assignment
	if (this != &other) {
		_value = other.getRawBits();
	}
	std::cout << "Copy assignment operator called\n";

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
	return _value >> _fractional_bits;
}

/*  
	std::ostream is the output stream type 
	customise what will be output from the class
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}