#include "Point.hpp"

Fixed getArea(Point const &a, Point const &b, Point const &c)
{
	//| Calculo da área do triângulo por método da determinante.
	Fixed det1 = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
	Fixed det2 = b.getX().toFloat() * (c.getY().toFloat() - a.getX().toFloat());
	Fixed det3 = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());

	Fixed area = Fixed(det1 + det2 + det3);
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed X = getArea(a, b, c);
	Fixed X1 = getArea(point, b, c);
	Fixed X2 = getArea(a, point, c);
	Fixed X3 = getArea(a, b, point);

	if (X == (X1 + X2 + X3) && X1 > 0 && X2 > 0 && X3 > 0)
		return (true);
	return (false);
}
