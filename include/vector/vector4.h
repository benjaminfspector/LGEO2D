#pragma once

template<class T> struct Vector4
{
	T x, y, z, w;

	template<class T2> Vector4<T>& operator=(const Vector4<T2> & p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
		w = p.w;
		return *this;
	}
	static bool operator==(const Vector4<T> & p1, const Vector4<T> & p2)
	{
		return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z && p1.w == p2.w;
	}
	Vector4<T>& operator+=(const Vector4<T> & p)
	{
		x += p.x;
		y += p.y;
		z += p.z;
		w += p.w;
		return *this;
	}
	Vector4<T>& operator-=(const Vector4<T> & p)
	{
		x -= p.x;
		y -= p.y;
		z -= p.z;
		w -= p.w;
		return *this;
	}
	Vector4<T>& operator*=(const T q)
	{
		x *= q;
		y *= q;
		z *= q;
		w *= q;
		return *this;
	}
	Vector4<T>& operator/=(const T q)
	{
		x /= q;
		y /= q;
		z /= q;
		w /= q;
		return *this;
	}
};

template<class T> Vector4<T> operator+(const Vector4<T> & p1, const Vector4<T> & p2)
{
	return{ p1.x + p2.x, p1.y + p2.y, p1.z + p2.z, p1.w + p2.w };
}
template<class T> Vector4<T> operator-(const Vector4<T> & p1, const Vector4<T> & p2)
{
	return{ p1.x - p2.x, p1.y - p2.y, p1.z - p2.z, p1.w - p2.w };
}
template<class T> Vector4<T> operator*(const Vector4<T> & p1, const T q)
{
	return{ p1.x * q, p1.y * q, p1.z * q, p1.w * q };
}
template<class T> Vector4<T> operator/(const Vector4<T> & p1, const T q)
{
	return{ p1.x / q, p1.y / q, p1.z / q, p1.w / q };
}

#ifdef LGEO_IO
template<class T> std::ofstream & operator<<(std::ofstream & o, const Vector4<T> & v)
{
	o << v.x << ' ' << v.y << ' ' << v.z << ' ' << v.w;
	return o;
}
template<class T> std::ostream & operator<<(std::ostream & o, const Vector4<T> & v)
{
	o << "x:" << v.x << " y:" << v.y << " z:" << v.z << " w:" << v.w;
	return o;
}
template<class T> std::istream & operator>>(std::istream & i, Vector4<T> & v)
{
	i >> v.x >> v.y >> v.z >> v.w;
	return i;
}
#endif

typedef Vector4<float> Vector4F;
typedef Vector4<short> Vector4S;
typedef Vector4<int> Vector4I;
typedef Vector4<long> Vector4L;
typedef Vector4<long long> Vector4LL;
typedef Vector4<double> Vector4D;