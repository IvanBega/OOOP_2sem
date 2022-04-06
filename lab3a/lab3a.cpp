#include <iostream>
#include "ClassicMergeSort.h"
int main()
{

    ClassicMergeSort<int> sort;
    std::vector<int> a = std::vector<int>{ 10, 18, 3,4,1 ,0 };
    sort.setArray(a);
    sort.sort();
    std::vector<int> b = sort.getArray();
    for(auto elem : b) {
        std::cout << elem << " ";
    }
}