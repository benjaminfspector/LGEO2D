#include "Timer.h"

long long testsize, cyclespersec;
std::chrono::system_clock::time_point timer;
double forLoopClocks;

void timerInit(long long cyclesPerSec)
{
	std::cout << std::fixed << std::setprecision(4);
	cyclespersec = cyclesPerSec;
	timer = std::chrono::high_resolution_clock::now();
	const int FOR_LOOP_CLOCK_TEST_SIZE = 10000000;
	for(int a = 0; a < FOR_LOOP_CLOCK_TEST_SIZE; a++);
	std::chrono::system_clock::time_point t = std::chrono::high_resolution_clock::now();
	forLoopClocks = double(std::chrono::duration_cast<std::chrono::nanoseconds>(t - timer).count()) / 1000000000 * cyclespersec / FOR_LOOP_CLOCK_TEST_SIZE;
}

void setup(long long s)
{
	testsize = s;
	timer = std::chrono::high_resolution_clock::now();
}

void stop()
{
	std::chrono::system_clock::time_point t = std::chrono::high_resolution_clock::now();

	double time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(t - timer).count()) / 1000000;

	std::cout << "Total time: " << time << " milliseconds " << std::endl;

	double avgtime = time / testsize * 1000;

	std::cout << "Average time: " << avgtime << " microseconds " << std::endl;

	double avgclocks = avgtime * cyclespersec / 1000000 - forLoopClocks;
	if(avgclocks < 0) avgclocks = 0;

	std::cout << "Average number of clocks: " << avgclocks << std::endl;
}