#include <iostream>
#include <string>

#include "samolot.h"

using namespace std;

int Samolot::liczba_samolotow = 0;

//operator wypisywania na strumień
ostream& operator<<(ostream& coutj, Samolot& s){
    if(s.ptr_pasazerowie == nullptr){ return coutj; }
    else {
        coutj << "W samolocie o nazwie \"" << s.m_nazwa_samolotu << "\" leca takie pasazerowie:" << endl;

        for (int i = 0; i < s.liczba_pasazerow; i++){
            cout << s[i].imie() << ", " << s[i].wiek() << " lat" << endl;
        }

        coutj << "Poziom paliwa: " << s.operator float() << "%" << endl;
        return coutj;
    }
}

int main()
{
    Samolot litak("Mriya", 2);
    litak.liczbaSamolotow();

    //  ----- modyfikacja -----
    cout << "Boarding starts!" << endl;
    for(int idx = 0; idx < 4; idx++)
    {
        cout << "Type in name and age of the passangers: " << endl;
        int wiek;
        string imie;
        cin >> imie >> wiek;

        litak.dodajPasazera(Pasazerowie(imie, wiek));

        cout << "Czy wprowadzic kolejnego pasazera? (tak / nie)" << endl;
        string c;
        cin >> c;

        if (c == "nie")
            break;
    }
    // ----- koniec modyfikacji -----

/*    litak.dodajPasazera(Pasazerowie("Mariia", 18));
    litak.dodajPasazera(Pasazerowie("Sarah", 32));
    litak.dodajPasazera(Pasazerowie("Ryan", 12));
    litak.dodajPasazera(Pasazerowie("Kim", 54));*/

    cout << "Informacja o samolocie \"" << litak.nazwaSamolotu() << "\":" << endl;
    cout << litak;

    Samolot plane;
    plane.liczbaSamolotow();

    //przypisanie/kopiowanie
    plane = litak;

    for (int i = plane.poziomPaliwa(); i < plane.max_paliwa; ++i) {
        ++plane; // zwiekszenie paliwa operatorem jednoargumentowym
    }

    //operator dwuargumentowy
    if (litak == plane){
        cout << "Samoloty sa rowne!" << endl;
    }
    else {
        cout << "Samoloty nie sa rowne!" << endl;
    }

    cout << "Informacja o kopii samolotu \"" << litak.nazwaSamolotu() << "\":" << endl;
    cout << plane;

    return 0;
}