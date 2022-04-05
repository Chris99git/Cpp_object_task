#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
class Data
{
private:
	int dzien;
	int miesiac;
	int godzina_rozpoczecia;
	int godzina_zakonczenia;
public:
	Data()
	{
	}
	Data(int dzien, int miesiac, int godzina_rozpoczecia, int godzina_zakonczenia)
	:dzien(dzien),miesiac(miesiac),godzina_rozpoczecia(godzina_rozpoczecia),godzina_zakonczenia(godzina_zakonczenia)
	{
		Wpisz(dzien, miesiac, godzina_rozpoczecia, godzina_zakonczenia);
	}
	void Wpisz(int _dzien, int _miesiac, int _godzina_rozpoczecia, int _godzina_zakonczenia)
	{
		this->dzien = _dzien;
		this->miesiac = _miesiac;
		this->godzina_rozpoczecia = _godzina_rozpoczecia;
		this->godzina_zakonczenia = _godzina_zakonczenia;
	}
		void prezentuj()
		{
			cout << "Rezerwacja w dniu: " << dzien << " Miesiaca: " << miesiac << ":" << godzina_rozpoczecia << " do " << godzina_zakonczenia << ":" << endl;
		}
};
class Rezerwacja :public Data
{
private:
	string imie, nazwisko;
	int nrStolika;
	Data rezerwacja;
public:
	void wyswietl()
	{
		cout << "Imie: " << imie << endl;
		cout << "Nazwisko: " << nazwisko << endl;
		cout << "Numer Stolika: " << nrStolika << endl;
		rezerwacja.prezentuj();
	}
	Rezerwacja(string imie, string nazwisko, int nrStolika, int dzien,int miesiac, Data rezerwacja)
		:imie(imie), nazwisko(nazwisko), nrStolika(nrStolika),dzien(dzien),miesiac(miesiac), rezerwacja(rezerwacja)
	{
	}
};
int main()
{
	Rezerwacja r1("Ola", "Nowak", 11,15,20, Data(10, 10, 10, 12));
	r1.wyswietl();
}

