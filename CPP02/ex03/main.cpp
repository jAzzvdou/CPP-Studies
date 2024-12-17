#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point point1(1, 1);
	Point point2(10, 10);

	if (bsp(a, b, c, point1))
		std::cout << "Point1 is inside the triangle" << std::endl;
	else
		std::cout << "Point1 is outside the triangle" << std::endl;

	if (bsp(a, b, c, point2))
		std::cout << "Point2 is inside the triangle" << std::endl;
	else
		std::cout << "Point2 is outside the triangle" << std::endl;

	return (0);
}
