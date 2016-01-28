#pragma once

template<typename T> class Vector2 {
public:
	T x, y;

	Vector2() {}
	Vector2(T xN, T yN) {
		x = xN;
		y = yN;
	}
	template<typename U> Vector2<T>& operator=(const Vector2<U> & v) {
		x = v.x;
		y = v.y;
		return *this;
	}
	Vector2<T>& operator+=(const Vector2<T> & v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	Vector2<T>& operator-=(const Vector2<T> & v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	Vector2<T>& operator*=(const T q) {
		x *= q;
		y *= q;
		return *this;
	}
	Vector2<T>& operator/=(const T q) {
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

template<typename T> bool operator==(const Vector2<T> & p1, const Vector2<T> & p2) {
	return p1.x == p2.x && p1.y == p2.y;
}
template<typename T> bool operator!=(const Vector2<T> & p1, const Vector2<T> & p2) {
	return p1.x != p2.x || p1.y != p2.y;
}
template<typename T> Vector2<T> operator+(const Vector2<T> & p1, const Vector2<T> & p2) {
	return Vector2<T>(p1.x + p2.x, p1.y + p2.y);
}
template<typename T> Vector2<T> operator-(const Vector2<T> & p1, const Vector2<T> & p2) {
	return Vector2<T>(p1.x - p2.x, p1.y - p2.y);
}
template<typename T> Vector2<T> operator*(const Vector2<T> & p, const T q) {
	return Vector2<T>(p.x * q, p.y * q);
}
template<typename T> Vector2<T> operator*(const T q, const Vector2<T> & p) {
	return Vector2<T>(p.x * q, p.y * q);
}
template<typename T> Vector2<T> operator/(const Vector2<T> & p1, const T q) {
	return Vector2<T>(p.x / q, p.y / q);
}
template<typename T> Vector2<T> operator/(const T q, const Vector2<T> & p) {
	return Vector2<T>(p.x / q, p.y / q);
}

template<typename T> T distance(const Vector2<T> & p, const Vector2<T> q) {
	T dx = p.x - q.x, dy = p.y - q.y;
	return sqrt(dx * dx + dy * dy);
}
template<typename T> T angle(const Vector2<T> & p, const Vector2<T> q) {
	return atan2(q.y - p.y, q.x - p.x);
}

#ifdef LGEO_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Vector2<U> & v) {
	o << v.x << ' ' << v.y;
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Vector2<U> & v) {
	o << "x:" << v.x << " y:" << v.y;
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Vector2<U> & v) {
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