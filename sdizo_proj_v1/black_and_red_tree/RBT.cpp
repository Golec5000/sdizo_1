#include "RBT.h"

RBT::RBT() : head(nullptr){
    cr = cl = cp ="  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;
}

RBT::~RBT() {

}

void RBT::add_element(int key) {

    auto * new_node = new RB_Node();
    RB_Node * guard = nullptr;
    auto * x = head;
    std::cout<< "test 1" << std::endl;
    while (x != nullptr){
        guard = x;
        if(new_node->key < x->key) x = x->left_child;
        else x = x->right_child;

    }
    new_node->parent = guard;
    if(guard == nullptr) head = new_node;
    else if(new_node->key < guard->key) guard->left_child = new_node;
    else guard->right_child = new_node;

    new_node->left_child = nullptr;
    new_node->right_child = nullptr;
    new_node->color = 'R';

    std::cout<< "test 2" << std::endl;
    while (new_node->parent->color == 'R'){

        if(new_node->parent == new_node->parent->parent->left_child){
            std::cout<< "test 3" << std::endl;
            guard = new_node->parent->parent->right_child;

            if(guard->color == 'R'){

                new_node->parent->color = 'B';
                guard->color = 'B';
                new_node->parent->parent->color = 'R';
                new_node = new_node->parent->parent;

            } else if(new_node == new_node->parent->right_child){

                new_node = new_node->parent;
                roted_left(new_node);
            } else{

                new_node->parent->color = 'B';
                new_node->parent->color = 'R';
                roted_right(new_node->parent->parent);

            }


        } else{
            std::cout<< "test 4" << std::endl;
            guard = new_node->parent->parent->left_child;
            if(guard->color == 'R'){

                new_node->parent->color = 'B';
                guard->color = 'B';
                new_node->parent->parent->color = 'R';
                new_node = new_node->parent->parent;

            } else if(new_node == new_node->parent->left_child){

                new_node = new_node->parent;
                roted_right(new_node);
            } else{

                new_node->parent->color = 'B';
                new_node->parent->color = 'R';
                roted_left(new_node->parent->parent);

            }

        }

        head->color = 'B';

    }

}

void RBT::remove_element(int key) {

}

void RBT::display(std::string sp, std::string sn, RB_Node *v) {

}

RB_Node *RBT::find_max() {
    return nullptr;
}

RB_Node *RBT::find_min() {
    return nullptr;
}

RB_Node *RBT::find_value(int key) {
    return nullptr;
}

RB_Node *RBT::get_head() {
    return nullptr;
}

void RBT::roted_left(RB_Node *p) {
    auto * v = p -> right_child;

    if(v == nullptr) return;
    auto * x = p -> parent;

    p -> right_child = v -> left_child;
    if(p -> right_child != nullptr) p -> right_child -> parent = p;

    v -> left_child = p;
    v -> parent = x;
    p -> parent = v;

    if(x != nullptr){
        if(x -> left_child == p) x -> left_child = v;
        else x -> right_child = v;
    } else head = v;
}

void RBT::roted_right(RB_Node *p) {
    auto * v = p -> left_child;

    if(v == nullptr) return;
    auto * x = p -> parent;

    p -> left_child = v -> right_child;
    if(p -> left_child != nullptr) p -> left_child -> parent = p;

    v -> right_child = p;
    v -> parent = x;
    p -> parent = v;

    if(x != nullptr) {
        if (x->left_child == p) x->left_child = v;
        else x->right_child = v;
    } else head = v;
}

void RBT::dsw_alg() {

}

RB_Node *RBT::succ_min_node(RB_Node *p) {
    if(p != nullptr) while (p -> left_child != nullptr) p = p-> left_child;

    return p;
}

RB_Node *RBT::find_succ_node(RB_Node *p) {
    RB_Node * temp = nullptr;
    if(p != nullptr) {
        if (p->right_child != nullptr) return succ_min_node(p->right_child);

        temp = p->parent;

        while (temp != nullptr && p == temp->right_child) {

            p = temp;
            temp = p->parent;

        }


    }
    return temp;
}
