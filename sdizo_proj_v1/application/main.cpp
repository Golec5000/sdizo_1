#include <iostream>
#include "../tablica_dym/Array.h"
#include "../lista_dwu/DoubleList.h"
#include "../kopiec_bin/Heap.h"
#include "../bst_tree/BST.h"
#include "../black_and_red_tree/RBT.h"
#include "../tests/Test_array.h"
#include "../tests/Test_list.h"
#include "../tests/Test_heap.h"
#include "../tests/Test_bst.h"
#include "../tests/Test_rbt.h"


//------------------------------------------------------------
void menu();
void tab_menu();
void list_menu();
void kopiec_menu();
void bst_menu();
void black_and_red_menu();

//-------------------------------------------------------------
void tests();
void array_test();
void list_test();
void heap_test();
void bst_test();
void rb_test();

//--------------------------------------------------------------

int main() {

    int num;

    do{
        menu();
        std::cin >> num;
        system("cls");
        switch (num) {

            case 1:
                //implementacja tablicy
                tab_menu();
                system("cls");
                break;

            case 2:
                //implementacji listy
                list_menu();
                system("cls");
                break;

            case 3:
                //implementacja kopca
                kopiec_menu();
                system("cls");
                break;
            case 4:
                //implementacja drzewa bst
                bst_menu();
                system("cls");
                break;
            case 5:
                //implementacja drzewa czerwono-czarnego
                black_and_red_menu();
                system("cls");
                break;
            case 10:
                //implementacja testów
                tests();

                break;
            case 0:
                exit(0);

            default:
                std::cout << "Brak takiej opcji" << std::endl;
                system("pause");
                system("cls");
                break;
        }
    } while (num);

    return 0;
}

void menu(){
    std::cout << "Wybierz structure" << std::endl;
    std::cout << "1. Tablica dynamiczna" << std::endl;
    std::cout << "2. Lista dwukierukowa" << std::endl;
    std::cout << "3. Kopiec binarny" << std::endl;
    std::cout << "4. Drzewo przeszukiwan binarnych (BST)" << std::endl;
    std::cout << "5. Drzewo czerwone-czarne" << std::endl;
    std::cout << "0. Koniec programu" << std::endl;
}

void tab_menu(){
    auto * array = new Array();

    int num_arr;

    do {
        std::cout << "Struktura tablicy: " << std::endl;
        array -> display();
        std::cout << "\n--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz operacje na tablicy dynamicznej" << std::endl;
        std::cout << "1. Dodaj z tyly" << std::endl;
        std::cout << "2. Dodaj z porzodu" << std::endl;
        std::cout << "3. Dodaj w srodku" << std::endl;
        std::cout << "4. Usun z tyly" << std::endl;
        std::cout << "5. Usun z przodu" << std::endl;
        std::cout << "6. Usun wybranego indeksu" << std::endl;
        std::cout << "7. Szukaj pozycji danej liczby" << std::endl;
        std::cout << "8. Rozmiar tablicy" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        int number, index;

        std::cout << "Podaj numer operacji: ";
        std::cin >> num_arr;
        system("cls");

        switch (num_arr) {
            case 1:
                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;
                array -> add_tail(number);
                system("cls");

                break;

            case 2:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;
                array ->add_head(number);
                system("cls");

                break;
            case 3:
                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                std::cout << "Podaj indeks do wpisania ( liczac od 0): ";
                std::cin >> index;

                array ->add_bottom(index,number);
                system("cls");

                break;
            case 4:

                array -> remove_tail();
                system("cls");

                break;

            case 5:

                array -> remove_head();
                system("cls");

                break;
            case 6:
                std::cout << "Podaj index do usuniecia: ";
                std::cin >> number;

                array ->remove(number);
                system("cls");

                break;
            case 7:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                index = array ->search(number);

                if(index == -1) std::cout << "W tablicy nie ma takiej liczby !"<< std::endl;
                else std::cout << "Pozycja liczby " << number << " wynosi: " << index << std::endl;
                system("pause");
                system("cls");
                break;

            case 8:

                std::cout << "Rozmiar tablicy wynosi: " << array -> get_size() << std::endl;
                system("pause");
                system("cls");
                break;
            case 0:
                break;
            default:
                std::cout << "Brak takiej opcji ! "<< std::endl;
                system("pause");
                system("cls");
                break;
        }


    } while (num_arr != 0);

    delete array;

}

void list_menu(){

    auto * list = new DoubleList();

    int num_list;

    do{

        std::cout<<"Lista wyswietlana od przodu"<<std::endl;
        list -> display();

        std::cout<<"Lista wyswietlana od tylu"<<std::endl;
        list->display_back();

        std::cout << "\n--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz operacje na liście dwukierunkowej" << std::endl;
        std::cout << "1. Dodaj z tyly" << std::endl;
        std::cout << "2. Dodaj z porzodu" << std::endl;
        std::cout << "3. Dodaj pod dany indeks" << std::endl;
        std::cout << "4. Usun z przodu" << std::endl;
        std::cout << "5. Usun z tylu" << std::endl;
        std::cout << "6. Usun z podanego indeksu" << std::endl;
        std::cout << "7. Szukaj pozycji danej liczby" << std::endl;
        std::cout << "8. Rozmiar tablicy" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        int number, index;

        std::cout << "Podaj numer operacji: ";
        std::cin >> num_list;
        system("cls");

        switch (num_list) {
            case 1:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                list ->add_back(number);
                system("cls");

                break;

            case 2:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                list ->add_front(number);
                system("cls");
                break;

            case 3:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                std::cout << "Podaj indeks do wpisania: ";
                std::cin >> index;

                list ->add_bottom(index,number);
                system("cls");

                break;

            case 4:

                list -> remove_front();
                system("cls");

                break;

            case 5:

                list -> remove_back();
                system("cls");

                break;

            case 6:

                std::cout << "Podaj indeks do usuniecia: ";
                std::cin >> index;

                list ->remove_by_index(index);
                system("cls");

                break;
            case 7:

                std::cout << "Podaj liczbe do wyszukania: ";
                std::cin >> number;

                Node *node;
                node = list->search(number);
                system("cls");
                if(node != nullptr ) std::cout << " Wartosc znaleziona " << std::endl;
                else std::cout << "Nie ma takiej liczby" << std::endl;

                system("pause");
                system("cls");
                break;

            case 8:
                std::cout << "Lista ma rozmiar: " << list ->get_size() << std::endl;
                system("pause");
                system("cls");
                break;

            case 0:
                break;

            default:
                std::cout << "Brak takiej opcji !" << std::endl;
                system("pause");
                system("cls");
                break;
        }

    } while (num_list != 0);

    delete list;

}

void kopiec_menu(){

    auto * heap = new Heap();

    int num_heap;

    do{

        std::cout << "Struktura kopca:" << std::endl;
        heap->heap_dispaly();

        std::cout << "\n--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz operacje na kopcu binarnym" << std::endl;
        std::cout << "1. Dodaj element" << std::endl;
        std::cout << "2. Usun element" << std::endl;
        std::cout << "3. Szukaj pozycji danej liczby" << std::endl;
        std::cout << "4. Rozmiar kopca" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        std::cin >> num_heap;

        system("cls");

        switch (num_heap) {

            int number;

            case 1:
                std::cout << "Podaj liczbe do wpisania: ";
                std::cin>>number;

                heap->add_element(number);

                system("cls");

                break;
            case 2:

                heap->remove();

                system("cls");

                break;
            case 3:

                std::cout << "Podaj liczbę do wyszukania: ";
                std::cin>>number;

                int index;
                index = heap->search(number);

                if (index > -1) std::cout << "Element znaleziony pod indeksem: " << index << std::endl;
                else std::cout << "Brak podanego elementu: " << std::endl;

                system("pause");
                system("cls");

                break;
            case 4:

                std::cout << "Rozmiar kopca wynosi: " << heap->size_heap() << std::endl;

                system("pause");
                system("cls");

                break;
            case 0:
                break;
            default:

                std::cout << "Brak takiej opcji !" << std::endl;
                system("pause");
                system("cls");

                break;
        }

    } while (num_heap != 0);


    delete heap;

}

void bst_menu(){

    auto * bst = new BST();

    int num_bst;

    do{

        std::cout << "Struktura bst:" << std::endl;
        bst->display_tree();

        std::cout << "\n--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz operacje na BST" << std::endl;
        std::cout << "1. Dodaj element" << std::endl;
        std::cout << "2. Usun element" << std::endl;
        std::cout << "3. Szukaj danego klucza" << std::endl;
        std::cout << "4. DSW" << std::endl;
        std::cout << "5. Rotuj w prawo" << std::endl;
        std::cout << "6. Rotuj w lewo" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        std::cin>> num_bst;

        switch (num_bst) {

            int number;

            case 1:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin>>number;

                bst->add_element(number);

                system("cls");

                break;
            case 2:

                std::cout << "Podaj liczbe do usuniecia: ";
                std::cin>>number;

                bst->remove_element(number);

                system("cls");

                break;
            case 3:

                std::cout << "Podaj liczbe do znalezienia: ";
                std::cin>>number;

                BST_Node * node;
                node = bst->find_value(number);

                if (node != nullptr) std::cout << "Wartość szukana znaleziona "<< std::endl;
                else std::cout << "Brak danego elementu "<< std::endl;

                system("pause");
                system("cls");

                break;

            case 4:

                bst->dsw_alg();
                system("cls");
                break;
            case 5:

                std::cout << "Podaj liczbe do obrotu w prawo: ";
                std::cin>>number;

                BST_Node * node_rot_right;
                node_rot_right = bst->find_value(number);

                if(node_rot_right != nullptr) bst->roted_right(node_rot_right);

                system("cls");

                break;
            case 6:

                std::cout << "Podaj liczbe do obrotu w lewo: ";
                std::cin>>number;

                BST_Node * node_rot_left;
                node_rot_left = bst->find_value(number);

                if(node_rot_left != nullptr) bst->roted_right(node_rot_left);

                system("cls");

                break;

        }

    } while (num_bst != 0);


    delete bst;

}

void black_and_red_menu(){

    auto * rbt = new RBT();

    int num_rbt;

    do{

        std::cout << "Struktura drzewa czerwono-czarnego:" << std::endl;
        rbt->display_tree();

        std::cout << "\n--------------------------------------------------------------" << std::endl;

        std::cout << "Wybierz operacje na drzewie czerwono-czarnym" << std::endl;
        std::cout << "1. Dodaj element" << std::endl;
        std::cout << "2. Usun element" << std::endl;
        std::cout << "3. Szukaj danego klucza" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        std::cin>> num_rbt;

        switch (num_rbt) {

            int number;

            case 1:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin>>number;

                rbt->add_element(number);

                system("cls");

                break;
            case 2:

                std::cout << "Podaj liczbe do usuniecia: ";
                std::cin>>number;

                rbt->remove_element(number);

                system("cls");

                break;
            case 3:

                std::cout << "Podaj liczbe do znalezienia: ";
                std::cin>>number;

                RB_Node * node;
                node = rbt->find_value(number);

                if (node != nullptr) std::cout << "Wartość szukana znaleziona "<< std::endl;
                else std::cout << "Brak danego elementu "<< std::endl;

                system("pause");
                system("cls");

                break;
            default:
                system("cls");
                break;

        }

    } while (num_rbt != 0);

    delete rbt;
}

//--------------------------------------------------------------

void tests(){
    //array_test();
    //list_test();
    //heap_test();
    //bst_test();
    rb_test();
}

void array_test(){
    auto * testArray = new Test_array();

    std::cout<<"Podaj ilość elementów:";
    int c;
    std::cin >> c;

//    int tmp_remove[20];
//    int tmp_add[20];
//
//    std::cout<<" Test : "<<std::endl;
//    for(int i = 1; i <= 20 ; i++) {
//        std::cout<<i<<"/20";
//
//        tmp_add[i-1] = testArray->add_test(c);
//        tmp_remove[i-1] = testArray->clear_test(c);
//
//        std::cout<<std::endl;
//    }
//
//    float sum_add = 0, sum_rev = 0;
//
//    for(int i = 0; i < 20; i++){
//
//        sum_add += tmp_add[i];
//        sum_rev += tmp_remove[i];
//
//    }
//
//    std::cout<< "Dodawanie "<< sum_add/20 << " " << "Usuwanie "<< sum_rev/20<<std::endl;

    int tmp_search[20];
    std::cout<<" Test : "<<std::endl;
    for(int i = 1; i <= 20 ; i++) {
        std::cout<<i<<"/20";

        tmp_search[i-1] = testArray->search_test(c);

        std::cout<<std::endl;
    }

    float sum_search = 0;

    for(int i = 0; i < 20; i++) sum_search += tmp_search[i];

    std::cout << "Szaukanie : " << sum_search/20 << " [us]" << std::endl;

    delete testArray;
}

void list_test(){

    auto * testList = new Test_list();
    std::cout<<"Podaj ilosc elementów:";
    int c;
    std::cin >> c;


    int tmp_remove[20];
    int tmp_add[20];

    std::cout<<" Test : "<<std::endl;
    for(int i = 1; i <= 20 ; i++) {
        std::cout<<i<<". ";
        tmp_add[i-1] = testList->add_elements(c);
        tmp_remove[i-1] = testList->clear(c);
        std::cout<<std::endl;
    }

    float sum_add = 0, sum_rev = 0;

    for(int i = 0; i < 20; i++){

        sum_add += tmp_add[i];
        sum_rev += tmp_remove[i];

    }

    std::cout<< "Dodawanie "<< sum_add/20 << " " << "Usuwanie "<< sum_rev/20 << " ";

//    int tmp_search[20];
//    std::cout<<" Test : "<<std::endl;
//    for(int i = 1; i <= 20 ; i++) {
//        std::cout<<i<<"/20";
//
//        tmp_search[i-1] = testList->search_element(c);
//
//        std::cout<<std::endl;
//    }
//
//    float sum_search = 0;
//
//    for(int i = 0; i < 20; i++) sum_search += tmp_search[i];
//
//    std::cout << "Szaukanie : " << sum_search/20 << " [us]" << std::endl;


    delete testList;

}

void heap_test(){

    auto * testHeap = new Test_heap();

    std::cout<<"Podaj ilość elementów:";
    int c;
    std::cin >> c;

//    int tmp_remove[20];
//    int tmp_add[20];
//
//    std::cout<<" Test : "<<std::endl;
//    for(int i = 1; i <= 20 ; i++) {
//        std::cout<<i<<"/20";
//        tmp_add[i-1] = testHeap->add_test(c);
//        tmp_remove[i-1] =testHeap->clear_test(c);
//        std::cout<<std::endl;
//    }
//
//    float sum_add = 0, sum_rev = 0;
//
//    for(int i = 0; i < 20; i++){
//
//        sum_add += tmp_add[i];
//        sum_rev += tmp_remove[i];
//
//    }
//
//    std::cout<< "Dodawanie "<< sum_add/20 << "[ms] " << "Usuwanie "<< sum_rev/20 << " [ms]";

    int tmp_search[20];
    std::cout<<" Test : "<<std::endl;
    for(int i = 1; i <= 20 ; i++) {
        std::cout<<i<<"/20";

        tmp_search[i-1] = testHeap->search_test(c);

        std::cout<<std::endl;
    }

    float sum_search = 0;

    for(int i = 0; i < 20; i++) sum_search += tmp_search[i];

    std::cout << "Szaukanie : " << sum_search/20 << " [us]" << std::endl;

    delete testHeap;
}

void bst_test(){

    auto * testBst = new Test_bst();

    std::cout<<"Podaj ilość elementów:";
    int c;
    std::cin >> c;

//    int tmp_remove[20];
//    int tmp_add[20];
//
//    std::cout<<" Test : "<<std::endl;
//    for(int i = 1; i <= 20 ; i++) {
//        std::cout<<i<<"/20";
//        tmp_add[i-1] = testBst->add_test(65000);
//        tmp_remove[i-1] =testBst->clear_test(65000);
//        std::cout<<std::endl;
//    }
//    float sum_add = 0, sum_rev = 0;
//
//    for(int i = 0; i < 20; i++){
//
//        sum_add += tmp_add[i];
//        sum_rev += tmp_remove[i];
//
//    }
//
//    std::cout<< "Dodawanie "<< sum_add/20 << "[ms] " << "Usuwanie "<< sum_rev/20 << " [ms]";

//
//    int tmp_dsw[20];
//    std::cout<<" Test : "<<std::endl;
//    for(int i = 1; i <= 20 ; i++) {
//        std::cout<<i<<"/20";
//
//        tmp_dsw[i-1] = testBst->dsw_test(55000);
//
//        std::cout<<std::endl;
//    }
//
//    float sum_dsw = 0;
//
//    for(int i = 0; i < 20; i++) sum_dsw += tmp_dsw[i];
//
//    std::cout << "Alg DSW : " << sum_dsw/20 << " [ms]" << std::endl;

    int tmp_search[20];
    std::cout<<" Test : "<<std::endl;
    for(int i = 1; i <= 20 ; i++) {
        std::cout<<i<<"/20";

        tmp_search[i-1] = testBst->search_test(c);

        std::cout<<std::endl;
    }

    float sum_dsw = 0;

    for(int i = 0; i < 20; i++) sum_dsw += tmp_search[i];

    std::cout << "Szukanie : " << sum_dsw/20 << " [us]" << std::endl;

    delete testBst;
}

void rb_test(){


    auto * testrbt = new Test_rbt();

    std::cout<<"Podaj ilość elementów:";
    int c;
    std::cin >> c;

    int tmp_remove[20];
    int tmp_add[20];

    std::cout<<" Test : "<<std::endl;
    for(int i = 1; i <= 20 ; i++) {
        std::cout<<i<<"/20";
        tmp_add[i-1] = testrbt->add_test(c);
        tmp_remove[i-1] =testrbt->clear_test(c);
        std::cout<<std::endl;
    }
    float sum_add = 0, sum_rev = 0;

    for(int i = 0; i < 20; i++){

        sum_add += tmp_add[i];
        sum_rev += tmp_remove[i];

    }

    std::cout<< "Dodawanie "<< sum_add/20 << "[ms] " << "Usuwanie "<< sum_rev/20 << " [ms]";

//    int tmp_search[20];
//    std::cout<<" Test : "<<std::endl;
//    for(int i = 1; i <= 20 ; i++) {
//        std::cout<<i<<"/20";
//
//        tmp_search[i-1] = testrbt->search_test(70000);
//
//        std::cout<<std::endl;
//    }
//
//    float sum_search = 0;
//
//    for(int i = 0; i < 20; i++) sum_search += tmp_search[i];
//
//    std::cout << "Szaukanie : " << sum_search/20 << " [us]" << std::endl;

    delete testrbt;


}