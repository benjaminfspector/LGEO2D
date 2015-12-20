#define LGEO_H

#define LGEO_IO

#include "include/LGEO.h"
#include "Timer.h"

#include <iostream>
#include <fstream>

#define TEST_SIZE 10000000

int main()
{
	srand(time(NULL));
	//lgeo::Vector2D * results = new lgeo::Vector2D[TEST_SIZE];

	timerInit(2800000000ll);

	setup(TEST_SIZE);
	lgeo::SegmentD s1{ { 1, RAND_MAX }, { 1, 0 } };
	lgeo::SegmentD s2{ { 0, 1 }, { RAND_MAX, 1 } };
	for(int a = 0; a < TEST_SIZE; a++)
	{
		lgeo::intersection(s1, s2);
	}
	stop();


	//delete results;

	system("PAUSE");
	return EXIT_SUCCESS;
}