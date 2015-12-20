#include "Timer.h"

long long testsize, cyclespersec;
std::chrono::system_clock::time_point timer;

void timerInit(long long cyclesPerSec)
{
	std::cout << std::fixed << std::setprecision(4);
	cyclespersec = cyclesPerSec;
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

	double avgclocks = avgtime * cyclespersec / 1000000;

	std::cout << "Average number of clocks: " << avgclocks << std::endl;
}