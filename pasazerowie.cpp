#include "pasazerowie.h"

Pasazerowie::Pasazerowie(string imie, int wiek){
    m_imie = imie;
    m_wiek = wiek;
}

bool Pasazerowie::operator==(const Pasazerowie &p) {
    return m_imie == p.m_imie && m_wiek == p.m_wiek;
}

string Pasazerowie::imie() { return m_imie; }

int Pasazerowie::wiek() { return m_wiek; }
