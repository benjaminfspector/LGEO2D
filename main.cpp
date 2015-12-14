#define LGEO_H

#include "include/LGEO.h"

#include <iostream>
#include <fstream>

int main()
{
	lgeo::RectangleF rect1{ { 0, 0 }, { 1, 1 } };
	lgeo::RectangleF rect2{ { 0.91, 0.1 }, { .9, .9 } };

	std::cout << lgeo::intersection(rect1, rect2) << std::endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}