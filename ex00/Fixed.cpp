/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:08:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/25 13:01:35 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*  
	Fixed point
		- decimal point is at a fixed position
		- number stored as an integer
		- constant precision
		- not accurate 

	Floating point 
		- decimal point can move based on the exponent
		- stored in IEEE 754 format
		- precision varies but accurate
*/
int const Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Desturctor called\n";
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	// avoid self assignment
	if (this != &other) {
		_value = other.getRawBits();
	}

	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
}