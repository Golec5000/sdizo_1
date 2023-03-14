#include "DoubleList.h"

DoubleList::DoubleList() : head(nullptr), tail(nullptr){}

DoubleList::~DoubleList() {

    while (head != nullptr){ // kasowanie wszytkich węzłów po zakończeniu kożystania z listy
        auto * p = head -> next;
        delete head;
        head = p;
    }

}

void DoubleList::add_front(int number) {

    auto * new_node = new Node();//tworzymy nowy węzeł
    new_node -> value = number;//przpisanie wartości

    new_node -> next = head;// następnik w nowym węźle staje się głową

    head = new_node;// przpisujemy wartość i nowy węzeł jest początkiem głowy

    //sprawdzenie czy węzeł ma następnika
    if(new_node -> next != nullptr) new_node -> next -> prev = new_node;// jeśli tak to przypisujemy następnikowi nowy wzeł jako poprzednik do istsniejącego
    else tail = new_node;// jeśli nie ma to staje sie również ogonem

}

void DoubleList::add_back(int number) {

    auto * new_node = new Node();//tworzymy nowy węzeł
    new_node -> value = number;//przpisanie wartości

    new_node -> prev = tail; // poprzenikiem w nowym węźle staje się ogon

    tail = new_node;// przpisujemy wartość i nowy węzeł jest początkiem ogona

    //sprawdzenie czy węzeł ma poprzenika
    if(new_node -> prev != nullptr) new_node -> prev -> next = new_node;// jeśli tak to przypisujemy poprzenikowi nowy wzeł jako natępnik istsniejącego
    else head = new_node;// jeśli nie ma to staje sie również głową


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

int DoubleList::list_size() {
    int counter = 0;
    Node * p = head;

    while (p != nullptr){
        counter ++;
        p = p -> next;
    }

    return counter;
}

int DoubleList::search(int number) {
    //todo: zrobić wszykiwanie dwu kierunkowe
    Node * p = head;
    int counter = 0;
    bool test = false;

    while (p != nullptr){

        if(p -> value == number){
            test = true;
            break;
        } 
        counter ++ ;
        p = p -> next;

    }
    if(test) return counter;
    else return -1;
}

void DoubleList::add_bottom(int index, int number) {

    if(index <= 0) add_front(number);
    else if(index >= list_size() - 1) add_back(number);
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

    }

}

void DoubleList::remove_front() {

    if(list_size() == 0) return;
    if(list_size() == 1) head = tail = nullptr;
    else{
        auto * p = head;
        head = p ->next;
        head -> prev = nullptr;
        delete p;
    }
}

void DoubleList::remove_back() {
    if(list_size() == 0) return;
    if(list_size() == 1 ) tail = head = nullptr;
    else{
        auto * p = tail;
        tail = p -> prev;
        tail -> next = nullptr;
        delete p;
    }

}

void DoubleList::remove_by_index(int index) {


    if(index <= 0) remove_front();
    else if (index >= list_size() - 1) remove_back();
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


