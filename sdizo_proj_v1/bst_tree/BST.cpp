#include "BST.h"

BST::BST() : head(nullptr){

    cr = cl = cp ="  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

}

void BST::add_element(int key) {

    auto * new_node = new BST_Node();//utworzenie nowego węzła i przypisanie mu wartości
    new_node -> value = key;

    auto * p = head;// pomocniczy wskażnik zaczynający od głowy drzewa
    if(p == nullptr) head = new_node;// jeśli head jest puste to nowy węzeł staje się głową
    else{
        while (p != nullptr){ // pętla będzie działać do poki wskaźnik nie trafi na NULL lub zostanie wcześniej przerwana

            if(key >= p -> value) {// jeśli nowa wartość jest większa od istniejącej w drzewie idziemy na prawo

                if(p -> right_child == nullptr) { // sprawdzenie czy prawe dziecko drzewa nie istnieje

                    p -> right_child = new_node;// jeśli nie ma to dodajemy nowy węzeł
                    break;//przerywamy pętle bo nie musimy patrzeć dalej i dodaliśmy nowy element
                }
                p = p -> right_child;//jeśli nie jeste puste przypisuje przypisajemy kolejnego
            }
            else {//jeśli wartość dodanego klucza jest mniejsza to idziemy w lewo

                if(p -> left_child == nullptr) {//taka sama procedura jak wprzypasku prawego potomka drzewa
                    p -> left_child = new_node;
                    break;
                }
                p = p -> left_child;
            }

        }

        new_node -> parent = p; // rodzicem nowego węzła jest poprzedzający węzeł
    }

}

void BST::remove_element(int key) {

    auto * node_to_delete = find_value(key); // wyszkiwanie węzła do usunięcia

    BST_Node * temp , * temp_2; // wskaźniki pomocnicze do usuwania z drzewa

    if(node_to_delete == nullptr) return; // jeśli nie ma takiego węzłą to wychodzimy z funkcji

    if(node_to_delete -> left_child == nullptr || node_to_delete -> right_child == nullptr) temp = node_to_delete;
    else temp = find_succ_node(node_to_delete);

    if(temp -> left_child != nullptr) temp_2 = temp -> left_child;
    else temp_2 = temp -> right_child;

    if(temp_2 != nullptr) temp_2 -> parent = temp -> parent;

    if(temp -> parent == nullptr) head = temp_2;
    else if(temp == temp -> parent ->left_child) temp -> parent ->left_child = temp_2;
    else temp -> parent -> right_child = temp_2;

    if(temp != node_to_delete) node_to_delete -> value = temp -> value;

    delete temp;

}

void BST::display(std::string sp, std::string sn, BST_Node * v) {
    std::string s;

    if( v != nullptr){
        s = sp;
        if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
        display( s + cp, cr, v -> right_child);

        s = s.substr ( 0, sp.length( ) - 2 );
        std::cout << s << sn << v -> value << std::endl;

        s = sp;
        if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
        display( s + cp, cl, v ->left_child );
    }
}

BST_Node *  BST::find_max() {
    auto * p = head;
    while (p -> right_child != nullptr) p = p -> right_child;
    return p;
}

BST_Node *  BST::find_min() {
    auto * p = head;
    while (p -> left_child != nullptr) p = p -> left_child;
    return p;
}

BST_Node * BST::find_value(int key) {

    auto * p = head;

    while (p != nullptr && p -> value != key){

        if(p -> value > key) p = p -> left_child;
        else p = p -> right_child;

    }

    return p;
}

BST_Node *BST::get_head() {
    return head;
}

BST_Node *BST::succ_min_node(BST_Node *p) {

    if(p != nullptr) while (p -> left_child != nullptr) p = p-> left_child;

    return p;
}

BST_Node *BST::find_succ_node(BST_Node *p) {

    BST_Node * temp = nullptr;
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

void BST::roted_left(BST_Node * p) {
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

void BST::roted_right(BST_Node * p) {
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

// Funkcja oblicza szybko 2^log2 ( x )
// Wartością tej funkcji jest liczba x,
// w której pozostawiono najstarszy bit 1.
//----------------------------------------
int unsigned BST::log2(unsigned int x) {
    int unsigned y = 1;

    while( ( x >>= 1 ) > 0 ) y <<= 1;

    return y;
}

void BST::dsw_alg() {
    int unsigned n,s;// liczba wierszy, licznik obrotów, licznik

    n = 0;

    auto * p = head;

    while (p != nullptr){

        if( p -> left_child != nullptr){

            roted_right(p);
            p = p -> parent;

        } else{

            n++;
            p = p -> right_child;

        }

    }
    s = n + 1 - log2(n + 1);
    p = head;

    for(int i = 0; i < s; i++){

        roted_left(p);
        p = p -> parent -> right_child;

    }

    n -= s;

    while (n > 1){

        n >>= 1;
        p = head;
        for(int  i = 0; i < n; i++){
            roted_left(p);
            p = p -> parent -> right_child;
        }

    }


}
