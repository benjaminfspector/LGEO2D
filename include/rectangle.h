#pragma once

#include "vector.h"

/*
The Rectangle class is internally represented with two Vector structs. Position represents the point with the lowest-valued coordinates within the rectangle. Size is guaranteed to always be nonnegative; if it is set to be negative, the position will be moved accordingly.
*/
template<typename T> class Rectangle
{
private:
	Vector<T> size;

public:
	Vector<T> position;

	Rectangle() {
		position = { 0, 0 };
		size = { 0, 0 };
	}
	Rectangle(const Vector<T> & pos, const Vector<T> & s) {
		position = pos;
		setSize(s);
	}
	template<typename U> Rectangle<T>& operator=(const Rectangle<U> & r) {
		position = r.position;
		size = r.getSize();
		return *this;
	}
	Vector<T> getSize() const {
		return size;
	}
	void setSize(const Vector<T> & s)
	{
		if(s.x >= 0) size.x = s.x;
		else {
			position.x += s.x;
			size.x = -s.x;
		}
		if(s.y >= 0) size.y = s.y;
		else {
			position.y += s.y;
			size.y = -s.y;
		}
	}
	T getArea() const {
		return size.x * size.y;
	}
	T getPerimeter() const {
		return size.x + size.x + size.y + size.y;
	}
	template<typename U> bool contains(const Vector<U> & p) const {
		return p.x >= position.x && p.x <= position.x + size.x && p.y >= position.y && p.y <= position.y + size.y;
	}
	template<typename U> bool contains(const Rectangle<U> & p) const {
		return position.x <= p.position.x && position.y <= p.position.y && position.x + size.x >= p.position.x + p.size.x && position.y + size.y >= p.position.y + p.size.y;
	}

	template<typename U> friend bool operator==(const Rectangle<U> & r1, const Rectangle<U> & r2);
	template<typename U> friend bool intersects(const Rectangle<U> & r1, const Rectangle<U> & r2);
	template<typename U> friend Rectangle<U> intersection(const Rectangle<U> & r1, const Rectangle<U> & r2);

#ifdef LGEO2D_IO
	template<typename U> friend std::ofstream & operator<<(std::ofstream & o, const Rectangle<U> & r);
	template<typename U> friend std::ostream & operator<<(std::ostream & o, const Rectangle<U> & r);
	template<typename U> friend std::istream & operator>>(std::istream & i, Rectangle<U> & r);
#endif
};

template<typename T> bool operator==(const Rectangle<T> & r1, const Rectangle<T> & r2) {
	return r1.position == r2.position && r1.size == r2.size;
}
template<typename U> bool intersects(const Rectangle<U> & r1, const Rectangle<U> & r2) {
	return r1.position.x + r1.size.x >= r2.position.x && r2.position.x + r2.size.x >= r1.position.x && r1.position.y + r1.size.y >= r2.position.y && r2.position.y + r2.size.y >= r1.position.y;
}

template<typename U> Rectangle<U> intersection(const Rectangle<U> & r1, const Rectangle<U> & r2) {
	if(intersects(r1, r2)) {
		Vector<U> min = { r1.position.x > r2.position.x ? r1.position.x : r2.position.x, r1.position.y > r2.position.y ? r1.position.y : r2.position.y };
		Vector<U> max = { r1.position.x + r1.size.x < r2.position.x + r2.size.x ? r1.position.x + r1.size.x : r2.position.x + r2.size.x, r1.position.y + r1.size.y < r2.position.y + r2.size.y ? r1.position.y + r1.size.y : r2.position.y + r2.size.y };
		return Rectangle<U>(min, max - min);
	}
	throw NO_INTERSECTION;
}

#ifdef LGEO2D_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Rectangle<U> & r) {
	//Output values:
	o << r.position << ' ' << r.size;
	//Return modified ofstream (to allow chaining):
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Rectangle<U> & r) {
	//Output values:
	o << "Position: " << r.position << ", Size: " << r.size;
	//Return modified ostream (to allow chaining):
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Rectangle<U> & r) {
	//Read in values:
	i >> r.position >> r.size;
	//Return modified istream (to allow chaining):
	return i;
}
#endif

typedef Rectangle<float> RectangleF;
typedef Rectangle<short> RectangleS;
typedef Rectangle<unsigned short> RectangleUS;
typedef Rectangle<unsigned int> RectangleUI;
typedef Rectangle<int> RectangleI;
typedef Rectangle<unsigned long> RectangleUL;
typedef Rectangle<long> RectangleL;
typedef Rectangle<unsigned long long> RectangleULL;
typedef Rectangle<long long> RectangleLL;
typedef Rectangle<double> RectangleD;