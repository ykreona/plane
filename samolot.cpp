#include <iostream>
#include <string>

#include "samolot.h"

using namespace std;

Samolot::Samolot(string setName, int fuel) {
    m_nazwa_samolotu = setName;
    m_paliwo = fuel;

    ++liczba_samolotow;
}

string Samolot::nazwaSamolotu() {
    return m_nazwa_samolotu;
}

//statyczna metoda
void Samolot::liczbaSamolotow(){
    ++liczba_samolotow;
}

Samolot::~Samolot() {
    delete [] ptr_pasazerowie;
}

Pasazerowie& Samolot::pasazer(int i) {
    return ptr_pasazerowie[i];
}

void Samolot::dodajPasazera(const Pasazerowie &p){
    Pasazerowie *temp = new Pasazerowie[liczba_pasazerow+1];

    for (int i = 0; i < liczba_pasazerow; ++i) {
        temp[i] = ptr_pasazerowie[i];
    }

    temp[liczba_pasazerow] = p;
    delete[] ptr_pasazerowie;
    ptr_pasazerowie = temp;
    ++liczba_pasazerow;
}

//operator indeksowy
Pasazerowie Samolot::operator[](int i) {
    if (i >= liczba_pasazerow && i > 0){ cout << "miejsce jest puste" << endl;}
    return pasazer(i);
}

//operator kopiujacy
Samolot& Samolot::operator=(const Samolot &p) {
    m_nazwa_samolotu = p.m_nazwa_samolotu;
    m_paliwo = p.m_paliwo;
    liczba_pasazerow = p.liczba_pasazerow;

    if(p.ptr_pasazerowie == nullptr) { cout << "pasazerow nie ma" << endl; }

    else {
        if(ptr_pasazerowie != nullptr) {
            delete[] ptr_pasazerowie;
        }

        ptr_pasazerowie = new Pasazerowie[liczba_pasazerow];
        for(int i = 0; i < p.liczba_pasazerow; ++i)
            ptr_pasazerowie[i] = p.ptr_pasazerowie[i];
    }
    return *this;
}

Samolot& Samolot::operator++() {
    m_paliwo++;
    return *this;
}

bool Samolot::operator==(const Samolot & s) {
    if (this == & s) { return true; }

    if (m_nazwa_samolotu != s.m_nazwa_samolotu) { return false; }

    if (liczba_pasazerow != s.liczba_pasazerow) { return false; }

    if (m_paliwo != s.m_paliwo) { return false; }

    for (int i = 0; i < liczba_pasazerow; ++i){
        if (!(ptr_pasazerowie[i] == s.ptr_pasazerowie[i])) { return false; }
    }
}

//operator konwersji
Samolot::operator float() const {
    return (m_paliwo * 1.0f / max_paliwa) * 100;
}

int Samolot::poziomPaliwa() {
    return m_paliwo;
}