#include "DoubleList.h"

DoubleList::DoubleList() : head(nullptr), tail(nullptr), size(0){}

DoubleList::~DoubleList() {

    while (head != nullptr){ // kasowanie wszytkich węzłów po zakończeniu kożystania z listy
        auto * p = head -> next;
        delete head;
        head = p;
    }
    size = 0;

}

void DoubleList::add_front(int number) {

    auto * new_node = new Node();//tworzymy nowy węzeł
    new_node -> value = number;//przpisanie wartości

    new_node -> next = head;// następnik w nowym węźle staje się głową

    head = new_node;// przpisujemy wartość i nowy węzeł jest początkiem głowy

    //sprawdzenie czy węzeł ma następnika
    if(new_node -> next != nullptr) new_node -> next -> prev = new_node;// jeśli tak to przypisujemy następnikowi nowy wzeł jako poprzednik do istsniejącego
    else tail = new_node;// jeśli nie ma to staje sie również ogonem

    size++;

}

void DoubleList::add_back(int number) {

    auto * new_node = new Node();//tworzymy nowy węzeł
    new_node -> value = number;//przpisanie wartości

    new_node -> prev = tail; // poprzenikiem w nowym węźle staje się ogon

    tail = new_node;// przpisujemy wartość i nowy węzeł jest początkiem ogona

    //sprawdzenie czy węzeł ma poprzenika
    if(new_node -> prev != nullptr) new_node -> prev -> next = new_node;// jeśli tak to przypisujemy poprzenikowi nowy wzeł jako natępnik istsniejącego
    else head = new_node;// jeśli nie ma to staje sie również głową

    size++;

}

void DoubleList::display() {

    Node * p = head;

    std::cout << "[";
    while (p != nullptr){

        std::cout << std::setw(3) << p -> value << std::setw(3);
        p = p -> next;

    }
    std::cout << "]" << std::endl;

}

Node * DoubleList::search(int number) {
    Node * h = head;
    Node * t = tail;

    while ( h != nullptr && t != nullptr){

        if (h->value == number) return h;
        if(t->value == number) return t;
        if(h == t){
            if(h->value == number) return h;
            else return nullptr;
        }

        h = h->next;
        t = t->prev;

    }

    return nullptr;
}

void DoubleList::add_bottom(int index, int number) {

    if(index <= 0) add_front(number);
    else if(index >= size - 1) add_back(number);
    else{

        auto * new_node = new Node();// nowy węzeł listy
        new_node -> value = number;

        auto * p = head;// 1. węzeł pomocniczy który będzie po nowym elementem
        int counter = 0;

        while (p != nullptr && counter != index){ //szukanie węzłą poprzedzający nowy
            counter++;
            p = p -> next;
        }
        //         e
            // a -> b -> c-> d
        auto * s = p ->prev; // 2. który będzie przed nowywym węźle

        //przepinanie dla nowego węzłą
        new_node -> next = p; // przypisanie nowemu węzła będącego po nim
        new_node -> prev = s; // przypisanie nowemu węzłą porzedzającego
        p -> prev = new_node; // przypisanie węzłowi poprzedzającego nowego węzła
        s -> next = new_node; // przypisanie węzłowi nowego występującego po nim
        size ++;
    }

}

void DoubleList::remove_front() {

    if(size == 0) return;
    if(size == 1) {
        head = tail = nullptr;
        size = 0;
    }
    else{
        auto * p = head;
        head = p ->next;
        head -> prev = nullptr;
        delete p;
        size--;
    }
}

void DoubleList::remove_back() {
    if(size == 0) return;
    if(size == 1 ) {
        tail = head = nullptr;
        size = 0;
    }
    else{
        auto * p = tail;
        tail = p -> prev;
        tail -> next = nullptr;
        delete p;
        size --;
    }

}

void DoubleList::remove_by_index(int index) {


    if(index <= 0) remove_front();
    else if (index >= size - 1) remove_back();
    else{

        auto * p = head;
        int counter = 0;

        while (p != nullptr && counter != index){
            counter++;
            p = p->next;
        }

        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;

        delete p;
        size --;

    }


}

void DoubleList::display_back() {

    auto * p = tail;

    std::cout << "[";
    while (p != nullptr){

        std::cout << std::setw(3) << p -> value << std::setw(3);
        p = p -> prev;

    }
    std::cout << "]" << std::endl;


}

long DoubleList::get_size() {
    return size;
}


