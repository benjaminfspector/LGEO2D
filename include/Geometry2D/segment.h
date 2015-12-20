#pragma once

#include <math.h>
#include "../vector/vector2.h"

template<class T> class Segment
{
public:
	Vector2<T> p1, p2;

	Segment() {}
	Segment(const Vector2<T> & v1, const Vector2<T> & v2)
	{
		p1 = v1;
		p2 = v2;
	}
	float getSlopeF() const
	{
		return float(p1.y - p2.y) / (p1.x - p2.x);
	}
	double getSlopeD() const
	{
		return double(p1.y - p2.y) / (p1.x - p2.x);
	}
	template<class T2> Segment<T>& operator=(const Segment<T2> & s)
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
		Segment<T> s = { p1, v };
		if(s.getSlopeD() != getSlopeD()) return false;
		return p1.x < p2.x ? v.x >= p1.x && v.x <= p2.x : v.x <= p1.x && v.x >= p2.x;
	}
};

template<class T> bool operator==(const Segment<T> & s1, const Segment<T> & s2)
{
	return (s1.p1 == s2.p1 && s1.p2 == s2.p2) || (s1.p1 == s2.p2 && s1.p2 == s2.p1);
}
template<class T> Relation intersects(const Segment<T> & s1, const Segment<T> & s2)
{
	Orientation o1 = getOrientation(s1.p1, s1.p2, s2.p1), o2 = getOrientation(s1.p1, s1.p2, s2.p2), o3 = getOrientation(s2.p1, s2.p2, s1.p1), o4 = getOrientation(s2.p1, s2.p2, s1.p2);
	if(o1 != o2 && o3 != o4) return Relation::INTERSECTION;
	else if(s1 == s2 || ((o1 == COLLINEAR || o3 == COLLINEAR) && (s2.contains(s1.p1) || s2.contains(s1.p2)))) return Relation::CONCURRENT;
	return Relation::NO_INTERSECTION;
}
template<class T> Vector2<T> intersection(const Segment<T> & s1, const Segment<T> & s2)
{
	//Relation r = intersects(s1, s2);
	//if(r == Relation::INTERSECTION)
	{
		double slope1 = s1.getSlopeD(), slope2 = s2.getSlopeD();
		double yInt1 = s1.p1.y - (slope1 * s1.p1.x), yInt2 = s2.p1.y - (slope2*s2.p1.x);
		T xVal = round((yInt1 - yInt2) / (slope2 - slope1));
		return { xVal, round(slope1 * xVal + yInt1) };
	}
	//throw r;
}

typedef Segment<float> SegmentF;
typedef Segment<short> SegmentS;
typedef Segment<int> SegmentI;
typedef Segment<long> SegmentL;
typedef Segment<long long> SegmentLL;
typedef Segment<double> SegmentD;