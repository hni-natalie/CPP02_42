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

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				_value;
		static int const	_fractional_bits;
	
	public:
		Fixed();
		Fixed( int const integer );
		Fixed( float const f );
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits(int const raw );
		float toFloat( void ) const;
		int	toInt( void ) const;

		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;

		// return a new obj so not a reference
		Fixed operator+(Fixed const& other);
		Fixed operator-(Fixed const& other);
		Fixed operator*(Fixed const& other);
		Fixed operator/(Fixed const& other);

		// returns a reference to the modified object
		Fixed& operator++(); //pre-increment
		Fixed& operator++(int); //post-increment
		Fixed& operator--(); //pre-decrement
		Fixed& operator--(int); //post-decrement

		static Fixed& min(Fixed& f1, Fixed& f2);
		static const Fixed& min(Fixed const& f1, Fixed const& f2);
		static Fixed& max(Fixed& f1, Fixed& f2);
		static const Fixed& max(Fixed const& f1, Fixed const& f2);
	};
	
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif 