#ifndef SDIZO_PROJ_V1_TEST_HEAP_H
#define SDIZO_PROJ_V1_TEST_HEAP_H


#include "../kopiec_bin/Heap.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>

class Test_heap {
public:
    Test_heap();
    long long int add_test(int n);
    long long int clear_test(int n);
    long long int search_test(int n);
    ~Test_heap();

private:
    Heap * heap = new Heap();
    long long int read_QPC();
    long long int frequency, start, elapsed;
    std::vector<int> temp_tab;
};


#endif //SDIZO_PROJ_V1_TEST_HEAP_H
