#include <iostream>
#include <conio.h>
#include "../tablica_dym/Array.h"
#include "../lista_dwu/DoubleList.h"
#include "../kopiec_bin/Heap.h"
#include "../bst_tree/BST.h"
#include "../black_and_red_tree/RBT.h"

void menu();
void tab_menu();
void list_menu();
void kopiec_menu();
void bst_menu();
void black_and_red_menu();

int main() {

    int num;

    do{
        menu();
        std::cin >> num;

        switch (num) {

            case 1:
                //implementacja tablicy
                tab_menu();
                break;

            case 2:
                //implementacji listy
                list_menu();
                break;

            case 3:
                //implementacja kopca
                kopiec_menu();
                break;
            case 4:
                //implementacja drzewa bst
                bst_menu();
                break;
            case 5:
                //implementacja drzewa czerwono-czarnego
                black_and_red_menu();
                break;
            case 0:
                exit(0);

            default:
                std::cout << "Brak takiej opcji" << std::endl;
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
    std::cout << "4. BST" << std::endl;
    std::cout << "0. Koniec programu" << std::endl;
}

void tab_menu(){
    auto * array = new Array();

    int num_arr;
    array -> display();

    do {
        std::cout << "Wybierz operacje na tablicy dynamicznej" << std::endl;
        std::cout << "1. Dodaj z tyly" << std::endl;
        std::cout << "2. Dodaj z porzodu" << std::endl;
        std::cout << "3. Dodaj w srodku" << std::endl;
        std::cout << "4. Usun z tyly" << std::endl;
        std::cout << "5. Usun z przodu" << std::endl;
        std::cout << "6. Usun wybrana liczbe" << std::endl;
        std::cout << "7. Szukaj pozycji danej liczby" << std::endl;
        std::cout << "8. Rozmiar tablicy" << std::endl;
        std::cout << "0. Cofnij do menu glownego" << std::endl;

        int number, index;

        std::cout << "Podaj numer operacji: ";
        std::cin >> num_arr;

        switch (num_arr) {
            case 1:
                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                array -> add_tail(number);
                array -> display();

                break;

            case 2:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                array ->add_head(number);
                array -> display();

                break;
            case 3:
                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                std::cout << "Podaj indeks do wpisania ( liczac od 0): ";
                std::cin >> index;

                array ->add_bottom(index,number);
                array -> display();

                break;
            case 4:

                array -> remove_tail();
                array -> display();

                break;

            case 5:

                array -> remove_head();
                array -> display();

                break;
            case 6:
                std::cout << "Podaj liczbe do usuniecia: ";
                std::cin >> number;

                array ->remove(number);
                array -> display();

                break;
            case 7:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                index = array ->search(number);

                if(index == -1) std::cout << "W tablicy nie ma takiej liczby !"<< std::endl;
                else std::cout << "Pozycja liczby " << number << " wynosi: " << index << std::endl;

                break;

            case 8:

                std::cout << "Rozmiar tablicy wynosi: " << array -> get_size() << std::endl;

                break;
            case 0:
                break;
            default:
                std::cout << "Brak takiej opcji ! "<< std::endl;
                break;
        }


    } while (num_arr != 0);

}

void list_menu(){

    auto * list = new DoubleList();

    int num_list;
    list -> display();

    do{

        std::cout << "Wybierz operacje na tablicy dynamicznej" << std::endl;
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

        switch (num_list) {
            case 1:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                list ->add_back(number);
                list -> display();
                list -> display_back();

                break;

            case 2:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                list ->add_front(number);
                list -> display();
                list -> display_back();

                break;

            case 3:

                std::cout << "Podaj liczbe do wpisania: ";
                std::cin >> number;

                std::cout << "Podaj indeks do wpisania: ";
                std::cin >> index;

                list ->add_bottom(index,number);
                list -> display();
                list -> display_back();

                break;

            case 4:

                list -> remove_front();
                list ->display_back();

                break;

            case 5:

                list -> remove_back();
                list ->display();

                break;

            case 6:

                std::cout << "Podaj indeks do usuniecia: ";
                std::cin >> index;

                list ->remove_by_index(index);
                list -> display();

                break;
            case 7:

                std::cout << "Podaj liczbe do wyszukania: ";
                std::cin >> number;

                index = list ->search(number);

                if(index >=0 ) std::cout << "Liczba " << number << " ma indeks: " << index << std::endl;
                else std::cout << "Nie ma takiej liczby" << std::endl;

                break;

            case 8:
                std::cout << "Lista ma rozmiar: " << list ->list_size() << std::endl;
                break;

            case 0:
                break;

            default:
                std::cout << "Brak takiej opcji !" << std::endl;
                break;
        }

    } while (num_list != 0);

    delete list;

}

void kopiec_menu(){

    auto * heap = new Heap();
    heap ->add_element(5);
    heap ->add_element(6);
    heap ->add_element(4);
    heap ->add_element(6);
    heap ->add_element(6);
    heap ->add_element(7);
    heap ->add_element(8);
    heap ->add_element(2);
    heap ->add_element(1);
    heap ->add_element(4);
    heap ->add_element(3);
    heap ->add_element(6);
    heap ->add_element(2);
    heap ->add_element(4);
    heap ->add_element(14);
    heap ->display("","",0);

    heap ->remove();
    heap ->display("","",0);


    delete heap;

}

void bst_menu(){

    auto * bst = new BST();

    bst ->add_element(10);
    bst ->add_element(4);
    bst ->add_element(8);
    bst ->add_element(7);
    bst ->add_element(3);
    bst ->add_element(2);
    bst ->add_element(5);
    bst ->add_element(11);
    bst ->add_element(1);
    bst ->add_element(17);
    bst ->add_element(22);
    bst ->add_element(6);
    bst ->add_element(5);
    bst ->add_element(4);
    bst ->add_element(4);
    bst ->display("","",bst -> get_head());

    //bst ->remove_element(3);
    //bst ->display("","",bst -> get_head());

//    bst ->roted_right(bst ->find_value(5));
//    bst ->roted_right(bst ->find_value(7));
//    bst ->roted_right(bst ->find_value(2));
//    bst ->roted_right(bst ->find_value(5));
//    bst ->roted_right(bst ->find_value(3));

//    bst ->roted_left(bst ->find_value(7));
//    bst ->roted_left(bst ->find_value(5));
//
//    bst ->display("","",bst -> get_head());

    bst -> dsw_alg();

    bst ->display("","",bst -> get_head());

    system("pause");
    system("cls");


    delete bst;

}

void black_and_red_menu(){

    auto * rbt = new RBT();

    rbt->add_element(5);
    rbt->add_element(6);
    rbt->add_element(10);
    rbt->add_element(1);
    rbt->add_element(1);
    rbt->add_element(3);
    rbt->add_element(15);
    rbt->add_element(25);
    rbt->add_element(8);
    rbt->add_element(9);

    delete rbt;
}