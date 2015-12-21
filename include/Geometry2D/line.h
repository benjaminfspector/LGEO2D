#pragma once

#include <math.h>
#include "../vector/vector2.h"

template<class T> class Line
{
public:
	Vector2<T> slope, source;

	Line() {}
	Line(const Vector2<T> & v1, const Vector2<T> & v2)
	{
		slope = Vector2<T>(v1.x - v2.x, v1.y - v2.y);
		//Ensure that slope has a positive x value:
		if(slope.x < 0) slope *= -1;
		//Ensure slope has a magnitude of 1.
		slope /= sqrt(slope.x * slope.x + slope.y * slope.y);
		if(slope.x == 0 && slope.y < 0) slope.y *= -1;
		//To keep things regular, we need to make the source as small as possible. This will happen at the intersection with a perpendicular through the origin.
		source = v1;
		Vector2<T> perp = slope.y > 0 ? Vector2<T>{ slope.y, -slope.x } : Vector2<T>{ -slope.y, slope.x };
		//Solve for intersection:
		T s = (slope.x * source.y - slope.y * source.x) / T(slope.x * perp.y - slope.y * perp.x);
		source = perp * s;
	}
	template<class T2> Line<T>& operator=(const Line<T2> & s)
	{
		slope = s.slope;
		source = s.source;
		return *this;
	}
	bool contains(const Vector2<T> & v) const
	{
		return v.y - (slope.y * v.x / slope.x) == source.y;
	}
	T getYFromX(T x)
	{
		return slope.y * (x - source.x) / slope.x + source.y;
	}
	T getXFromY(T y)
	{
		return slope.x * (y - source.y) / slope.y + source.x;
	}
};

template<class T> bool operator==(const Line<T> & l1, const Line<T> & l2)
{
	return l1.slope == l2.slope && l1.source == l2.source;
}
template<class T> Relation intersects(const Line<T> & l1, const Line<T> & l2)
{
	return l1.slope != l2.slope ? Relation::INTERSECTION : l1.source == l2.source ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
}
template<class T> Vector2<T> intersection(const Line<T> & l1, const Line<T> & l2)
{
	Relation r = intersects(l1, l2);
	if(r == Relation::INTERSECTION)
	{
		T s = (l1.slope.x * (l1.source.y - l2.source.y) - l1.slope.y * (l1.source.x - l2.source.x)) / T(l1.slope.x * l2.slope.y - l1.slope.y * l2.slope.x);
		return l2.slope * s + l2.source;
	}
	throw r;
}

typedef Line<float> LineF;
typedef Line<double> LineD;