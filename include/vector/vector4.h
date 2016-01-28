#pragma once

template<typename T> class Vector4 {
public:
	T x, y, z, w;

	Vector4() {}
	Vector4(T xN, T yN, T zN, T wN) {
		x = xN;
		y = yN;
		z = zN;
		w = wN;
	}
	template<typename U> Vector4<T>& operator=(const Vector4<U> & p) {
		x = p.x;
		y = p.y;
		z = p.z;
		w = p.w;
		return *this;
	}
	Vector4<T>& operator+=(const Vector4<T> & p) {
		x += p.x;
		y += p.y;
		z += p.z;
		w += p.w;
		return *this;
	}
	Vector4<T>& operator-=(const Vector4<T> & p) {
		x -= p.x;
		y -= p.y;
		z -= p.z;
		w -= p.w;
		return *this;
	}
	Vector4<T>& operator*=(const T q) {
		x *= q;
		y *= q;
		z *= q;
		w *= q;
		return *this;
	}
	Vector4<T>& operator/=(const T q) {
		x /= q;
		y /= q;
		z /= q;
		w /= q;
		return *this;
	}

	T magnitude() {
		return sqrt(x * x + y * y + z * z + w * w);
	}
};

template<typename T> T distance(const Vector4<T> & p, const Vector4<T> q) {
	T dx = p.x - q.x, dy = p.y - q.y, dz = p.z - q.z, dw = p.w - q.w;
	return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

template<typename T> bool operator==(const Vector4<T> & p1, const Vector4<T> & p2) {
	return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z && p1.w == p2.w;
}
template<typename T> bool operator!=(const Vector4<T> & p1, const Vector4<T> & p2) {
	return p1.x != p2.x || p1.y != p2.y || p1.z != p2.z || p1.w != p2.w;
}
template<typename T> Vector4<T> operator+(const Vector4<T> & p1, const Vector4<T> & p2) {
	return Vector4<T>(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z, p1.w + p2.w);
}
template<typename T> Vector4<T> operator-(const Vector4<T> & p1, const Vector4<T> & p2) {
	return Vector4<T>(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z, p1.w - p2.w);
}
template<typename T> Vector4<T> operator*(const Vector4<T> & p, const T q) {
	return Vector4<T>(p.x * q, p.y * q, p.z * q, p.w * q);
}
template<typename T> Vector4<T> operator*(const T q, const Vector4<T> & p) {
	return Vector4<T>(p.x * q, p.y * q, p.z * q, p.w * q);
}
template<typename T> Vector4<T> operator/(const Vector4<T> & p, const T q) {
	return Vector4<T>(p.x / q, p.y / q, p.z / q, p.w / q);
}
template<typename T> Vector4<T> operator/(const T q, const Vector4<T> & p) {
	return Vector4<T>(p.x / q, p.y / q, p.z / q, p.w / q);
}

#ifdef LGEO_IO
template<typename U> std::ofstream & operator<<(std::ofstream & o, const Vector4<U> & v) {
	o << v.x << ' ' << v.y << ' ' << v.z << ' ' << v.w;
	return o;
}
template<typename U> std::ostream & operator<<(std::ostream & o, const Vector4<U> & v) {
	o << "x:" << v.x << " y:" << v.y << " z:" << v.z << " w:" << v.w;
	return o;
}
template<typename U> std::istream & operator>>(std::istream & i, Vector4<U> & v) {
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