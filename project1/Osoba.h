#ifndef OSOBA_H
#define OSOBA_H
#pragma once
#include <iostream>
using namespace std;
class Osoba
{
private:
	string imie;
	string nazwisko;
	string miejscowosc;
public:
	Osoba();
	Osoba(string _imie, string _nazwisko, string _miejscowosc);
	~Osoba();
	Osoba(const Osoba& other);
	void Wypisz()const;
};

#endif