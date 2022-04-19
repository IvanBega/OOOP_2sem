#include <iostream>
#include "ClassicMergeSort.h"
#include "ParallelMergeSort.h"
#include "Utils.h"
int main()
{

    ParallelMergeSort<int> sort;
    std::vector<int> a = std::vector<int>{ 10, 18, 3,4,1 ,0, 4, 6, 5, 1, 66, 1, 4, 124 };
    //std::vector<int> b = Utils::randVec(0, 10, 5);
    sort.setArray(a);
    sort.sort();
    std::vector<int> c = sort.getArray();
    for(auto elem : c) {
        std::cout << elem << " ";
    }
}