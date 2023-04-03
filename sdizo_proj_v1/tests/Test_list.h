#ifndef SDIZO_PROJ_V1_TEST_LIST_H
#define SDIZO_PROJ_V1_TEST_LIST_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../lista_dwu/DoubleList.h"
#include <vector>
#include <list>

class Test_list {
public:
    Test_list();
    ~Test_list();
    long long int add_elements(int n);
    long long int clear(int n);
    long long int search_element(int n);

private:
    DoubleList * list = new DoubleList();
    long long int read_QPC();
    long long int frequency, start, elapsed;
    std::vector<int> temp_tab;
    std::list<int> tmp_list;
};


#endif //SDIZO_PROJ_V1_TEST_LIST_H
