#pragma once

#include <math.h>
#include "vector.h"

template<typename T> class Segment {
public:
	Vector<T> p1, p2;

	Segment() {}
	Segment(const Vector<T> & v1, const Vector<T> & v2) {
		p1 = v1;
		p2 = v2;
	}
	template<typename U> Segment<T>& operator=(const Segment<U> & s) {
		p1 = s.p1;
		p2 = s.p2;
		return *this;
	}
	template<typename U = T> U getSlope() const {
		U dx = p1.x - p2.x;
		if(dx == 0) throw Failure::NO_ANSWER;
		return (p1.y - p2.y) / dx;
	}
	T getLength() const {
		Vector<T> dif = p2 - p1;
		return sqrt(dif.x * dif.x + dif.y * dif.y);
	}
	Vector<T> getMidpoint() const {
		return p1 + ((p2 - p1) / 2);
	}
	bool contains(const Vector<T> & v) const {
		Segment<T> s = { p1, v };
		if(s.getSlopeD() != getSlopeD()) return false;
		return p1.x < p2.x ? v.x >= p1.x && v.x <= p2.x : v.x <= p1.x && v.x >= p2.x;
	}

#ifdef LGEO2D_IO
	template<typename U> friend std::ofstream & operator<<(std::ofstream & o, const Segment<U> & r2);
	template<typename U> friend std::ostream & operator<<(std::ostream & o, const Segment<U> & r2);
	template<typename U> friend std::istream & operator>>(std::istream & i, Segment<U> & r2);
#endif
};

template<typename T> bool operator==(const Segment<T> & s1, const Segment<T> & s2) {
	return (s1.p1 == s2.p1 && s1.p2 == s2.p2) || (s1.p1 == s2.p2 && s1.p2 == s2.p1);
}
template<typename T> Relation intersects(const Segment<T> & s1, const Segment<T> & s2) {
	Orientation o1 = getOrientation(s1.p1, s1.p2, s2.p1), o2 = getOrientation(s1.p1, s1.p2, s2.p2), o3 = getOrientation(s2.p1, s2.p2, s1.p1), o4 = getOrientation(s2.p1, s2.p2, s1.p2);
	if(o1 != o2 && o3 != o4) return Relation::INTERSECTION;
	else if(s1 == s2 || ((o1 == COLLINEAR || o3 == COLLINEAR) && (s2.contains(s1.p1) || s2.contains(s1.p2)))) return Relation::CONCURRENT;
	return Relation::NO_INTERSECTION;
}
template<typename T> Vector<T> intersection(const Segment<T> & s1, const Segment<T> & s2) {
	//It's faster to do the orientation-based intersection calculation than it is to find the intersection. However, this is faster here, because it batches the solution and checking.
	T slope1 = s1.getSlope(), slope2 = s2.getSlope();
	T yInt1 = s1.p1.y - (slope1 * s1.p1.x), yInt2 = s2.p1.y - (slope2*s2.p1.x);
	if(slope1 == slope2) throw yInt1 == yInt2 ? Relation::CONCURRENT : Relation::NO_INTERSECTION;
	T xVal = (yInt1 - yInt2) / (slope2 - slope1);
	if((s1.p1.x <= s1.p2.x ? xVal >= s1.p1.x && xVal <= s1.p2.x : xVal <= s1.p1.x && xVal >= s1.p2.x) && (s2.p1.x <= s2.p2.x ? xVal >= s2.p1.x && xVal <= s2.p2.x : xVal <= s2.p1.x && xVal >= s2.p2.x)) return{ xVal, slope1 * xVal + yInt1 };
	throw Relation::NO_INTERSECTION; 
}

#ifdef LGEO2D_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Segment<U> & r) {
	//Output values:
	o << r.p1 << ' ' << r.p2;
	//Return modified ofstream (to allow chaining):
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Segment<U> & r) {
	//Output values:
	o << "P1: " << r.p1 << ", P2: " << r.p2;
	//Return modified ostream (to allow chaining):
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Segment<U> & r) {
	//Read in values:
	i >> r.p1 >> r.p2;
	//Return modified istream (to allow chaining):
	return i;
}
#endif

typedef Segment<float> SegmentF;
typedef Segment<short> SegmentS;
typedef Segment<int> SegmentI;
typedef Segment<long> SegmentL;
typedef Segment<long long> SegmentLL;
typedef Segment<double> SegmentD;