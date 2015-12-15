#define LGEO_H

#define LGEO_IO

#include "include/LGEO.h"

#include <iostream>
#include <fstream>

int main()
{
	lgeo::RectangleD rect1{ { 0, 0.1 }, { 1, 1 } };
	lgeo::RectangleD rect2{ { 0, 0 }, { 1, 1 } };

	std::cout << (rect2 == rect1) << std::endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}