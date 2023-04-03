#include "Test_list.h"

Test_list::Test_list() {}

Test_list::~Test_list() {
    delete list;
    list = nullptr;
}

long long int Test_list::add_elements(int n) {

    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();

    for(int i = 0; i < n; i++){
        //list ->add_front((std::rand()%10));
        //list ->add_back((std::rand()%10));
        //list ->add_bottom(3,(std::rand()%10));
        //mp_list.push_back(std::rand()%10);
        //tmp_list.push_front(std::rand()%10);
        tmp_list.insert(tmp_list.begin(),std::rand()%10);
    }
    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;

}

long long int Test_list::clear(int n) {

    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
    start = read_QPC();

    for(int i = 0; i < n; i++){
        //list ->remove_front();
        //list ->remove_back();
        //list ->remove_by_index(3);
        //tmp_list.pop_back();
        //tmp_list.pop_front();
    }
    elapsed = read_QPC() - start;

    return (1000.0 * elapsed) /frequency;


}

long long int Test_list::search_element(int n) {
    srand(time(NULL));
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    for(int i = 0; i < n; i++){
        int num = std::rand()%100000;
        list ->add_back(num);
        temp_tab.push_back(num);
    }

    int key = temp_tab[std::rand()%temp_tab.size()];

    start = read_QPC();
    auto * node = list->search(key);
    elapsed = read_QPC() - start;

    temp_tab.clear();
    for(int i = 0; i < n; i++ ) list->remove_back();

    return (1000000.0 * elapsed) /frequency;
}

long long int Test_list::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);

    return((long long int)count.QuadPart);
}
