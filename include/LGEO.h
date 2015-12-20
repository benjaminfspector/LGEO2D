#pragma once

#ifdef LGEO_IO
#include <iostream>
#endif

namespace lgeo
{
enum Relation
{
	NO_INTERSECTION,
	INTERSECTION,
	CONCURRENT
};

#include "vector/vector.h"
#include "geometry2d/geometry2d.h"
}