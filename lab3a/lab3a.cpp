#include <iostream>
#include "ClassicMergeSort.h"
#include "ParallelMergeSort.h"
#include "Utils.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "Sorter.h"
int main()
{
    Sorter<int>* a = new Sorter<int>(new ClassicSortingStrategy<int>);
    std::vector<int> vec{ 1,5,7,2 };
    a->set_strategy(new ParallelSortingStrategy<int>);
    a->setArray(vec);
    a->sort();
    std::vector<int> b = a->getArray();
    for (auto elem : b)
        std::cout << elem << " ";
}