#ifndef SDIZO_PROJ_V1_TEST_BST_H
#define SDIZO_PROJ_V1_TEST_BST_H

#include "../bst_tree/BST.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <algorithm>

class Test_bst {
public:
    Test_bst();
    ~Test_bst();
    long long int add_test(int n);
    long long int clear_test(int n);
    long long int search_test(int n);
    long long int dsw_test(int n);
private:
    BST * bst = new BST();
    long long int read_QPC();
    long long int frequency, start, elapsed;
    std::vector<int> keys;

};


#endif //SDIZO_PROJ_V1_TEST_BST_H
