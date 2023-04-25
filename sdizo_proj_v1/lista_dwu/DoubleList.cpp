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
// a - b - c - d - e
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
    //wyświetla liste od przodu
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

    //metoda korzysta z podwujnego piwota dzięki czemu czas wyszukiwani jest
    //skócony który idzie o przodu i tyłu i każdy wędruje przez połowę z każdej strony

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

    if(size == 0) return;       //jeśli nic nie ma usuwanie ma się nie wykonać
    if(size == 1) {             //jeśli jest tylko 1 element to zerujemy rozmiar i głowę i ogon ustawiamy na NULL
        head = tail = nullptr;
        size = 0;
    }
    else{                               //jeśli rozmiar jest większy przesuwamy głowę na jej następnik
        auto * p = head;            //poprzednik ustawiamy na null
        head = p ->next;
        head -> prev = nullptr;
        delete p;                                   //usuwamy węzeł i zmniejszamy rozmiar
        size--;
    }
}

void DoubleList::remove_back() {
    if(size == 0) return;                   //początek taki sam jak w dodawaniu z przodu
    if(size == 1 ) {
        tail = head = nullptr;
        size = 0;
    }
    else{                                       // ten fragment jest odbiciem lustrzanym dla dodawania z przodu
                                                // i operacji dokonojuemy na ogonie
        auto * p = tail;
        tail = p -> prev;
        tail -> next = nullptr;
        delete p;
        size --;
    }

}

void DoubleList::remove_by_index(int index) {


    if(index <= 0) remove_front();      // zabezpiecznie przed podaniem indeksu mniejszego od 0
    else if (index >= size - 1) remove_back();// zabezpiecznie przed podaniem indeksu większego od rozmiaru listy
    else{

        auto * p = head;
        int counter = 0;

        //szukanie węzła do usunięcia
        while (p != nullptr && counter != index){
            counter++;
            p = p->next;
        }

        //odpięcie znalezionego węzłą
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;

        // usunięcie węzłą i zmnieszenie rozmiaru
        delete p;
        size --;

    }


}

void DoubleList::display_back() {

    auto * p = tail;
    //wyświetla liste od tyłu
    std::cout << "[";
    while (p != nullptr){

        std::cout << std::setw(3) << p -> value << std::setw(3);
        p = p -> prev;

    }
    std::cout << "]" << std::endl;


}

//zwraca rozmiar listy
long DoubleList::get_size() {
    return size;
}


