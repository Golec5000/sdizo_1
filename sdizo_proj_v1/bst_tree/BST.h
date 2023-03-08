#ifndef SDIZO_PROJ_V1_BST_H
#define SDIZO_PROJ_V1_BST_H
#include <iostream>
#include "BST_Node.h"

class BST {
public:
    BST();
    void add_element(int key);
    void remove_element(int key);
    void display(std::string sp, std::string sn, BST_Node * v);
    int find_max();
    int find_min();
    BST_Node * find_value(int key);
    BST_Node * get_head();
private:
    BST_Node * head;
    //zminne do rysowania
    std::string cr,cl,cp;
    long bst_size;
};


#endif //SDIZO_PROJ_V1_BST_H
