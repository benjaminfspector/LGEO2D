#pragma once

#include <math.h>
#include "../vector/vector2.h"

template<typename T> class Ray
{
private:
	Vector2<T> pitch;
public:
	Vector2<T> source;

	Ray() {}
	Ray(const Vector2<T> & src, const Vector2<T> & anotherPoint) {
		source = src;
		pitch = Vector2<T>(anotherPoint.x - src.x, anotherPoint.y - src.y);
		//Ensure pitch has a magnitude of 1.
		pitch /= sqrt(pitch.x * pitch.x + pitch.y * pitch.y);
	}
	template<typename U> Line<T>& operator=(const Ray<U> & s) {
		pitch = s.pitch;
		source = s.source;
		return *this;
	}
	bool contains(const Vector2<T> & v) const {
		return sign(v.x - source.x) != -sign(pitch.x) && sign(v.y - source.y) != -sign(pitch.y);
	}
	Vector2<T> getPitch() const {
		return pitch;
	};
	template<typename U = T> U getSlope() const {
		if(pitch.x == 0) throw Failure::NO_ANSWER;
		return pitch.y / U(pitch.x);
	};
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

	template<typename U> friend bool operator==(const Ray<U> & r1, const Ray<U> & r2);
	template<typename U> friend Relation intersects(const Ray<U> & r1, const Ray<U> & r2);
	template<typename U> friend Vector2<U> intersection(const Ray<U> & r1, const Ray<U> & r2);

#ifdef LGEO_IO
	template<typename U> friend std::ofstream & operator<<(std::ofstream & o, const Ray<U> & r2);
	template<typename U> friend std::ostream & operator<<(std::ostream & o, const Ray<U> & r2);
	template<typename U> friend std::istream & operator>>(std::istream & i, Ray<U> & r2);
#endif
};

template<typename U> bool operator==(const Ray<U> & r1, const Ray<U> & r2)
{
	return r1.pitch == r2.pitch && r1.source == r2.source;
}
template<typename U> Relation intersects(const Ray<U> & r1, const Ray<U> & r2)
{
	Vector2<U> ds = r2.source - r1.source;
	U det = r2.pitch.x * r1.pitch.y - r2.pitch.y * r1.pitch.x;
	if(det == 0) return r1.contains(r2.source) || r2.contains(r1.source) ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
	U u = (ds.y * r2.pitch.x - ds.x * r2.pitch.y) / det;
	U v = (ds.y * r1.pitch.x - ds.x * r1.pitch.y) / det;
	if(u >= 0 && v >= 0) return Relation::INTERSECTION;
	return Relation::NO_INTERSECTION;
}
template<typename U> Vector2<U> intersection(const Ray<U> & r1, const Ray<U> & r2)
{
	Vector2<U> ds = r2.source - r1.source;
	U det = r2.pitch.x * r1.pitch.y - r2.pitch.y * r1.pitch.x;
	if(det == 0) throw r1.contains(r2.source) || r2.contains(r1.source) ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
	U u = (ds.y * r2.pitch.x - ds.x * r2.pitch.y) / det;
	U v = (ds.y * r1.pitch.x - ds.x * r1.pitch.y) / det;
	if(u < 0 || v < 0) throw Relation::NO_INTERSECTION;
	return r1.source + (r1.pitch * u);
}

#ifdef LGEO_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Ray<U> & r) {
	//Output values:
	o << r.source << ' ' << r.pitch;
	//Return modified ofstream (to allow chaining):
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Ray<U> & r) {
	//Output values:
	o << "Source: " << r.source << ", Pitch: " << r.pitch;
	//Return modified ostream (to allow chaining):
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Ray<U> & r) {
	//Read in values:
	i >> r.source >> r.pitch;
	//Ensure pitch has a magnitude of 1.
	pitch /= sqrt(pitch.x * pitch.x + pitch.y * pitch.y);
	//Return modified istream (to allow chaining):
	return i;
}
#endif

typedef Ray<float> RayF;
typedef Ray<double> RayD;