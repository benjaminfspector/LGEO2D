#pragma once

#include "../vector/vector.h"

/*
The Rectangle class is internally represented with two Vector2 structs. Position represents the point with the lowest-valued coordinates within the rectangle. Size is guaranteed to always be nonnegative; if it is set to be negative, the position will be moved accordingly.
*/
template<class T> class Rectangle
{
private:
	Vector2<T> size;

public:
	Vector2<T> position;

	Rectangle()
	{
		position = { 0, 0 };
		size = { 0, 0 };
	}
	Rectangle(const Vector2<T> & pos, const Vector2<T> & s)
	{
		position = pos;
		setSize(s);
	}
	template<class T2> Rectangle<T>& operator=(const Rectangle<T2> & r)
	{
		position = r.position;
		size = r.getSize();
		return *this;
	}
	static bool operator==(const Rectangle<T2> & r1, const Rectangle<T2> & r2)
	{
		return r1.position == r2.position && r1.size == r2.size;
	}
	Vector2<T> getSize() const
	{
		return size;
	}
	void setSize(const Vector2<T> & s)
	{
		if(s.x >= 0) size.x = s.x;
		else
		{
			position.x += s.x;
			size.x = -s.x;
		}
		if(s.y >= 0) size.y = s.y;
		else
		{
			position.y += s.y;
			size.y = -s.y;
		}
	}
	T getArea() const
	{
		return size.x * size.y;
	}
	T getPerimeter() const
	{
		return size.x + size.x + size.y + size.y;
	}
	template<class U> bool contains(const Vector2<U> & p) const
	{
		return p.x >= position.x && p.x <= position.x + size.x && p.y >= position.y && p.y <= position.y + size.y;
	}

	template<class U> friend bool intersects(const Rectangle<U> & r1, const Rectangle<U> & r2);
	template<class U> friend Rectangle<U> intersection(const Rectangle<U> & r1, const Rectangle<U> & r2);
};

template<class U> bool intersects(const Rectangle<U> & r1, const Rectangle<U> & r2)
{
	return r1.position.x + r1.size.x >= r2.position.x && r2.position.x + r2.size.x >= r1.position.x && r1.position.y + r1.size.y >= r2.position.y && r2.position.y + r2.size.y >= r1.position.y;
}

template<class U> Rectangle<U> intersection(const Rectangle<U> & r1, const Rectangle<U> & r2)
{
	if(intersects(r1, r2))
	{
		Vector2<U> min = { r1.position.x > r2.position.x ? r1.position.x : r2.position.x, r1.position.y > r2.position.y ? r1.position.y : r2.position.y };
		Vector2<U> max = { r1.position.x + r1.size.x < r2.position.x + r2.size.x ? r1.position.x + r1.size.x : r2.position.x + r2.size.x, r1.position.y + r1.size.y < r2.position.y + r2.size.y ? r1.position.y + r1.size.y : r2.position.y + r2.size.y };
		return Rectangle<U>(min, max - min);
	}
	return Rectangle<U>();
}

#ifdef LGEO_IO
template<class T> std::ofstream & operator<<(std::ofstream & o, const Rectangle<T> & r)
{
	o << r.position << ' ' << r.getSize();
	return o;
}
template<class T> std::ostream & operator<<(std::ostream & o, const Rectangle<T> & r)
{
	o << "Position: " << r.position << ", Size: " << r.getSize();
	return o;
}
template<class T> std::istream & operator>>(std::istream & i, Rectangle<T> & r)
{
	Vector2<T> s;
	i >> r.position.x >> r.position.y >> s;
	r.setSize(s);
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