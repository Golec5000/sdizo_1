#include "Heap.h"

/*metoda oraz parametry z nią związane potrzebne do wyświetlania zastała wzięta ze strony
 *https://eduinf.waw.pl/inf/alg/001_search/0113.php
 */
void Heap::display(std::string sp, std::string sn, int v) {

    std::string s;
    if( v < tab -> get_size() )
    {
        s = sp;
        if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
        display( s + cp, cr, 2 * v + 2 );

        s = s.substr ( 0, sp.length( ) - 2 );

        std::cout << s << sn << tab -> get_tab()[ v ] << std::endl;

        s = sp;
        if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
        display( s + cp, cl, 2 * v + 1 );
    }

}


void Heap::add_element(int number) {

    tab ->add_tail(number);
    int counter = tab -> get_size() - 1;

    while(counter > 0 && tab ->get_tab()[counter] > tab ->get_tab()[parent(counter)]){ //warunek kopca

        //zamieniamy miejscami syna i rodzica miejscami
        tab ->swap(tab ->get_tab()[counter],tab ->get_tab()[parent(counter)],counter, parent(counter));
        //obliczamy nową pozycję ojca
        counter = parent(counter);
    }

}

void Heap::remove() {
    //ten warunek sprawdza czy można usunąć wartość z kopca
    if(tab->get_size() > 0){
        //zamiana pierwszego i ostatniego elementu
        tab->swap(tab->get_tab()[0], tab->get_tab()[tab->get_size() - 1], 0,tab->get_size() - 1);
        tab->remove_tail(); // usunięcie ostatniego elementu
    }

    //warunek sprawdza czy kopiec nie jest pusty po usunięciu i czy można przejść do naprawy kopca
    //sytuacja krytyczna jest w tedy kiedy w kopcu jest tylko jeden element i po jego usunięciu
    // naprawa kopca nie powinna się wykonywać

    if(tab ->get_size() > 0) {

        int v = tab -> get_tab()[0];     //zapisanie nowego tymczasowego max kopca do zmiennej pomocniczej
        int i = 0;                       //iterator przechodzący po rodzicach
        int j = 1;                       //iterator przechodzący po potomkach zaczynając od lewego

        while (j < tab -> get_size()){

            if(j + 1 < tab -> get_size() && tab -> get_tab()[j + 1] > tab -> get_tab()[j]) j++; //sprawdzenie warunku kopca dla lewego
            // dziecka, jeśli jest prawdziwy będziemy następnie przechodzić po prawej stronie

            if(v >= tab -> get_tab()[j]) break;  //jeśli dojdziemy do wartości wcześniej zapamiętanej prztywamy pętle
            //jeśli nie dojdzie do przerwania zammieniamy miejscami rodzica z odpowiadającym mu dzieckiem

            tab ->swap(tab -> get_tab()[i],tab -> get_tab()[j],i,j);

            i = j;    //nowa wartość rodzica
            j = 2 * j + 1;  //nowa wartość indeksu dziecka zależna od głowy po lewej stronie od niego
        }

        tab->get_tab()[i] = v;  //przypisanie na ostatni indeks zapamiętaj wartości

    }

}

Heap::Heap() : tab (new Array()) {

    //wartości do rysowania kopca (ustawienie ich wartości)
    cr = cl = cp ="  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

}


int Heap::parent(int index) {
    return (index - 1) / 2; // wyliczanie rodzica dla danego węzła / liścia
}

Heap::~Heap() {
    delete tab;
}

int Heap::search(int num) {
    //metoda wykorzystuje już isteniejącą metode pszeszukiwania tablicy
    //zwraca ona indeks danego elementu, jeśli jest brak danego elementu zwracane jest wartość -1
    return tab->search(num);

}

// metoda pomocnicza która pozwala wyświetlić kopiec bez wywoływania metody z parametrami
void Heap::heap_dispaly() {
    display("","",0);
}

int Heap::size_heap() {
    return tab->get_size();
}


