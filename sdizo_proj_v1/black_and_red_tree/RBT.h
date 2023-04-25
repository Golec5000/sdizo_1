#ifndef SDIZO_PROJ_V1_RBT_H
#define SDIZO_PROJ_V1_RBT_H
#include <iostream>

#include "RB_Node.h"

class RBT {

public:
    RBT();
    ~RBT();
    void add_element(int key);
    void remove_element(int key);
    void display_tree();
    RB_Node * find_value(int key);
    void roted_left(RB_Node * p);
    void roted_right(RB_Node * p);
private:
    RB_Node guard;
    RB_Node * head;

    //zminne do rysowania
    std::string cr,cl,cp;

    RB_Node * succ_min_node(RB_Node * p);
    RB_Node * find_succ_node(RB_Node * p);
    void display(std::string sp, std::string sn, RB_Node * v);
    void clear_tree(RB_Node * n);
};


#endif //SDIZO_PROJ_V1_RBT_H