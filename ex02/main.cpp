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

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const b(1);
	// Fixed c ( Fixed ( 5.5f ));

	// a = a + b;
	// std::cout << a + b << std::endl;
	// std::cout << a - b << std::endl;
	// std::cout << c * b << std::endl;
	// std::cout << c / b << std::endl;

	// if (a == b) {
    //     std::cout << "a is equal to b" << std::endl;
    // }
    // else if (a < b) {
    //     std::cout << "a is smaller than b" << std::endl;
    // }
	// else if (a > b) {
    //     std::cout << "a is larger than b" << std::endl;
    // }
	// else {
    //     std::cout << "a is not equal to b" << std::endl;
    // }

	std::cout << a << std::endl;
	std::cout << ++a << std::endl; // 1/256
	std::cout << a << std::endl;
	std::cout << a++ << std::endl; // 2/256
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	
	return 0;
}
