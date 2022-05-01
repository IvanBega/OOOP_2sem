#include <iostream>
#include "ClassicMergeSort.h"
#include "ParallelMergeSort.h"
#include "Utils.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "CompareSorts.h"
int main()
{

    /*ParallelMergeSort<int> sort;
    std::vector<int> a;
    std::vector<int> c;
    int total = 0;
    for (int i = 0; i < 100; i++)
    {
        a = Utils::randVec(0, 10000, 50000);
        sort.setArray(a);

        auto start = std::chrono::high_resolution_clock::now();

        sort.sort();

        auto stop = std::chrono::high_resolution_clock::now();


        c = sort.getArray();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        total += duration.count();
        std::cout << duration.count() << " microseconds.\n";
    }
    std::cout << "\n---------\n\nAverage is " << total / 100 << " microseconds.\n";
    int count = 0;
    for(auto elem : c) {
        if (count++ % 15 == 0)
            std::cout << "\n";
        std::cout << elem << " ";
    }*/
    CompareSorts<int> comparator(1);
    /*std::vector<int> range = {  850, 900, 950, 1000, 1100, 1200,
    1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 5000, 10000,
    15000, 30000, 50000, 100000, 200000, 300000, 500000, 1000000};*/
    std::vector<int> range = {2, 5, 10, 20, 50, 100, 200, 500,850, 900, 950, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000,
    5000, 10000, 15000, 30000, 50000, 100000, 200000, 300000, 500000, 1000000};
    comparator.TestClassic(range);
    comparator.TestParallel(range);
}