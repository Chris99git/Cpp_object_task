#include <iostream>
using namespace std;
//to jest klasa która bedzie s³uzyla do przechowywania liczb z duza iloscia liczb po przecinku
class MojaLiczba
{
private:
	int liczba; //w tej zmiennej bêdziemy przechowywaæ liczbê przed przecinkiem
	int* tabCyfr; //w tej tablicy beda przechowywane wszystkie cyfry po przecinku
	int l; //to jest liczba cyfr po przecinku
public:
	MojaLiczba(int _l,int _liczba)
		:l(_l),liczba(_liczba)
	{
		tabCyfr = new int[l];
		for (int i = 0; i < l; i++)
			tabCyfr[i] = i + 1;
	}
	MojaLiczba()
	{}
	//prze³adujemy teraz operator dodawania tak zeby nauczyc dodawac liczbe int do MolejLiczby
	MojaLiczba& operator+(int x)
	{
		liczba = +x; //do liczby przed przecinkiem dodajemy x
		return *this;
	}
	//przeladujemy teraz operator << tak zeby nauczyc kompilator wyswietlac moj¹ liczbe
	friend ostream& operator<< (ostream& wyjscie, const MojaLiczba& m);
};
//operator dostaje dwa parametry, pierwszy parametr odp gdze mamy wyswietlacz i podniego w mainie jest podstawiony cout
//drugi parametr odpowiad ana pyt co mamy wyswietlac i pod niego podstawiony jest w main obiekt l1
ostream& operator<< (ostream& wyjscie, const MojaLiczba& m)
{
	wyjscie << m.liczba;
	wyjscie << ",";
	for (int i = 0; i < m.l; i++)
		wejscie << m.tabCyfr[i];
	return wyjscie;
}
int main()
{
	cout << endl;
	MojaLiczba l1(5, 1);
	cout << l1;
	cout << endl;
	MojaLiczba l2(6, 2);
	cout << l2;

	MojaLiczba l3;
	l3 = l1 + 2;
	cout << endl;

}
