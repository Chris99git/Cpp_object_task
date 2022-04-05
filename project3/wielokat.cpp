#include <iostream>
#include <cmath>
using namespace std;
class Punkt
{
private:
    static int pkt;
    double x;
    double y;
public:
    Punkt()
    {
        wczytajPunkt(0, 0);
        pkt++;
    }
    Punkt(double x, double y)
    {
        wczytajPunkt(x, y);
        pkt++;
    }
    ~Punkt()
    {
        pkt--;
    }
    static int ilePunktow()
    {
        return pkt;
    }
    void wczytajPunkt(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    void Inicjalizuj(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void wypiszPunkt() const
    {
        cout << "(" << x << "," << y << ")";
    }
    double odleglosc(Punkt& p)
    {
        return sqrt(((x - p.x) * (x - p.x)) + ((y - p.y) * (y - p.y)));
    }
    friend void przesun(Punkt& p, double x, double y);
};

class Wielokat
{
private:
    Punkt* wierzcholki;
    int nWierzcholki;
public:
    Wielokat();
    Wielokat(int nWierzcholki);
    ~Wielokat();
    void wypiszWierzcholki() const;
    void obwWielokat();
    friend void przesun(Wielokat& w, double x, double y);
};

Wielokat::Wielokat()
{
    nWierzcholki = 4;
    wierzcholki = new Punkt[nWierzcholki];
    wierzcholki[0].wczytajPunkt(0, 0);
    wierzcholki[1].wczytajPunkt(0, 1);
    wierzcholki[2].wczytajPunkt(1, 0);
    wierzcholki[3].wczytajPunkt(1, 1);
}

Wielokat::Wielokat(int nWierzcholki)
{
    this->nWierzcholki = nWierzcholki;
    this->wierzcholki = new Punkt[nWierzcholki];
    int x, y;
    for (int i = 0; i < nWierzcholki; i++)
    {
        cout << i + 1 << ".  ";
        cin >> x >> y;
        wierzcholki[i].wczytajPunkt(x, y);
    }
}

Wielokat::~Wielokat()
{
    delete[] wierzcholki;
}

void Wielokat::wypiszWierzcholki() const
{
    cout << nWierzcholki << "-kat:" << endl;
    for (int i = 0; i < nWierzcholki; i++)
    {
        cout << i + 1 << ". ";
        wierzcholki[i].wypiszPunkt();
        cout << endl;
    }
}

void Wielokat::obwWielokat()
{
    int sum = 0;
    for (int i = 0; i < nWierzcholki - 1; i++)
    {
        sum += wierzcholki[i].odleglosc(wierzcholki[i + 1]);
    }
    sum += wierzcholki[nWierzcholki - 1].odleglosc(wierzcholki[0]);
    std::cout << "Obwod: " << sum << std::endl << std::endl;
}

void przesun(Punkt& p, double _x, double _y)
{
    p.x += _x;
    p.y += _y;
}

void przesun(Wielokat& w, double x, double y)
{
    for (int i = 0; i < w.nWierzcholki; i++)
        przesun(w.wierzcholki[i], x, y);
}

int Punkt::pkt = 0;
int main()
{
    Punkt p1(5, 10);

    Wielokat w1;
    w1.wypiszWierzcholki();
    w1.obwWielokat();
    Wielokat w2(6);
    cout << endl;
    przesun(w2, 2, 3);
    cout << endl;
    w2.wypiszWierzcholki();
}
