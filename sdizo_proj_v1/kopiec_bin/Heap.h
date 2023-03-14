#include <iostream>
#include "../tablica_dym/Array.h"

#ifndef SDIZO_PROJ_V1_KOPIECBIN_H
#define SDIZO_PROJ_V1_KOPIECBIN_H

class Heap {

public:
    Heap();
    void display(std::string sp, std::string sn, int v);
    void add_element(int number);
    void remove();
    ~Heap();

private:
    Array * tab;
    int parent(int index);
    //zminne do rysowania
    std::string cr,cl,cp;

};


#endif //SDIZO_PROJ_V1_KOPIECBIN_H
