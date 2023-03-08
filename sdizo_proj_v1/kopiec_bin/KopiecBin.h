#include <iostream>
#include "../tablica_dym/TabDym.h"

#ifndef SDIZO_PROJ_V1_KOPIECBIN_H
#define SDIZO_PROJ_V1_KOPIECBIN_H

class KopiecBin {

public:
    KopiecBin();
    void display(std::string sp, std::string sn, int v);
    void add_element(int number);
    void remove();
    ~KopiecBin();

private:
    TabDym * tab;
    int parent(int index);
    //zminne do rysowania
    std::string cr,cl,cp;

};


#endif //SDIZO_PROJ_V1_KOPIECBIN_H
