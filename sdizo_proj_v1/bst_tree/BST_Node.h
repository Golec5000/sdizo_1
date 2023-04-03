#ifndef SDIZO_PROJ_V1_BST_NODE_H
#define SDIZO_PROJ_V1_BST_NODE_H


class BST_Node {
public:
    BST_Node();
    BST_Node * parent;
    BST_Node * left_child;
    BST_Node * right_child;
    int value;
    ~BST_Node();

};


#endif //SDIZO_PROJ_V1_BST_NODE_H
