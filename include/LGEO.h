#pragma once

#ifdef LGEO_IO
#include <iostream>
#endif

namespace lgeo {
template<typename T> char sign(T x) {
	return (x > 0) - (x < 0);
}

enum Failure {
	NO_ANSWER,
	INFINITE_ANSWERS
};
enum Relation {
	NO_INTERSECTION,
	INTERSECTION,
	CONCURRENT
};

#include "vector/vector.h"
#include "geometry2d/geometry2d.h"
}