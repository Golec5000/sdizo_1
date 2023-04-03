#ifndef SDIZO_PROJ_V1_TEST_ARRAY_H
#define SDIZO_PROJ_V1_TEST_ARRAY_H
#include "../tablica_dym/Array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>

class Test_array {
public:
    Test_array();
    long long int add_test(int n);
    long long int clear_test(int n);
    long long int search_test(int n);
    ~Test_array();

private:
    Array * tab = new Array();
    long long int read_QPC();
    long long int frequency, start, elapsed;
    std::vector<int> temp_tab;
};


#endif //SDIZO_PROJ_V1_TEST_ARRAY_H
