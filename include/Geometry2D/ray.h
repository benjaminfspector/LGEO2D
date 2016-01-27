#pragma once

#include <math.h>
#include "../vector/vector2.h"

template<class T> class Ray
{
public:
	Vector2<T> pitch, source;

	Ray() {}
	Ray(const Vector2<T> & src, const Vector2<T> & anotherPoint) {
		source = src;
		pitch = Vector2<T>(anotherPoint.x - src.x, anotherPoint.y - src.y);
		//Ensure pitch has a magnitude of 1.
		pitch /= sqrt(pitch.x * pitch.x + pitch.y * pitch.y);
	}
	template<class T2> Line<T>& operator=(const Ray<T2> & s) {
		pitch = s.pitch;
		source = s.source;
		return *this;
	}
	bool contains(const Vector2<T> & v) const {
		return sign(v.x - source.x) != -sign(pitch.x) && sign(v.y - source.y) != -sign(pitch.y);
	}
	T getYFromX(T x) const {
		if(sign(x - source.x) != sign(pitch.x)) throw Failure::NO_ANSWER;
		else if(pitch.x == 0) throw Failure::INFINITE_ANSWERS;
		return pitch.y * (x - source.x) / pitch.x + source.y;
	}
	T getXFromY(T y) const {
		if(sign(y - source.y) != sign(pitch.y)) throw Failure::NO_ANSWER;
		else if(pitch.y == 0) throw Failure::INFINITE_ANSWERS;
		return pitch.x * (y - source.y) / pitch.y + source.x;
	}
};

template<class T> bool operator==(const Ray<T> & r1, const Ray<T> & r2)
{
	return r1.pitch == r2.pitch && r1.source == r2.source;
}
template<class T> Relation intersects(const Ray<T> & r1, const Ray<T> & r2)
{
	Vector2<T> ds = r2.source - r1.source;
	T det = r2.pitch.x * r1.pitch.y - r2.pitch.y * r1.pitch.x;
	if(det == 0) return r1.contains(r2.source) || r2.contains(r1.source) ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
	T u = (ds.y * r2.pitch.x - ds.x * r2.pitch.y) / det;
	T v = (ds.y * r1.pitch.x - ds.x * r1.pitch.y) / det;
	if(u >= 0 && v >= 0) return Relation::INTERSECTION;
	return Relation::NO_INTERSECTION;
}
template<class T> Vector2<T> intersection(const Ray<T> & r1, const Ray<T> & r2)
{
	Vector2<T> ds = r2.source - r1.source;
	T det = r2.pitch.x * r1.pitch.y - r2.pitch.y * r1.pitch.x;
	if(det == 0) throw r1.contains(r2.source) || r2.contains(r1.source) ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
	T u = (ds.y * r2.pitch.x - ds.x * r2.pitch.y) / det;
	T v = (ds.y * r1.pitch.x - ds.x * r1.pitch.y) / det;
	if(u < 0 || v < 0) throw Relation::NO_INTERSECTION;
	return r1.source + (r1.pitch * u);
}

typedef Ray<float> RayF;
typedef Ray<double> RayD;