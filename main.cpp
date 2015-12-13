#define LGEO_H

#include "include/LGEO.h"

#include <iostream>
#include <fstream>

int main()
{
	Vector2F f1;
	Vector3F f2 = { 2, 2 };

	std::ifstream f("test.txt");
	f >> f1;
	std::cout << f1 << std::endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}