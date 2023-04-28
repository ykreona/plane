#ifndef PASAZEROWIE_H
#define PASAZEROWIE_H

#include <string>
#include <iostream>

using namespace std;

class Pasazerowie{
public:
    Pasazerowie(string setName = "", int setAge = 0);

    bool operator==(const Pasazerowie &p);

    string imie();
    int wiek();
private:
    string m_imie;
    int m_wiek;
};

#endif // !PASAZEROWIE_H