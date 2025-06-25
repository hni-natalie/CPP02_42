/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:08:30 by hni-xuan          #+#    #+#             */
/*   Updated: 2025/06/25 13:41:55 by hni-xuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*  
	Formula = (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|

	0.5f f suffix tells the compiler to treat it as a float
*/
static float area(Point p1, Point p2, Point p3) {
	float area = ((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) + 
				  (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) +
				  (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))) / 2;

	if (area < 0)
		return (area * -1);
	return area;
}

/*  
	implement with Area Method

	1. Compute the area of ABC
	2. Compute the area of sub-triangles formed with point P
		Area of triangle PBC, APC, ABP
	3. If all the sub-area are non-zero (not on the edge) and all the sub-area sums up = area ABC,
		then point P in the triangle 
	4. If the sub-area = 0, point on the edge as they form a line 
*/
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float actual_area = area(a, b, c);
	if (actual_area == 0)
		return false;

	float area1 = area(a, b, point);
	float area2 = area(a, c, point);
	float area3 = area(b, c, point);

	if (area1 == float(0) || area2 == float(0) || area3 == float(0))
		return false;

	return ((area1 + area2 + area3) - actual_area) == 0;
}