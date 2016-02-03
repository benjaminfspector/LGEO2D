#define LGEO2D_IO
#include "include/LGEO2D.h"
#include "Timer.h"

#include <iostream>
#include <fstream>

#define TEST_SIZE 10000

int main() {
	using namespace lgeo2d;

	srand(time(NULL));

	timerInit(2800000000ll);

	SegmentF l1{ { 0, 43 }, { 12, 27 } };
	SegmentF l2{ { 1, 43 }, { 8, 27 } };
	setup(TEST_SIZE);

	for(int a = 0; a < TEST_SIZE; a++) {
		std::cout << intersection(l1, l2);
	}

	stop();

	std::cout << '\n';
	//delete results;

	system("PAUSE");
	return EXIT_SUCCESS;
}