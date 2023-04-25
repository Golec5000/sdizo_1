#include "BST.h"

BST::BST() : head(nullptr){

    // ustawienie wartości bazowych dla zmiennych odpowiedzialnych za rysowanie
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
            else {//jeśli wartość dodanego klucza jest mniejsza to idziemy w lewo iwykonujemy lustrzana procedura jak wprzypasku prawego potomka drzewa

                if(p -> left_child == nullptr) {
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

    //sprawdzenie czy węzeł nie posiada potomków lub posiada nie posiada jednego
    //jeśli warunek jest spełniony przypisujemy ten węzeł do zmiennej tymczasowej
    // w innym przypadku do zmiennej tymczasowj przypisajemy następnika węzła
    if(node_to_delete -> left_child == nullptr || node_to_delete -> right_child == nullptr) temp = node_to_delete;
    else temp = find_succ_node(node_to_delete);

    //sprawdzamy czy węzeł temp posiada lewego syna jeśli tak to przypisujemy go do temp_2
    if(temp -> left_child != nullptr) temp_2 = temp -> left_child;
    else temp_2 = temp -> right_child;//jeśli nie posiada to przypisyjemy prawego potomka
    //niezależnie od przypadku temp_2 staje się potomkiem temp

    //jeśli temp_2 istnieje i nie został mu przypisany null
    //wtedy rodzic temp zostaje rodzizem węzła temp_2
    if(temp_2 != nullptr) temp_2 -> parent = temp -> parent;

    //jeśli rodzic węzła temp nie istenieje to głowa drzewa staje się węzłem temp_2
    if(temp -> parent == nullptr) head = temp_2;
    //jeśli temp jest lewym potomkiem swojego rodzica to wtedy przypisujemy mu węzeł temp_2
    else if(temp == temp -> parent ->left_child) temp -> parent ->left_child = temp_2;
    //w innym przpadku wezeł temp_2 przypisujemy do prawego potomka rodzica temp
    else temp -> parent -> right_child = temp_2;

    //jeśli węzeł temp nie jest węzłem do usunięcia to w miejsce usuwanego wpisujemy wartość klucza z temp
    if(temp != node_to_delete) node_to_delete -> value = temp -> value;

    delete temp;

}

//funkacja przekopionowana od kopca binarnego zmodyfikowana pod BST
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

//metoda wyszukuje węzeł ze wskazanym kluczem
BST_Node * BST::find_value(int key) {

    auto * p = head; //węzeł pomocniczy przyjmuje wartość korzenia

    while (p != nullptr && p -> value != key){

        if(key < p->value) p = p -> left_child; // Jeśli klucz jej mniejszy od wartości klucza to idzemy lewą ścierzką
        else p = p -> right_child; // w innym przypadku wędrujemy prawą ścierzką

    }

    return p;
}

//metoda wyszukuje węzeł z najmniejszą wartością klucza zaczynając od wzkazanego węzłą
BST_Node *BST::min_node(BST_Node *p) {

    if(p != nullptr) while (p -> left_child != nullptr) p = p-> left_child;

    return p;
}

//metoda wyszuuje następnika dla podanego węzłą
BST_Node *BST::find_succ_node(BST_Node *p) {

    BST_Node * temp = nullptr;//węzeł pomocniczy
    if(p != nullptr) {
        //sprawdzenie czy dany węzeł ma prawego potomka
        //jeśli tak funkcja zwraca węzeł minimalny węzeł zaczynając od swojego prawego potomka
        if (p->right_child != nullptr) return min_node(p->right_child);

        //jeśli nie ma prawego potomka to do zmiennej pomocniczej przypisajemy węzeł rodzica podanego do funkcji
        temp = p->parent;

        //pętla wyszukująca następnika
        while (temp != nullptr && p == temp->right_child) {

            p = temp; // przypisanie węzłowi p wartości węzła tymczasowego
            temp = p->parent; // przypisanie wartości węzłowi tymczasowemu rodzica węzła p

        }

    }
    //wartość zwracana może wynosić null
    return temp;
}

void BST::roted_left(BST_Node * p) {
    auto * v = p -> right_child; // w v umieszczamy prawego syna węzłą który rotujemy

    if(v == nullptr) return; // Jeśli prawy syn nie istnieje kończymy rotację
    auto * x = p -> parent;     // x przyjmuje rodzica węzła który rotujemy

    p -> right_child = v -> left_child;  //prawym synem węzła rotowanego staje się lewy syn węzłą v

    //jeśli prawy syn istnieje jego ojcem staje się teraz węzeł pierwotnie rotowany
    if(p -> right_child != nullptr) p -> right_child -> parent = p;


    v -> left_child = p;    //lewym synem v staje się rotowany węzeł
    v -> parent = x;        //rodzicem v staje sie rodzic węzłą rotowanego
    p -> parent = v;        //rodzicem węzłą rotowanego staje się v

    if(x != nullptr){ //sprawdzamy czy x nie jest null

        //jeśli tak to sprawdzamy czy lewym potomkiem x jest węzeł rotowany
        if(x -> left_child == p) x -> left_child = v;   //jeśli tak to przypisujemy lewemu potomkwi v
        else x -> right_child = v; // jeśli nie to samo przypisanie ale dla prawego potomka

    } else head = v; //jeśli x jest null to korzeniowi przypisujemy wartość węzła v

}

void BST::roted_right(BST_Node * p) {
    auto * v = p -> left_child; //węzeł v przyjmuje lewego potomka węzła rotowanego

    //Jeśli lewy potomek nie isnieje to przerywamy rotowanie
    if(v == nullptr) return;

    auto * x = p -> parent; // x przyjmuje rodzica węzła rotowanego

    p -> left_child = v -> right_child; //lewemu potomkowi węzła rotowanego przypisujemy prawgo potomka węzła v

    //Jeśli węzeł rotowany posiada lewego potomka jego rodzicem staje się pierwornie rotowany węzeł
    if(p -> left_child != nullptr) p -> left_child -> parent = p;

    v -> right_child = p;       //prawy potomek v przymuje węzeł rotowany
    v -> parent = x;            // rodzicem węzła v staje się rodzic węzła rotowanego
    p -> parent = v;            //rodzicem węzłą rotowanego staje sie węzeł v

    //Sprawdzenie czy węzeł x nie jest null
    if(x != nullptr) {
        //jeśli x istnieje
        //sprawdzamy czy lewy potomek x jest równym węzłowi rotowanemu
        if (x->left_child == p) x->left_child = v; //jeśli tak to lewy potomek x dostaje wartośc węzłą v
        else x->right_child = v; // jeśli nie to mamy to samo przypisanie ale dla prawego potomka
    } else head = v;  //jeśli x nie istnieje to korzeń przyjmuje wartość węzła v
}

// Funkcja oblicza szybko 2^log2 ( x )
// Wartością tej funkcji jest liczba x,
// wktórej pozostawiono najstarszy bit 1.
//----------------------------------------
int unsigned BST::log2(unsigned int x) {
    int unsigned y = 1;

    while( ( x >>= 1 ) > 0 ) y <<= 1;

    return y;
}

void BST::dsw_alg() {
    int unsigned n,s;// liczba wysokości drzewa, licznik obrotów

    n = 0;

    auto * p = head;//przypisanie wskażnika głowy do zmiennej pomocniczej p

    //cz 1 alg -> prostowanie drzewa przez obraczanie lewych potomków w lewo
    while (p != nullptr){

        // spradzeni czy węzeł posiada lewego potomka
        if( p -> left_child != nullptr){
            // wykonaie rotacji w lewo
            roted_right(p);
            p = p -> parent; // ustawienie p na rodzica który  jest przerotowanym węzłem

        } else{
            //węzeł nie posiada lewego potomka więc wiekszamy licznik n o 1
            n++;
            p = p -> right_child;//przechodzimy na prawego potomka węzła p

        }

    }
    s = n + 1 - log2(n + 1);
    p = head;

    for(int i = 0; i < s; i++){

        roted_left(p);
        p = p -> parent -> right_child;

    }

    n -= s;

    //cz 2 alg -> obracanie co drugiego węzła w lewo
    while (n > 1){

        n >>= 1;
        p = head;
        for(int  i = 0; i < n; i++){
            roted_left(p);
            p = p -> parent -> right_child;
        }

    }


}

//funkcja pomocnicza działająca na takiej samej zasadzie jak w kopcu binarnym
void BST::display_tree() {
    display("","",head);
}

void BST::clear_tree(BST_Node *n) { //rekurencyjne usuwanie wszystkich węzłów wykorzystywane w desruktorze

    if(n != nullptr){

        clear_tree(n->left_child);
        clear_tree(n->right_child);

        delete n;

    }

}

BST::~BST() {
    clear_tree(head);
}
