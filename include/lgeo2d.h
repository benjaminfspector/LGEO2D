#pragma once

#ifdef LGEO2D_IO
#include <iostream>
#endif

namespace lgeo2d {
template<typename T> char sign(T x) {
	return (x > 0) - (x < 0);
}

#include "vector.h"

enum Failure {
	NO_ANSWER,
	INFINITE_ANSWERS
};
enum Relation {
	NO_INTERSECTION,
	INTERSECTION,
	CONCURRENT
};
enum Orientation {
	CLOCKWISE,
	COUNTERCLOCKWISE,
	COLLINEAR
};
template<typename T> Orientation getOrientation(Vector<T> p1, Vector<T> p2, Vector<T> p3) {
	double val = double(p2.y - p1.y)*(p3.x - p2.x) - double(p3.y - p2.y)*(p2.x - p1.x);
	if(val > -0.0001 && val < 0.0001) return COLLINEAR;
	if(val < 0) return COUNTERCLOCKWISE;
	return CLOCKWISE;
};

//Include polygon later.
#include "segment.h"
#include "line.h"
#include "ray.h"
#include "rectangle.h"
}