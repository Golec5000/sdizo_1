#ifndef SDIZO_PROJ_V1_BST_H
#define SDIZO_PROJ_V1_BST_H
#include <iostream>
#include "BST_Node.h"

class BST {
public:
    BST();
    ~BST();
    void add_element(int key);
    void remove_element(int key);
    void display_tree();
    BST_Node *  find_max();
    BST_Node *  find_min();
    BST_Node * find_value(int key);
    BST_Node * get_head();
    void roted_left(BST_Node * p);
    void roted_right(BST_Node * p);
    void dsw_alg();
private:
    void display(std::string sp, std::string sn, BST_Node * v);
    BST_Node * head;
    //zminne do rysowania
    std::string cr,cl,cp;
    BST_Node * succ_min_node(BST_Node * p);
    BST_Node * find_succ_node(BST_Node * p);
    int unsigned log2 ( int unsigned x);
    void clear_tree(BST_Node * n);
};


#endif //SDIZO_PROJ_V1_BST_H
