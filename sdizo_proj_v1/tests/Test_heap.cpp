#include "Test_heap.h"

Test_heap::Test_heap() {}

Test_heap::~Test_heap() {
    delete heap;
    heap = nullptr;
}

long long int Test_heap::add_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();

    for(int i = 0; i < n; i++){
        heap ->add_element((std::rand()%1001)-500);
    }
    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;

}

long long int Test_heap::clear_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();
    for(int i = 0; i < n; i++){
        heap ->remove();
    }
    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;


}

long long int Test_heap::search_test(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    for(int i = 0; i < n; i++){
        int num = std::rand()%100000;
        heap->add_element(num);
        temp_tab.push_back(num);
    }

    int key = temp_tab[std::rand()%temp_tab.size()];

    start = read_QPC();
    int index  = heap->search(key);
    elapsed = read_QPC() - start;

    temp_tab.clear();
    for(int i = 0; i < n; i++ ) heap->remove();

    return (1000000.0 * elapsed) /frequency;
}

long long int Test_heap::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);

    return((long long int)count.QuadPart);
}
