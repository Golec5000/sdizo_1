#include "KopiecBin.h"

/*metoda oraz parametry z nią związane potrzebne do wyświetlania zastała wzięta ze strony
 *https://eduinf.waw.pl/inf/alg/001_search/0113.php
 */
void KopiecBin::display(std::string sp, std::string sn, int v) {

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


void KopiecBin::add_element(int number) {

    tab ->add_tail(number);
    int counter = tab -> get_size() - 1;

    while(counter > 0 && tab ->get_tab()[counter] > tab ->get_tab()[parent(counter)]){
        tab ->swap(tab ->get_tab()[counter],tab ->get_tab()[parent(counter)],counter, parent(counter));
        counter = parent(counter);
    }

}

void KopiecBin::remove() {

    if(tab ->get_size() > 0) {
        tab->swap(tab->get_tab()[0], tab->get_tab()[tab->get_size() - 1], 0,tab->get_size() - 1);//zamiana ostatniego elementu z największym
        tab->remove_tail();// usunięcie największego z kopca
    }
    if(tab -> get_size() > 0){//sprawdzenie czy kopiec ma elemty
        int v = tab -> get_tab()[0];//zapisanie nowego tymczaswoego maxa kopca do zmiennej pomocniczej
        int i = 0;//iterator przechodzący po rodzicach
        int j = 1;//iterator przechodzący po lewym dziecku

        while (j < tab -> get_size()){ // warunek pętli nie pozwalający wyjść po za zakres kopca

            if(j + 1 < tab -> get_size() && tab -> get_tab()[j + 1] > tab -> get_tab()[i]) j++;//sprawdzenie warunku kopca dla lewgo dziecka, jeśli jest prawdziwy będzemy nastęnie przechodzić po prawej strobnie
            if(v >= tab -> get_tab()[j]) break;//jeśli dijdzemy do wartości wcześniej zapamiętajnej prztywamy pętle
            //jeśli nie dojdzie do przerwania zammieniamy miejscami rodzica z odpowiadającym mu dzieckiem
            tab ->swap(tab -> get_tab()[i],tab -> get_tab()[j],i,j);
            i = j;//nowa wartość rodzica
            j = 2 * j + 1;//nowa wartość indeksu dziecka zależna od głowy po lewej stronie od niego
        }

        tab ->get_tab()[i] = v;//przypisanie na ostatni indeks zapamiętaj wartości

    }

}

KopiecBin::KopiecBin() : tab (new TabDym()) {

    cr = cl = cp ="  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

}

int KopiecBin::parent(int index) {
    return (index - 1) / 2;
}

KopiecBin::~KopiecBin() {
    delete tab;
}


