#include "RB_Node.h"

RB_Node::RB_Node() : parent(nullptr), left_child(nullptr), right_child(nullptr){}

RB_Node::~RB_Node() {
    parent = nullptr;
    left_child = nullptr;
    right_child = nullptr;
}
