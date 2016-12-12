#include "RandomUtil.h"
#include <random>
#include <chrono>

int RandomUtil::getRandomInt(const int& min, const int& max)
{
	std::uniform_int_distribution<int> ud(min, max);
	std::random_device rd;
	return ud(rd);
}

float RandomUtil::nextDouble()
{
	static std::mt19937 rng_engine((unsigned)time(nullptr));
	static std::uniform_real_distribution<float> distribution;
	return distribution(rng_engine);
}

void RandomUtil::generateSeed()
{
	std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
}
