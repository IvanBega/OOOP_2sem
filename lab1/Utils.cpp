#include "Utils.h"
#include <conio.h>
#include <random>
#include <ctime>

int Utils::randInt(int min, int max)
{
    static std::random_device rd;
    static std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
    static std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int> dist(min, max);

    return dist(gen);
}