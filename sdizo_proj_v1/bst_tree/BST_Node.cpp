#include "BST_Node.h"

BST_Node::BST_Node() : parent(nullptr), left_child(nullptr), right_child(nullptr){}

BST_Node::~BST_Node() {

    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;

}
