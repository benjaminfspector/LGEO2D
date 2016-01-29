#define LGEO_H

#define LGEO_IO

#include "include/LGEO.h"
#include "Timer.h"

#include <iostream>
#include <fstream>

#define TEST_SIZE 20

int main() {
	srand(time(NULL));

	timerInit(2800000000ll);

	lgeo::SegmentF l1{ { 0, 43 }, { 12, 27 } };
	lgeo::SegmentF l2{ { 1, 43 }, { 8, 27 } };
	setup(TEST_SIZE);

	for(int a = 0; a < TEST_SIZE; a++) {
		std::cout << lgeo::intersection(l1, l2);
	}

	stop();

	std::cout << '\n';
	//delete results;

	system("PAUSE");
	return EXIT_SUCCESS;
}