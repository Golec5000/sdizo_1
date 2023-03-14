#ifndef SDIZO_PROJ_V1_RB_NODE_H
#define SDIZO_PROJ_V1_RB_NODE_H


class RB_Node {
public:
    RB_Node();
    ~RB_Node();
    RB_Node * parent;
    RB_Node * left_child;
    RB_Node * right_child;
    char color;
    int key;
};


#endif //SDIZO_PROJ_V1_RB_NODE_H
