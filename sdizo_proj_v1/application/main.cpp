#include <iostream>
#include "../tablica_dym/TabDym.h"
#include "../lista_dwu/DoubleList.h"
#include "../kopiec_bin/KopiecBin.h"
#include "../bst_tree/BST.h"

void menu();
void tab_menu();
void list_menu();
void kopiec_menu();
void bst_menu();

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
    std::cout << "0. Koniec programu" << std::endl;
}

void tab_menu(){
    auto * array = new TabDym();

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

    auto * heap = new KopiecBin();
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

    bst ->add_element(5);
    bst ->add_element(51);
    bst ->add_element(17);
    bst ->add_element(1);
    bst ->add_element(1);
    bst ->add_element(4);

    bst ->display("","",bst -> get_head());


    delete bst;

}
