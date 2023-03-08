#include "BST.h"

BST::BST() : head(nullptr),bst_size(0){

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

            if(key > p -> value) {// jeśli nowa wartość jest większa od istniejącej w drzewie idziemy na prawo

                if(p -> right_child == nullptr) { // sprawdzenie czy prawe dziecko drzewa nie istnieje

                    p -> right_child = new_node;// jeśli nie ma to dodajemy nowy węzeł
                    break;//przerywamy pętle bo nie musimy patrzeć dalej i dodaliśmy nowy element
                }
                else p = p -> right_child;//jeśli nie jeste puste przypisuje przypisajemy kolejnego
            }
            else {//jeśli wartość dodanego klucza jest mniejsza to idziemy w lewo

                if(p -> left_child == nullptr) {//taka sama procedura jak wprzypasku prawego potomka drzewa
                    p -> left_child = new_node;
                    break;
                }
                else p = p -> left_child;
            }

        }

        new_node -> parent = p; // rodzicem nowego węzła jest poprzedzający węzeł
    }

}

void BST::remove_element(int key) {

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

int BST::find_max() {
    return 0;
}

int BST::find_min() {
    return 0;
}

BST_Node * BST::find_value(int key) {

    auto * p = head;

    while (p != nullptr && p -> value != key){

        if(p -> value < key) p = p -> left_child;
        else p = p -> right_child;

    }

    return p;
}

BST_Node *BST::get_head() {
    return head;
}
