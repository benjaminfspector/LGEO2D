#pragma once

enum Orientation {
	CLOCKWISE,
	COUNTERCLOCKWISE,
	COLLINEAR
};

template<typename T> Orientation getOrientation(Vector2<T> p1, Vector2<T> p2, Vector2<T> p3) {
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