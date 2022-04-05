#include <iostream>
using namespace std;
class Kino
{
private:
	string nazwa;
	int sala;
public:
	Kino()
	{
		cout << endl << "To jest konstruktor domniemany";
	}
	Kino(string _nazwa, int _sala)
		:nazwa(_nazwa), sala(_sala)
	{
	}
	Kino(Kino& wzor)
	{
		nazwa = wzor.nazwa;
		sala = wzor.sala;
		cout << endl << "To jest konstruktor kopiuj¹cy";

	}
	void Wyswietl() const
	{
		cout << endl << nazwa << " " << sala;
	}
	void kina()
	{
		cout << "dostepne kina: ";
		cout << "imax";
		cout << "cinemacity";
	}
	~Kino()
	{
		cout << "To jest destruktor";
	}

};
class Film:public Kino
{

private:
	string gatunek;
	string tytul;

public:
	Film(string _nazwa, int _sala, string _gatunek, string _tytul)
		:Kino(_nazwa, _sala), gatunek(_gatunek), tytul(_tytul)
	{
		cout << endl << "To jest konstruktor";
	}
	~Film();
	void Wyswietl() const
	{
		Kino::Wyswietl();
		cout << endl << gatunek << " " << tytul;
	}
	void Wczytaj();
};
void Film::Wczytaj()
{
	cout << endl << "gatunek ";
	cin >> gatunek;
	cout << endl << "podaj tytul: ";
	cin >> tytul;
}

Film::~Film()
{
	cout << "To jest destruktor";
}

int main() {
	//To jest obiekt lokalny statyczny
	Kino r1("imax", 1);
	r1.Wyswietl();
	//To jest obiekt lokalny dynamiczny
	Kino* r2 = new Kino("cinema city", 2);
	r2->Wyswietl();
	delete r2;
	//Obiekt lokalny automatyczny
	Kino r3;
	Kino r4(r1);
	r4.Wyswietl();

}
