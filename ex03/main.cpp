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

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	{
		Point a(1.2f, 3.4f);
		Point b(4.8f, 2.1f);
		Point c(2.9f, 5.6f);

		Point inside(3.0f, 3.5f);     // likely inside
		Point edge(3.0f, 2.75f);        // likely on edge ab
		Point vertex(1.2f, 3.4f);       // exactly on vertex a
		Point outside(11.0f, 5.0f);     // outside triangle

		std::cout << "Inside:  " << std::boolalpha << bsp(a, b, c, inside) << std::endl;
		std::cout << "Edge:    " << std::boolalpha << bsp(a, b, c, edge) << std::endl;
		std::cout << "Vertex:  " << std::boolalpha << bsp(a, b, c, vertex) << std::endl;
		std::cout << "Outside: " << std::boolalpha << bsp(a, b, c, outside) << std::endl;
	}
	{
		Point a(0, 0);
		Point b(10, 0);
		Point c(5, 10);

		Point inside(5, 5);
		Point outside(15, 5);
		Point onEdgeAB(5, 0);          
		Point onEdgeAC(2.5, 5);       
		Point onEdgeBC(7.5, 5);         
		Point onVertexA(0, 0);           
		Point onVertexB(10, 0);           
		Point onVertexC(5, 10);          
		Point veryCloseToEdge(5, 0.0001);

		std::cout << "Point inside triangle?       " << bsp(a, b, c, inside) << std::endl;
		std::cout << "Point outside triangle?      " << bsp(a, b, c, outside) << std::endl;
		std::cout << "Point on edge AB?            " << bsp(a, b, c, onEdgeAB) << std::endl;
		std::cout << "Point on edge AC?            " << bsp(a, b, c, onEdgeAC) << std::endl;
		std::cout << "Point on edge BC?            " << bsp(a, b, c, onEdgeBC) << std::endl;
		std::cout << "Point on vertex A?           " << bsp(a, b, c, onVertexA) << std::endl;
		std::cout << "Point on vertex B?           " << bsp(a, b, c, onVertexB) << std::endl;
		std::cout << "Point on vertex C?           " << bsp(a, b, c, onVertexC) << std::endl;
		std::cout << "Point very close to edge AB? " << bsp(a, b, c, veryCloseToEdge) << std::endl;
	}
    return 0;
}