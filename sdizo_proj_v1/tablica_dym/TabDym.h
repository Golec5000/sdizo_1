#include <iostream>
#include <iomanip>

#ifndef SDIZO_PROJ_V1_TABDYM_H
#define SDIZO_PROJ_V1_TABDYM_H

class TabDym{
public:
    TabDym();
    ~TabDym();
    void add_head(int number);
    void add_tail(int number);
    void add_bottom(int index, int number);
    int search(int number);
    void remove(int number);
    void remove_head();
    void remove_tail();
    int get_size() const;
    void display();
    int * get_tab();
    void swap(int num1, int num2, int index1, int index2);
private:
    long size_tab;
    int * tab;
    void add_if_zero(int number);
    void remove_if_one_or_zero();
};

#endif //SDIZO_PROJ_V1_TABDYM_H
