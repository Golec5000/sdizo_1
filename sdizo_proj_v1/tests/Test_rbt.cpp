#include "Test_rbt.h"

Test_rbt::Test_rbt() {}

Test_rbt::~Test_rbt() {
    delete rbt;
    rbt = nullptr;
}

long long int Test_rbt::add_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    for(int i = 0; i < n ; i++) keys.push_back(std::rand()%100000);

    start = read_QPC();

    for (int i = 0; i < n; i++) rbt->add_element(keys[i]);

    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;
}

long long int Test_rbt::clear_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    std::sort(keys.begin(),keys.end());

    start = read_QPC();
    for (int i = 0; i < n; i++) rbt->remove_element(keys[i]);
    elapsed = read_QPC() - start;
    keys.clear();



    return (1000.0 * elapsed) /frequency;
}

long long int Test_rbt::search_test(int n) {

    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    for(int i = 0; i < n; i++){
        int num = std::rand()%100000;
        rbt->add_element(num);
        keys.push_back(num);
    }

    int key = keys[std::rand()%keys.size()];

    start = read_QPC();
    auto * tmp = rbt->find_value(key);
    elapsed = read_QPC() - start;

    for (int i = 0; i < n; i++) rbt->remove_element(keys[i]);
    keys.clear();

    return (1000000.0 * elapsed) /frequency;

}

long long int Test_rbt::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);

    return((long long int)count.QuadPart);
}
