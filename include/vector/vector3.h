#pragma once

template<typename T> class Vector3 {
public:
	T x, y, z;

	Vector3() {}
	Vector3(T xN, T yN, T zN) {
		x = xN;
		y = yN;
		z = zN;
	}
	template<typename U> Vector3<T>& operator=(const Vector3<U> & p) {
		x = p.x;
		y = p.y;
		z = p.z;
		return *this; }
	Vector3<T>& operator+=(const Vector3<T> & p) {
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	Vector3<T>& operator-=(const Vector3<T> & p) {
		x -= p.x;
		y -= p.y;
		z -= p.z;
		return *this;
	}
	Vector3<T>& operator*=(const T q) {
		x *= q;
		y *= q;
		z *= q;
		return *this;
	}
	Vector3<T>& operator/=(const T q) {
		x /= q;
		y /= q;
		z /= q;
		return *this;
	}

	T magnitude() {
		return sqrt(x * x + y * y + z * z);
	}
};

template<typename T> bool operator==(const Vector3<T> & p1, const Vector3<T> & p2) {
	return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
}
template<typename T> bool operator!=(const Vector3<T> & p1, const Vector3<T> & p2) {
	return p1.x != p2.x || p1.y != p2.y || p1.z != p2.z;
}
template<typename T> Vector3<T> operator+(const Vector3<T> & p1, const Vector3<T> & p2) {
	return Vector3<T>(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
}
template<typename T> Vector3<T> operator-(const Vector3<T> & p1, const Vector3<T> & p2) {
	return Vector3<T>(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}
template<typename T> Vector3<T> operator*(const Vector3<T> & p, const T q) {
	return Vector3<T>(p.x * q, p.y * q, p.z * q);
}
template<typename T> Vector3<T> operator*(const T q, const Vector3<T> & p) {
	return Vector3<T>(p.x * q, p.y * q, p.z * q);
}
template<typename T> Vector3<T> operator/(const Vector3<T> & p, const T q) {
	return Vector3<T>(p.x / q, p.y / q, p.z / q);
}
template<typename T> Vector3<T> operator/(const T q, const Vector3<T> & p) {
	return Vector3<T>(p.x / q, p.y / q, p.z / q);
}

template<typename T> T distance(const Vector3<T> & p, const Vector3<T> q) {
	T dx = p.x - q.x, dy = p.y - q.y, dz = p.z - q.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

#ifdef LGEO_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Vector3<U> & v) {
	o << v.x << ' ' << v.y << ' ' << v.z;
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Vector3<U> & v) {
	o << "x:" << v.x << " y:" << v.y << " z:" << v.z;
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Vector3<U> & v) {
	i >> v.x >> v.y >> v.z;
	return i;
}
#endif

typedef Vector3<float> Vector3F;
typedef Vector3<short> Vector3S;
typedef Vector3<int> Vector3I;
typedef Vector3<long> Vector3L;
typedef Vector3<long long> Vector3LL;
typedef Vector3<double> Vector3D;