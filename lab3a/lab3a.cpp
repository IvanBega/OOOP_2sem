#include <iostream>
#include "ClassicMergeSort.h"
#include "ParallelMergeSort.h"
#include "Utils.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
int main()
{

    ParallelMergeSort<int> sort;
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
    /*int count = 0;
    for(auto elem : c) {
        if (count++ % 15 == 0)
            std::cout << "\n";
        std::cout << elem << " ";
    }*/
}