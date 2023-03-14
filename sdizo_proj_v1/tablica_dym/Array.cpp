#include "Array.h"

Array::Array() : size_tab(0), tab(nullptr){}

void Array::add_head(int number) {

    if(tab == nullptr) add_if_zero(number);
    else{
        int * temp_tab = nullptr;
        long temp_size = size_tab + 1;
        temp_tab = new int [temp_size];

        if(temp_tab != nullptr){

            temp_tab[0] = number;
            for(int i = 0; i < temp_size; i++) temp_tab[i + 1] = tab[i];

            delete [] tab;
            tab = temp_tab;
            size_tab = temp_size;

        }
    }

}

void Array::add_tail(int number) {

    if(tab == nullptr) add_if_zero(number);
    else{

        int * temp_tab = nullptr;
        long temp_size = size_tab + 1;
        temp_tab = new int [temp_size];

        if(temp_tab != nullptr) {

            for (int i = 0; i < size_tab; ++i) {
                temp_tab[i] = tab[i];
            }
            temp_tab[size_tab] = number;

            delete[] tab;
            tab = temp_tab;
            size_tab = temp_size;
        }
    }

}

void Array::add_bottom(int index, int number) {
    if(tab == nullptr) add_if_zero(number); //sprawczenie tablica jest pusta, jeśli tak to meetoda dodaje wartość nie parząc na indeks
    else{

        if(index <= 0) add_head(number);//jeżli użtkownik poda indeks zero lub mniejszy to nowy element jest dodawany na pocztek jako głowa
        else if(index >= size_tab - 1) add_tail(number);//jeżli użtkownik poda indeks ostani lub większ to nowy element jest koniec na pocztek jako ogon
        else{

            //utworznie tablicy pomocniczej do realokacji pamięci i pojemnności dla głównej tablicy
            int * temp_tab = nullptr;
            long temp_size = size_tab + 1;
            temp_tab = new int [temp_size];

            if(temp_tab != nullptr) {

                //dodanie nowego elementu do tablicy będące na innej pozycji niż koniec i początek
                for (int i = 0; i < index; i++) temp_tab[i] = tab[i];//przepisanie lewej strony strony satrej tablicy do momętu zmiany
                temp_tab[index] = number; // dopisanie nowego elemetu we skazanym mniejscu
                for (int i = index; i < temp_size; i++) temp_tab[i + 1] = tab[i]; // przepisanie prawej strony starej toblicy do nowej po wprowadzeniu zmiany

                delete[] tab;
                tab = temp_tab;// przpisanie nowej tablicy
                size_tab = temp_size; // aktualizacja rozmiaru
            }
        }

    }
}

int Array::search(int number) {
    int num_index = -1; // wartość pomocnicza, zwrócenie wartości -1 oznacza że nie ma takiej liczby w tablicy
    for(int i = 0; i < size_tab; ++i)
        if(tab[i] == number){
            num_index = i;
            break;
        }
    return num_index;
}

void Array::remove(int number) {

    if(size_tab < 2) remove_if_one_or_zero();
    else{

        int index = search(number);

        if (index != -1){

            int * temp_tab = nullptr;
            long temp_size = size_tab - 1;
            temp_tab = new int [temp_size];

            if (temp_tab != nullptr){

                for(int i = 0; i < index; i ++ ) temp_tab[i] = tab[i];
                for(int i = index; i < temp_size; i++) temp_tab[i] = tab[i + 1];

                delete[] tab;
                tab = temp_tab;
                size_tab = temp_size;

            }

        }

    }

}

void Array::remove_head() {

    if(size_tab < 2) remove_if_one_or_zero();
    else{

        int * temp_tab = nullptr;
        long temp_size = size_tab - 1;
        temp_tab = new int [temp_size];

        if(temp_tab != nullptr){

            for(int i = 1; i < size_tab; i++) temp_tab[i - 1] = tab[i];

            delete[] tab;
            tab = temp_tab;
            size_tab = temp_size;

        }

    }

}

void Array::remove_tail() {

    if(size_tab < 2) remove_if_one_or_zero();
    else{

        int * temp_tab = nullptr;
        long temp_size = size_tab - 1;
        temp_tab = new int [temp_size];

        if(temp_tab != nullptr){

            for(int i = 0; i < temp_size; i++) temp_tab[i] = tab[i];

            delete[] tab;
            tab = temp_tab;
            size_tab = temp_size;

        }

    }

}

int Array::get_size() const {
    return size_tab;
}

void Array::add_if_zero(int number) {

    size_tab++;
    tab = new int[size_tab];
    tab[size_tab-1] = number;

}

Array::~Array() {

    delete [] tab;
    size_tab = 0;

}

void Array::display() {

    std::cout << "[ ";
    for (int i = 0; i < size_tab; i++) std::cout << std::setw(3) << tab[i] << std::setw(3);
    std::cout << " ]" << std::endl;

}

void Array::remove_if_one_or_zero() {
    if(get_size() == 0) std::cout << "nieda sie nic usunac bo tablica jest pusta !!" << std::endl;
    else{
        delete [] tab;
        size_tab = 0;
    }
}


int *Array::get_tab() {
    return tab;
}

void Array::swap(int num1, int num2, int index1, int index2) {

    tab[index1] = num2;
    tab[index2] = num1;

}

