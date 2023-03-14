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
    void display(std::string sp, std::string sn, RB_Node * v);
    RB_Node *  find_max();
    RB_Node *  find_min();
    RB_Node * find_value(int key);
    RB_Node * get_head();
    void roted_left(RB_Node * p);
    void roted_right(RB_Node * p);
    void dsw_alg();
private:
    RB_Node * head;
    //zminne do rysowania
    std::string cr,cl,cp;
    RB_Node * succ_min_node(RB_Node * p);
    RB_Node * find_succ_node(RB_Node * p);
};


#endif //SDIZO_PROJ_V1_RBT_H
