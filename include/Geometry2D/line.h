#pragma once

#include <math.h>
#include "../vector/vector2.h"

template<typename T> class Line {
private:
	Vector2<T> pitch, source;

public:
	Line() {}
	Line(const Vector2<T> & v1, const Vector2<T> & v2) {
		//Create pitch vector as difference of two initializaiton points.
		pitch = Vector2<T>(v1.x - v2.x, v1.y - v2.y);
		//Ensure that pitch has a positive x value:
		if(pitch.x < 0) pitch *= -1;
		//Ensure pitch has a magnitude of 1:
		pitch /= sqrt(pitch.x * pitch.x + pitch.y * pitch.y);
		if(pitch.x == 0 && pitch.y < 0) pitch.y *= -1;
		//To keep things regular, we need to make the source as small as possible. This will happen at the intersection with a perpendicular through the origin:
		source = v1;
		Vector2<T> perp = pitch.y > 0 ? Vector2<T>{ pitch.y, -pitch.x } : Vector2<T>{ -pitch.y, pitch.x };
		//Solve for intersection:
		T s = (pitch.x * source.y - pitch.y * source.x) / T(pitch.x * perp.y - pitch.y * perp.x);
		source = perp * s;
	}
	template<typename U> Line<T>& operator=(const Line<U> & s) {
		pitch = s.pitch;
		source = s.source;
		return *this;
	}
	Vector2<T> getSource() const {
		return source;
	};
	Vector2<T> getPitch() const {
		return pitch;
	};
	template<typename U = T> U getSlope() const {
		if(pitch.x == 0) throw Failure::NO_ANSWER;
		return pitch.y / U(pitch.x);
	};
	bool contains(const Vector2<T> & v) const {
		return v.y - (pitch.y * v.x / pitch.x) == source.y;
	}
	T getYFromX(T x) const {
		if(pitch.x == 0) throw x == source.x ? Failure::INFINITE_ANSWERS : Failure::NO_ANSWER;
		return pitch.y * (x - source.x) / pitch.x + source.y;
	}
	T getXFromY(T y) const {
		return pitch.x * (y - source.y) / pitch.y + source.x;
	}

	template<typename U> friend bool operator==(const Line<U> & l1, const Line<U> & l2);
	template<typename U> friend Relation intersects(const Line<U> & l1, const Line<U> & l2);
	template<typename U> friend Vector2<U> intersection(const Line<U> & l1, const Line<U> & l2);

#ifdef LGEO_IO
	template<typename U> friend std::ofstream & operator<<(std::ofstream & o, const Line<U> & r2);
	template<typename U> friend std::ostream & operator<<(std::ostream & o, const Line<U> & r2);
	template<typename U> friend std::istream & operator>>(std::istream & i, Line<U> & r2);
#endif
};

template<typename U> bool operator==(const Line<U> & l1, const Line<U> & l2) {
	return l1.pitch == l2.pitch && l1.source == l2.source;
}
template<typename U> Relation intersects(const Line<U> & l1, const Line<U> & l2) {
	return l1.pitch != l2.pitch ? Relation::INTERSECTION : l1.source == l2.source ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
}
template<typename U> Vector2<U> intersection(const Line<U> & l1, const Line<U> & l2) {
	Relation r = intersects(l1, l2);
	if(r == Relation::INTERSECTION) {
		U s = (l1.pitch.x * (l1.source.y - l2.source.y) - l1.pitch.y * (l1.source.x - l2.source.x)) / U(l1.pitch.x * l2.pitch.y - l1.pitch.y * l2.pitch.x);
		return l2.pitch * s + l2.source;
	}
	throw r;
}

#ifdef LGEO_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Line<U> & r) {
	//Output values:
	o << r.source << ' ' << r.pitch;
	//Return modified ofstream (to allow chaining):
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Line<U> & r) {
	//Output values:
	o << "Source: " << r.source << ", Pitch: " << r.pitch;
	//Return modified ostream (to allow chaining):
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Line<U> & r) {
	//Read in values:
	i >> r.source >> r.pitch;
	//Ensure that pitch has a positive x value:
	if(r.pitch.x < 0) r.pitch *= -1;
	//Ensure pitch has a magnitude of 1:
	r.pitch /= sqrt(r.pitch.x * r.pitch.x + r.pitch.y * r.pitch.y);
	if(r.pitch.x == 0 && r.pitch.y < 0) r.pitch.y *= -1;
	//To keep things regular, we need to make the source as small as possible. This will happen at the intersection with a perpendicular through the origin:
	Vector2<T> perp = r.pitch.y > 0 ? Vector2<T>{ r.pitch.y, -r.pitch.x } : Vector2<T>{ -r.pitch.y, r.pitch.x };
	//Solve for intersection:
	T s = (r.pitch.x * r.source.y - r.pitch.y * r.source.x) / T(r.pitch.x * r.perp.y - r.pitch.y * r.perp.x);
	r.source = perp * s;
	//Return modified istream (to allow chaining):
	return i;
}
#endif

typedef Line<float> LineF;
typedef Line<double> LineD;