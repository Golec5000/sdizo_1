#include <algorithm>
#include "Test_array.h"

Test_array::Test_array(){}

long long int Test_array::add_test(int n) {

    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();

    for(int i = 0; i < n; i++){

        //tab ->add_tail((std::rand()%10));
        //tab ->add_head((std::rand()%10));
        //tab ->add_bottom(tab->get_size()/2,(std::rand()%10));
        //temp_tab.push_back((std::rand()%10));
        //temp_tab.insert(temp_tab.end(),std::rand()%10);
        //temp_tab.insert(temp_tab.begin(),std::rand()%10);
        temp_tab.insert(temp_tab.begin() + (temp_tab.size()/2),std::rand()%10);
    }
    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;


}

long long int Test_array::clear_test(int n) {

    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();
    for(int i = 0; i < n; i++){
        //tab ->remove_tail();
        //tab->remove_head();
        //tab->remove(tab->get_size()/2);
        //temp_tab.pop_back();
        //temp_tab.erase(temp_tab.begin());
        temp_tab.erase(temp_tab.begin() + (temp_tab.size()/2));
    }

    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;


}

long long int Test_array::search_test(int n) {

    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    for(int i = 0; i < n; i++){
        int num = std::rand()%100000;
        //tab ->add_tail(num);
        temp_tab.push_back(num);
    }

    int key = temp_tab[std::rand()%temp_tab.size()];

    start = read_QPC();
    bool test = std::binary_search(temp_tab.begin(),temp_tab.end(),key);
    elapsed = read_QPC() - start;

    temp_tab.clear();
    //for(int i = 0; i < n; i++ ) tab->remove_head();

    return (1000000.0 * elapsed) /frequency;

}

Test_array::~Test_array() {
    delete tab;
    tab = nullptr;
}

long long int Test_array::read_QPC() {

    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);

    return((long long int)count.QuadPart);
}
