#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Point &other);
		Point(const float x, const float y);
		~Point();

		Point &operator=(const Point &other);

		Fixed getX(void) const;
		Fixed getY(void) const;
	private:
		const Fixed _x;
		const Fixed _y;
};

#endif //| POINT_HPP
