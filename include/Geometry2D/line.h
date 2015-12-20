#pragma once

#include <math.h>
#include "../vector/vector2.h"

template<class T> class Line
{
public:
	T slope, y_int;

	Line() {}
	Line(const Vector2<T> & v1, const Vector2<T> & v2)
	{
		slope = (v1.y - v2.y) / (v1.x - v2.x);
		y_int = v1.y 
	}
	float getSlopeF() const
	{
		return float(p1.y - p2.y) / (p1.x - p2.x);
	}
	double getSlopeD() const
	{
		return double(p1.y - p2.y) / (p1.x - p2.x);
	}
	template<class T2> Line<T>& operator=(const Line<T2> & s)
	{
		p1 = s.p1;
		p2 = s.p2;
		return *this;
	}
	T getLength() const
	{
		Vector2<T> dif = p2 - p1;
		return sqrt(dif.x * dif.x + dif.y * dif.y);
	}
	Vector2<T> getMidpoint() const
	{
		return p1 + ((p2 - p1) / 2);
	}
	bool contains(const Vector2<T> & v) const
	{
		Line<T> s = { p1, v };
		if(s.getSlopeD() != getSlopeD()) return false;
		return p1.x < p2.x ? v.x >= p1.x && v.x <= p2.x : v.x <= p1.x && v.x >= p2.x;
	}
};

template<class T> bool operator==(const Line<T> & l1, const Line<T> & l2)
{
	return l1.slope == l2.slope && l1.y_int == l2.y_int;
}
template<class T> bool intersects(const Line<T> & l1, const Line<T> & l2)
{
	return l1.slope != l2.slope || l1.y_int == l2.y_int;
}
template<class T> Vector2<T> intersection(const Line<T> & l1, const Line<T> & l2)
{
	if(intersects(l1, l2))
	{
		T xVal = round((l1.y_int - l2.y_int) / (l2.slope - l1.slope));
		return{ xVal, round(slope1 * xVal + yInt1) };
	}
}

typedef Line<float> LineF;
typedef Line<double> LineD;