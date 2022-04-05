#include <iostream>
using namespace std;
class Wielomian
{
private:
	int maxStopienWielomianu;
	int* wspolczynniki;
public:
    Wielomian()
    {
        maxStopienWielomianu = 2;
        wspolczynniki = new int[3];
    }
	Wielomian(int maxStopienWielomianu);
	~Wielomian();
    //konstruktor kopjuj¹cy
    Wielomian(Wielomian& wzor)
    {
        maxStopienWielomianu = wzor.maxStopienWielomianu;
        wspolczynniki = new int[maxStopienWielomianu];
        for (int i = 0; i < maxStopienWielomianu; i++)
            wspolczynniki[i] = wzor.wspolczynniki[i];
    }

    void Wczytaj()
    {
        int m;
        cin >> m;
        int licznik = 0;
        do
        {
            cin >> liczba[licznik];
            licznik++;
        } while (licznik < m);
    }
    void Wypisz()
    {
        cout << endl << "wielomian wspolczynniki: ";
        for (int i = 0; i < maxStopienWielomianu; i++)
            cout << wspolczynniki[i] << " ";
    }


};

Wielomian::Wielomian(int maxStopienWielomianu)
    :maxStopienWielomianu(maxStopienWielomianu)
{
    wspolczynniki = new int[maxStopienWielomianu+1];
}

Wielomian::~Wielomian()
{
}

int main()
{
    Wielomian w1(4, 1, 2, 3, 4);
    w2 = w1;
    w1.Wypisz();
    w2.Wypisz();


}