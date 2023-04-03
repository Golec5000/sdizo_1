#include "Test_bst.h"

Test_bst::Test_bst() {}

Test_bst::~Test_bst() {
    delete bst;
    bst = nullptr;
}

long long int Test_bst::add_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();

    for (int i = 0; i < n; i++) keys.push_back((std::rand()%1001)-500);

    start = read_QPC();

    for (int i = 0; i < n; i++) bst->add_element(keys[i]);

    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;

}

long long int Test_bst::clear_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    std::sort(keys.begin(),keys.end());

    start = read_QPC();

    for (int i = 0; i < n; i++) bst->remove_element(keys[i]);

    elapsed = read_QPC() - start;
    keys.clear();

    return (1000.0 * elapsed) /frequency;
}

long long int Test_bst::search_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    for(int i = 0; i < n; i++){
        int num = std::rand()%100000;
        bst->add_element(num);
        keys.push_back(num);
    }

    int key = keys[std::rand()%keys.size()];

    start = read_QPC();
    auto * tmp = bst->find_value(key);
    elapsed = read_QPC() - start;

    for (int i = 0; i < n; i++) bst->remove_element(keys[i]);
    keys.clear();

    return (1000000.0 * elapsed) /frequency;

}

long long int Test_bst::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);

    return((long long int)count.QuadPart);
}

long long int Test_bst::dsw_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    for (int i = 0; i < n; i++) keys.push_back((std::rand()%1001)-500);

    for (int i = 0; i < n; i++) bst->add_element(keys[i]);


    start = read_QPC();
    bst->dsw_alg();
    elapsed = read_QPC() - start;

    for (int i = 0; i < n; i++) bst->remove_element(keys[i]);
    keys.clear();

    return (1000000.0 * elapsed) /frequency;
}
