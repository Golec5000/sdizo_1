#ifndef SDIZO_PROJ_V1_TEST_RBT_H
#define SDIZO_PROJ_V1_TEST_RBT_H

#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "../black_and_red_tree/RBT.h"

class Test_rbt {
public:
    Test_rbt();
    ~Test_rbt();
    long long int add_test(int n);
    long long int clear_test(int n);
    long long int search_test(int n);
private:
    RBT * rbt = new RBT();
    long long int read_QPC();
    long long int frequency, start, elapsed;
    std::vector<int> keys;
};


#endif //SDIZO_PROJ_V1_TEST_RBT_H
