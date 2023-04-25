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

    RB_Node * temp = nullptr;   // tworzymy węzeł pomocniczy temp oraz nowy węzeł do wstawienia i
                                //ustawaiam parametry początkowe
    auto * new_node = new RB_Node();

    new_node->key = key;
    new_node->left_child = &guard;
    new_node->right_child = &guard;
    new_node->parent = head;

    if(new_node->parent == &guard) head = new_node;     //jeśli drzewo jest puste to nowy węzeł staje się korzeniem
    else{


        while (true){           //Wyszukiwanie miejsca, gdzie powinien być umieszczony nowy węzeł

            if(key >= new_node->parent->key){       //sprawdzamy czy będziemy iść prawą ścierzką czy lewą

                if(new_node->parent->right_child == &guard){

                    new_node->parent->right_child = new_node;       // Jeśli udało się znaleść miesce to dodajemny i przerywamy pętle
                    break;

                } else new_node->parent = new_node->parent->right_child;

            }
            else{

                if(new_node->parent->left_child == &guard){             //przypadek lustrzany

                    new_node->parent->left_child = new_node;
                    break;

                } else new_node->parent = new_node->parent->left_child;

            }

        }

        new_node->color = 'R';  //Nowy węzeł będzie na początek zawsze kolor czerwony

        //algorytm naprawiania drzewa
        //Naprawia do momętu gdy ojciec dodanego węzła jest czerwony
        while (new_node != head && new_node->parent->color == 'R'){

            if(new_node->parent != new_node->parent->parent->left_child){   //jeśli węzeł nie jest lewym potomkiem swojego ojca

                //węzeł temp (wujek) jest lewym potomkiem dziadka
                temp = new_node->parent->parent->left_child;

                if(temp->color == 'R'){     //przypadek 1: wujek jest ustawiony na czerwono

                    new_node->parent->color = 'B';      //kolorujemy wujka i ojca na czarno
                    temp->color = 'B';
                    new_node->parent->parent->color = 'R';  //dziadka kolorujemy na czerwono
                    new_node = new_node->parent->parent;     //ustawiamy się na dziadku
                    continue;
                } else {                    //przypadek 2: Wujek wstawionego węzła jest czarny a węzeł wstawiany jest lewym dzieckiem
                    if (new_node ==new_node->parent->left_child) {

                        new_node = new_node->parent; //ustawiamy się na ojcu
                        roted_right(new_node); // Wykonujemy na nim rorację w prawo

                    }
                                                            //przypadek 3 wujek wstawionego węzłą jest czarny a węzeł wstawiany jest prawym dzieckiem
                    new_node->parent->color = 'B';           //zamieniamy kolory dziadka i ojca na przeciwne
                    new_node->parent->parent->color = 'R';
                    roted_left(new_node->parent->parent);       //wykonujemy rotację w lewo względem dziadka
                    break;
                }
            }
            else{                   //Przypadki lustrzane

                //węzeł temp (wujek) jest prawym potomkiem dziadka
                temp = new_node->parent->parent->right_child;

                if(temp->color == 'R'){                 //przypadek 1: wujek jest ustawiony na czerwono

                    new_node->parent->color = 'B';       //kolorujemy wujka i ojca na czarno
                    temp->color = 'B';
                    new_node->parent->parent->color = 'R';//dziadka kolorujemy na czerwono
                    new_node = new_node->parent->parent; //ustawiamy się na dziadku
                    continue;

                } else {                //przypadek 2: Wujek wstawionego węzła jest czarny a węzeł wstawiany jest prawym dzieckiem
                    if (new_node == new_node->parent->right_child) {

                        new_node = new_node->parent;        //Ustawaimy się na ojcu
                        roted_left(new_node);             //Dokonujemy rotacji w lewo względem niego

                    }

                    new_node->parent->color = 'B';                  //przypadek 3 wujek wstawionego węzłą jest czarny a węzeł wstawiany jest lewym dzieckiem
                    new_node->parent->parent->color = 'R';          //zamieniamy kolory dziadka i ojca na przeciwne
                    roted_right(new_node->parent->parent);          //wykonujemy rotację w prawo względem dziadka
                    break;
                }
            }


        }

        head->color = 'B';                        //Kolorujemy korzeń na czarno

    }
}

void RBT::remove_element(int key) {

    auto * del = find_value(key);           //wyszukujemy elementu po kluczu który chcemy usunąć

    if (del == &guard) return;                          //jeśli dany węzeł nie istnie to przerywamy usuwanie

    RB_Node * p = nullptr;                             //węzeł pomocniczy który będzie ostatecznie usuwany

    if(del->left_child == & guard || del->right_child == &guard) p = del;      //przypadek 1: Jeśli węzeł ma jednego potomka, Jeśli tak to p dostaje węzeł wyszukany
    else p = find_succ_node(del);                                              // w innym przypadku węzeł p dostaje wartość wskażnika nastepnika usuwanego węzłą

    RB_Node * o = nullptr;                                      //węzeł pomocniczy o będzie lewym lub prawym synem w zależności od spełnienia warunku
    if(p->left_child != &guard) o = p->left_child;
    else o = p->right_child;

    o->parent = p->parent;                                       //rodzicem o będzie rodzic węzła p

    if(p->parent == &guard) head = o;                            //sprawdzamy czy usuwany węzeł jest korzeniem, jeśli tak to korzeniem staje jego syn
    else if(p == p->parent->left_child) p->parent->left_child = o;      // węzeł p w strukturze zostaje zastąpiony przez o
    else p->parent->right_child = o;

    if(p != del ) del->key = p->key;                    //węzeł del nie jest usuwany to przenosimy wartość klucza p do del

    RB_Node * k = nullptr;      // węzeł pomocniczy przy odbudowanie struktury drzewa

    //alg naprawy struktury drzewa , jeśli węzeł usuwany jest czerwony to go nie wykonujemy i kończymy
    if(p->color == 'B'){

        while (o != head && o->color == 'B'){

            if(o == o->parent->left_child){ //sprawdzmy czy węzeł o jest lewym potomkiem swojego rodzica

                k = o->parent->right_child; //jeśli tak to węzeł k staje się prawym bratem węzła o

                if(k->color == 'R'){        //przypadek 1: brat węzła o jest czerwony

                    k->color = 'B';         //zamieniamy kolor brata na czarny
                    o->parent->color = 'R';    //zamieniamy kolor rodzica na czerwony
                    roted_left(o->parent);  //rotujemy w lewo względem rodzica o i k
                    k = o->parent->right_child; // przywracamy k jako prawego brata o

                }

                if(k->left_child->color == 'B' && k->right_child->color == 'B'){    //Przypadek 2: brat węzłą o jest czarny i posiada 2 czarnych synów

                    k->color = 'R'; //w takim przypadku zamieniamy kolor węzła na czerwony
                    o = o->parent; //węzeł o staje się własnym rodzicem
                    continue;   //kontynuujemy działanie alg

                }

                if(k->right_child->color == 'B'){       //przpadek 3: brat węzłą o jest czarny i posiada czerwonego lewego syna i czarnego prawego syna

                    k->left_child->color = 'B';         //lewy syn k staje się czarny
                    k->color = 'R';                     //węzeł k zmienia swój kolor na czerwony
                    roted_right(k);                     //rotujemy w prawo wzgldem węzłą k
                    k = o->parent->right_child;             //k staje się prawym bratem węzła o

                }

                                                    //przypadek 4: brat węzła jest czarny i ma prawego czerwonego syna
                k->color = o->parent->color;         //węzeł k przyjmuje kolor swojego rodzica
                o->parent->color = 'B';               //rodzic przymuje kolor czarny
                k->right_child->color = 'B';            //prawy potomek węzłą k staje się czarny
                roted_left(o->parent);              //rotujemy w lewo względem rodzica
                o = head;                               //węzeł o staje się korzeniem co pozwala nam zakończyć algorytm

            } else{     //tu posiadamy warunki lustrazane do powyższych

                k = o->parent->left_child; //węzeł staje się bratem węzła o

                if(k->color == 'R'){ //przypadek 1: brat o jest czerwony

                    k->color = 'B';             //zmieniamy mu kolor na czarny
                    o->parent->color = 'R';     //rodzic węzłów staje się czerwony
                    roted_right(o->parent);     //rotujemy w prawo względem rodzica
                    k = o->parent->left_child;      //przywracamy k jako lewego brata o

                }

                if(k->left_child->color == 'B' && k->right_child->color == 'B'){    //przypadek 2: jest identyczny (z poprzednim)

                    k->color = 'R';
                    o = o->parent;
                    continue;

                }

                if(k->left_child->color == 'B'){    //przpadek 3: brat węzłą o jest czarny i posiada czarnego lewego syna i czerwonego prawego syna

                    k->right_child->color = 'B';    //prawy syn zostaje przemalowany na czarny
                    k->color = 'R';                 //kolor węzłą k zmieniamy na czerwony
                    roted_left(k);                 //rotujemy w lewo w zględem węzła k
                    k = o->parent->left_child;          //węzeł k staje się lewym bratem węzła o

                }
                                    //przypadek 4: brat węzła jest czarny i ma lewego czerwonego syna
                k->color = o->parent->color;        //węzeł k przyjmuje kolor swojego rodzica
                o->parent->color = 'B';              //rodzic przymuje kolor czarny
                k->left_child->color = 'B';             //lewy potomek węzłą k staje się czarny
                roted_right(o->parent);              //rotujemy w prawo względem rodzic
                o = head;                               //węzeł o staje się korzeniem co pozwala nam zakończyć algorytm

            }

        }

        o->color = 'B';         //węzeł o staje się czarny
        delete p;               //usuwamy węzeł p
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

RB_Node *RBT::find_value(int key) {//funkcja jest lustrzana do implementacji w BST
    //z różnicą że zamiast przyrównywać do null  to przyrównujemy do &guard
    //kiedy nie ma takie węzła to zwracamy referencje do guarda

    auto * p = head;

    while (p != &guard && p -> key != key){

        if(p -> key > key) p = p -> left_child;
        else p = p -> right_child;

    }

    if(p == &guard ) return &guard;
    return p;
}

void RBT::roted_left(RB_Node *p) { //funkcja jest lustrzana do implementacji w BST
    //z różnicą że zamiast przyrównywać do null  to przyrównujemy do &guard
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

void RBT::roted_right(RB_Node *p) {//funkcja jest lustrzana do implementacji w BST
    //z różnicą że zamiast przyrównywać do null  to przyrównujemy do &guard
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

RB_Node *RBT::succ_min_node(RB_Node *p) {//funkcja jest lustrzana do implementacji w BST
    //z różnicą że zamiast przyrównywać do null  to przyrównujemy do &guard
    if(p != &guard) while (p -> left_child != &guard) p = p-> left_child;

    return p;
}

RB_Node *RBT::find_succ_node(RB_Node *p) {//funkcja jest lustrzana do implementacji w BST
    //z różnicą że zamiast przyrównywać do null  to przyrównujemy do &guard
    //kiedy nie ma takie węzła to zwracamy referencje do guarda
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

void RBT::clear_tree(RB_Node *n) { // usuwanie rekurencyjne dla całego drzewa wykorzystywane w destruktorze
    if(n != &guard){

        clear_tree(n->left_child);
        clear_tree(n->right_child);
        delete n;

    }
}
