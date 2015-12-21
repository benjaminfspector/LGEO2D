#define LGEO_H

#define LGEO_IO

#include "include/LGEO.h"
#include "Timer.h"

#include <iostream>
#include <fstream>

#define TEST_SIZE 100000000

int main()
{
	srand(time(NULL));
	//lgeo::Vector2D * results = new lgeo::Vector2D[TEST_SIZE];

	timerInit(2800000000ll);

	setup(TEST_SIZE);
	lgeo::LineD l{ { 0, 43 }, { 8, 27 } };

	for(int a = 0; a < TEST_SIZE; a++)
	{
		l.getXFromY(633);
		//std::cout <<  << std::endl;
	}
	stop();


	//delete results;

	system("PAUSE");
	return EXIT_SUCCESS;
}