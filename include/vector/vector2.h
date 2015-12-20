#pragma once

template<class T> class Vector2
{
public:
	T x, y;

	template<class T2> Vector2<T>& operator=(const Vector2<T2> & v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	Vector2<T>& operator+=(const Vector2<T> & v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}
	Vector2<T>& operator-=(const Vector2<T> & v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}
	Vector2<T>& operator*=(const T q)
	{
		x *= q;
		y *= q;
		return *this;
	}
	Vector2<T>& operator/=(const T q)
	{
		x /= q;
		y /= q;
		return *this;
	}
};

template<class T> bool operator==(const Vector2<T> & p1, const Vector2<T> & p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}
template<class T> Vector2<T> operator+(const Vector2<T> & p1, const Vector2<T> & p2)
{
	return Vector2<T>(p1.x + p2.x, p1.y + p2.y);
}
template<class T> Vector2<T> operator-(const Vector2<T> & p1, const Vector2<T> & p2)
{
	return Vector2<T>(p1.x - p2.x, p1.y - p2.y);
}
template<class T> Vector2<T> operator*(const Vector2<T> & p, const T q)
{
	return Vector2<T>(p1.x * q, p1.y * q);
}
template<class T> Vector2<T> operator/(const Vector2<T> & p1, const T q)
{
	return Vector2<T>(p1.x / q, p1.y / q);
}

#ifdef LGEO_IO
template<class T> std::ofstream & operator<<(std::ofstream & o, const Vector2<T> & v)
{
	o << v.x << ' ' << v.y;
	return o;
}
template<class T> std::ostream & operator<<(std::ostream & o, const Vector2<T> & v)
{
	o << "x:" << v.x << " y:" << v.y;
	return o;
}
template<class T> std::istream & operator>>(std::istream & i, Vector2<T> & v)
{
	i >> v.x >> v.y;
	return i;
}
#endif

typedef Vector2<float> Vector2F;
typedef Vector2<short> Vector2S;
typedef Vector2<int> Vector2I;
typedef Vector2<long> Vector2L;
typedef Vector2<long long> Vector2LL;
typedef Vector2<double> Vector2D;