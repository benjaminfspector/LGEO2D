#pragma once

#include <math.h>
#include "../vector/vector2.h"

template<typename T> class Line
{
public:
	Vector2<T> pitch, source;

	Line() {}
	Line(const Vector2<T> & v1, const Vector2<T> & v2)
	{
		pitch = Vector2<T>(v1.x - v2.x, v1.y - v2.y);
		//Ensure that pitch has a positive x value:
		if(pitch.x < 0) pitch *= -1;
		//Ensure pitch has a magnitude of 1.
		pitch /= sqrt(pitch.x * pitch.x + pitch.y * pitch.y);
		if(pitch.x == 0 && pitch.y < 0) pitch.y *= -1;
		//To keep things regular, we need to make the source as small as possible. This will happen at the intersection with a perpendicular through the origin.
		source = v1;
		Vector2<T> perp = pitch.y > 0 ? Vector2<T>{ pitch.y, -pitch.x } : Vector2<T>{ -pitch.y, pitch.x };
		//Solve for intersection:
		T s = (pitch.x * source.y - pitch.y * source.x) / T(pitch.x * perp.y - pitch.y * perp.x);
		source = perp * s;
	}
	template<typename T2> Line<T>& operator=(const Line<T2> & s)
	{
		pitch = s.pitch;
		source = s.source;
		return *this;
	}
	bool contains(const Vector2<T> & v) const
	{
		return v.y - (pitch.y * v.x / pitch.x) == source.y;
	}
	T getYFromX(T x) const
	{
		if(pitch.x == 0) throw x == source.x ? Failure::INFINITE_ANSWERS : Failure::NO_ANSWER;
		return pitch.y * (x - source.x) / pitch.x + source.y;
	}
	T getXFromY(T y) const
	{
		return pitch.x * (y - source.y) / pitch.y + source.x;
	}
};

template<typename T> bool operator==(const Line<T> & l1, const Line<T> & l2)
{
	return l1.pitch == l2.pitch && l1.source == l2.source;
}
template<typename T> Relation intersects(const Line<T> & l1, const Line<T> & l2)
{
	return l1.pitch != l2.pitch ? Relation::INTERSECTION : l1.source == l2.source ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
}
template<typename T> Vector2<T> intersection(const Line<T> & l1, const Line<T> & l2)
{
	Relation r = intersects(l1, l2);
	if(r == Relation::INTERSECTION)
	{
		T s = (l1.pitch.x * (l1.source.y - l2.source.y) - l1.pitch.y * (l1.source.x - l2.source.x)) / T(l1.pitch.x * l2.pitch.y - l1.pitch.y * l2.pitch.x);
		return l2.pitch * s + l2.source;
	}
	throw r;
}

typedef Line<float> LineF;
typedef Line<double> LineD;