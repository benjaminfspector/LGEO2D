#pragma once

template<typename T> class Vector {
public:
	T x, y;

	Vector() {}
	Vector(T xN, T yN) {
		x = xN;
		y = yN;
	}
	template<typename U> Vector<T>& operator=(const Vector<U> & v) {
		x = v.x;
		y = v.y;
		return *this;
	}
	Vector<T>& operator+=(const Vector<T> & v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	Vector<T>& operator-=(const Vector<T> & v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	Vector<T>& operator*=(const T q) {
		x *= q;
		y *= q;
		return *this;
	}
	Vector<T>& operator/=(const T q) {
		x /= q;
		y /= q;
		return *this;
	}

	T magnitude() {
		return sqrt(x * x + y * y);
	}
	T angle() {
		return atan2(y, x);
	}
};

template<typename T> bool operator==(const Vector<T> & p1, const Vector<T> & p2) {
	return p1.x == p2.x && p1.y == p2.y;
}
template<typename T> bool operator!=(const Vector<T> & p1, const Vector<T> & p2) {
	return p1.x != p2.x || p1.y != p2.y;
}
template<typename T> Vector<T> operator+(const Vector<T> & p1, const Vector<T> & p2) {
	return Vector<T>(p1.x + p2.x, p1.y + p2.y);
}
template<typename T> Vector<T> operator-(const Vector<T> & p1, const Vector<T> & p2) {
	return Vector<T>(p1.x - p2.x, p1.y - p2.y);
}
template<typename T> Vector<T> operator*(const Vector<T> & p, const T q) {
	return Vector<T>(p.x * q, p.y * q);
}
template<typename T> Vector<T> operator*(const T q, const Vector<T> & p) {
	return Vector<T>(p.x * q, p.y * q);
}
template<typename T> Vector<T> operator/(const Vector<T> & p1, const T q) {
	return Vector<T>(p.x / q, p.y / q);
}
template<typename T> Vector<T> operator/(const T q, const Vector<T> & p) {
	return Vector<T>(p.x / q, p.y / q);
}

template<typename T, typename U = T> U distance(const Vector<T> & p, const Vector<T> q) {
	T dx = p.x - q.x, dy = p.y - q.y;
	return sqrt(dx * dx + dy * dy);
}
template<typename T, typename U = T> U angle(const Vector<T> & p, const Vector<T> q) {
	return atan2(q.y - p.y, q.x - p.x);
}

#ifdef LGEO2D_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Vector<U> & v) {
	o << v.x << ' ' << v.y;
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Vector<U> & v) {
	o << "x:" << v.x << " y:" << v.y;
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Vector<U> & v) {
	i >> v.x >> v.y;
	return i;
}
#endif

typedef Vector<float> VectorF;
typedef Vector<short> VectorS;
typedef Vector<int> VectorI;
typedef Vector<long> VectorL;
typedef Vector<long long> VectorLL;
typedef Vector<double> VectorD;