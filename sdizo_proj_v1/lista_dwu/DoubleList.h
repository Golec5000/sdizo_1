#ifndef SDIZO_PROJ_V1_DOUBLELIST_H
#define SDIZO_PROJ_V1_DOUBLELIST_H

#include "Node.h"
#include <iomanip>
#include <iostream>

class DoubleList {
private:
    Node * head;
    Node * tail;
public:
    DoubleList();
    ~DoubleList();
    void add_front(int number);
    void add_back(int number);
    void add_bottom(int index, int number);
    void display();
    int list_size();
    int search(int number);
    void remove_front();
    void remove_back();
    void remove_by_index(int index);
    void display_back();
};


#endif //SDIZO_PROJ_V1_DOUBLELIST_H
