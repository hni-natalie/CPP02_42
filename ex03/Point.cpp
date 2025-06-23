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

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

/* 
	As x and y are const, we can't modfiy them 
	Hence, we won't be able to use copy assignment operator in this case
*/
Point& Point::operator=(const Point& other) {
	(void) other;
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}