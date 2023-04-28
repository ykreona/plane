#ifndef SAMOLOT_H
#define SAMOLOT_H

#include <string>
#include "pasazerowie.h"

using namespace std;

class Samolot{

public:
    Samolot(string = "", int fuel = 0);
    string nazwaSamolotu();
    void liczbaSamolotow();
    ~Samolot();

    Pasazerowie& pasazer(int);
    void dodajPasazera(const Pasazerowie&);

    friend ostream& operator<<(ostream& coutj, Samolot& s);
    Pasazerowie operator[](int);
    Samolot& operator=(const Samolot &);
    Samolot& operator++();
    bool operator==(const Samolot &);
    operator float() const;

    int poziomPaliwa();
    int max_paliwa = 5;
private:
    string m_nazwa_samolotu;
    Pasazerowie* ptr_pasazerowie = nullptr;
    int liczba_pasazerow = 0;
    int m_paliwo = 0;
    static int liczba_samolotow;
};

#endif // SAMOLOT_H