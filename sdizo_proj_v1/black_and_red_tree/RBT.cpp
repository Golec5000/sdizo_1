#include "RBT.h"

RBT::RBT() : head(&guard){
    cr = cl = cp ="  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

    guard.color  = 'B';
    guard.parent = &guard;
    guard.left_child = &guard;
    guard.right_child = &guard;


}

RBT::~RBT() {
    clear_tree(head);
}

void RBT::add_element(int key) {

    RB_Node * temp = nullptr;
    auto * new_node = new RB_Node();

    new_node->key = key;
    new_node->left_child = &guard;
    new_node->right_child = &guard;
    new_node->parent = head;

    if(new_node->parent == &guard) head = new_node;
    else{


        while (true){

            if(key >= new_node->parent->key){

                if(new_node->parent->right_child == &guard){

                    new_node->parent->right_child = new_node;
                    break;

                } else new_node->parent = new_node->parent->right_child;

            }
            else{

                if(new_node->parent->left_child == &guard){

                    new_node->parent->left_child = new_node;
                    break;

                } else new_node->parent = new_node->parent->left_child;

            }

        }

        new_node->color = 'R';

        while (new_node != head && new_node->parent->color == 'R'){

            if(new_node->parent != new_node->parent->parent->left_child){

                temp = new_node->parent->parent->left_child;

                if(temp->color == 'R'){

                    new_node->parent->color = 'B';
                    temp->color = 'R';
                    new_node->parent->parent->color = 'R';
                    new_node = new_node->parent->parent;
                    continue;
                }
                if(new_node == new_node->parent->left_child){

                    new_node = new_node->parent;
                    roted_right(new_node);

                }

                new_node->parent->color = 'B';
                new_node->parent->parent->color = 'R';
                roted_left(new_node->parent->parent);
                break;

            }
            else{


                temp = new_node->parent->parent->right_child;

                if(temp->color == 'R'){

                    new_node->parent->color = 'B';
                    temp->color = 'B';
                    new_node->parent->parent->color = 'R';
                    new_node = new_node->parent->parent;
                    continue;

                }
                if(new_node == new_node->parent->right_child){

                    new_node = new_node->parent;
                    roted_left(new_node);

                }

                new_node->parent->color = 'B';
                new_node->parent->parent->color = 'R';
                roted_right(new_node->parent->parent);
                break;

            }


        }

        head->color = 'B';

    }
}

void RBT::remove_element(int key) {

    auto * del = find_value(key);
    RB_Node * p = nullptr;

    if(del->left_child == & guard || del->right_child == &guard) p = del;
    else p = find_succ_node(del);

    RB_Node * o = nullptr;
    if(p->left_child != &guard) o = p->left_child;
    else o = p->right_child;

    o->parent = p->parent;

    if(p->parent == &guard) head = o;
    else if(p == p->parent->left_child) p->parent->left_child = o;
    else p->parent->right_child = o;

    if(p != del ) del->key = p->key;

    RB_Node * k = nullptr;

    if(p->color == 'B'){

        while (o != head && o->color == 'B'){

            if(o == o->parent->left_child){

                k = o->parent->right_child;

                if(k->color == 'R'){

                    k->color = 'B';
                    o->parent->color = 'R';
                    roted_left(o->parent);
                    k = o->parent->right_child;

                }

                if(k->left_child->color == 'B' && k->right_child->color == 'B'){

                    k->color = 'R';
                    o = o->parent;
                    continue;

                }

                if(k->right_child->color == 'B'){

                    k->left_child->color = 'B';
                    k->color = 'R';
                    roted_right(k);
                    k = o->parent->right_child;

                }

                k->color = o->parent->color;
                o->parent->color = 'B';
                k->right_child->color = 'B';
                roted_left(o->parent);
                o = head;

            } else{

                k = o->parent->left_child;

                if(k->color == 'R'){

                    k->color = 'B';
                    o->parent->color = 'R';
                    roted_right(o->parent);
                    k = o->parent->left_child;

                }

                if(k->left_child->color == 'B' && k->right_child->color == 'B'){

                    k->color = 'R';
                    o = o->parent;
                    continue;

                }

                if(k->left_child->color == 'B'){

                    k->right_child->color = 'B';
                    k->color = 'R';
                    roted_left(k);
                    k = o->parent->left_child;

                }

                k->color = o->parent->color;
                o->parent->color = 'B';
                k->left_child->color = 'B';
                roted_right(o->parent);
                o = head;

            }

        }

        o->color = 'B';
        delete p;
    }

}

void RBT::display(std::string sp, std::string sn, RB_Node *v) {
    std::string t;

    if( v != &guard )
    {
        t = sp;
        if( sn == cr ) t [ t.length( ) - 2 ] = ' ';
        display( t+cp, cr, v->right_child );

        t = t.substr ( 0, sp.length( ) - 2 );
        std::cout << t << sn << v->color << ":" << v->key << std::endl;

        t = sp;
        if( sn == cl ) t [ t.length( ) - 2 ] = ' ';
        display( t+cp, cl, v->left_child );
    }
}

RB_Node *RBT::find_value(int key) {

    auto * p = head;

    while (p != nullptr && p -> key != key){

        if(p -> key > key) p = p -> left_child;
        else p = p -> right_child;

    }

    return p;

}

void RBT::roted_left(RB_Node *p) {
    RB_Node * v = nullptr, *x = nullptr;

    v = p->right_child;
    if(v != &guard){

        x = p->parent;
        p->right_child = v->left_child;
        if(p->right_child != &guard) p->right_child->parent = p;

        v->left_child = p;
        v->parent = x;
        p->parent = v;

        if(x != &guard)
            if(x->left_child == p) x->left_child = v;
            else x->right_child = v;
        else head = v;

    }

}

void RBT::roted_right(RB_Node *p) {
    RB_Node * v = nullptr, *x = nullptr;

    v = p->left_child;

    if(v != &guard){

        x = p->parent;
        p->left_child = v->right_child;
        if(p->left_child != &guard) p->left_child->parent = p;

        v->right_child = p;
        v->parent = x;
        p->parent = v;

        if(x != &guard)
            if(x->left_child == p)x->left_child = v;
            else x->right_child = v;
        else head = v;

    }

}

RB_Node *RBT::succ_min_node(RB_Node *p) {
    if(p != &guard) while (p -> left_child != &guard) p = p-> left_child;

    return p;
}

RB_Node *RBT::find_succ_node(RB_Node *p) {
    RB_Node * temp = nullptr;
    if(p != &guard) {
        if (p->right_child != &guard) return succ_min_node(p->right_child);

        temp = p->parent;

        while (temp != &guard && p == temp->right_child) {

            p = temp;
            temp = p->parent;

        }
        return temp;

    }
    return &guard;
}

void RBT::display_tree() {

    display("","",head);

}

void RBT::clear_tree(RB_Node *n) {
    if(n != &guard){

        clear_tree(n->left_child);
        clear_tree(n->right_child);
        delete n;

    }
}

RB_Node *RBT::find_max() {
    auto * p = head;
    while (p->right_child != &guard) p = p->right_child;
    return p;
}

RB_Node *RBT::find_min() {
    auto * p = head;
    while (p->left_child != &guard) p = p->left_child;
    return p;
}

RB_Node *RBT::get_head() {
    return head;
}
