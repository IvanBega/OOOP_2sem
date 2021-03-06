#include "Utils.h"
#include "Utils.h"
#include <conio.h>
#include <random>
#include <ctime>
/// <summary>
/// Returns random integer between min and max (border values are included)
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
int Utils::randInt(int min, int max)
{
    static std::random_device rd;
    static std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
    static std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int> dist(min, max);

    return dist(gen);
}
/// <summary>
/// Returns a vector of random integers (border values are included) of size "size"
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <param name="size"></param>
/// <returns></returns>
std::vector<int> Utils::randVec(int min, int max, int size)
{
    std::vector<int> a;
    if (size < 0)
        return a;
    for (int i = 0; i < size; i++)
        a.push_back(randInt(min, max));
    return a;
}
