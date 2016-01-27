#define LGEO_H

#define LGEO_IO

#include "include/LGEO.h"
#include "Timer.h"

#include <iostream>
#include <fstream>

#define TEST_SIZE 10000000

int main() {
	srand(time(NULL));
	//lgeo::Vector2D * results = new lgeo::Vector2D[TEST_SIZE];

	timerInit(2800000000ll);

	lgeo::RayF l1{ { 0, 43 }, { 12, 27 } };
	lgeo::RayF l2{ { 1, 43 }, { 8, 27 } };
	setup(TEST_SIZE);

	for(int a = 0; a < TEST_SIZE; a++) {
		l1.contains({ 2.4f, 39.8f });
	}

	stop();

	std::cout << '\n';
	//delete results;

	system("PAUSE");
	return EXIT_SUCCESS;
}