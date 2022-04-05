#include <iostream>
#include <cmath>
class Punkt
{
private:
    double x_;
    double y_;
    static int nPunkt;
public:
    Punkt(double x, double y) : x_(x), y_(y)
    {
        nPunkt++;
    }
    Punkt() : x_(0), y_(0)
    {
        nPunkt++;
    }
    void WczytajPunkt()
    {
        std::cout << "Podaj x: ";
        std::cin >> x_;
        std::cout << "Podaj y: ";
        std::cin >> y_;
        std::cout << std::endl;
    }
    void WypiszPunkt() const
    {
        std::cout << "x: " << x_ << " y: " << y_ << std::endl;
    }
    void Inicjalizuj(double x, double y)
    {
        x_ = x;
        y_ = y;
    }
    static int GetnPunkt()
    {
        return nPunkt;
    }
    double Odleglosc(Punkt p)
    {
        return sqrt(((p.x_ - x_) * (p.x_ - x_)) + ((p.y_ - y_) * (p.y_ - y_)));
    }
    friend void przesun(Punkt& p, double x, double y);
};
int Punkt::nPunkt = 0;

class Wielokat
{
private:
    Punkt* tablicaPunktow;
    int nWierzcholkow;
public:
    Wielokat() : nWierzcholkow(4)
    {
        tablicaPunktow = new Punkt[4];
        for (int i = 0; i < 4; i++)
            tablicaPunktow[i].WczytajPunkt();
    }
    Wielokat(int n) : nWierzcholkow(n)
    {
        tablicaPunktow = new Punkt[n];
        for (int i = 0; i < n; i++)
            tablicaPunktow[i].WczytajPunkt();
    }
    ~Wielokat()
    {
        delete[] tablicaPunktow;
    }
    void WypiszWierzcholki()
    {
        for (int i = 0; i < nWierzcholkow; i++)
            tablicaPunktow[i].WypiszPunkt();
        std::cout << std::endl;
    }
    void ObliczIWypiszObwodWielokata()
    {
        int sum = 0;
        for (int i = 0; i < nWierzcholkow - 1; i++)
        {
            sum += tablicaPunktow[i].Odleglosc(tablicaPunktow[i + 1]);
        }
        sum += tablicaPunktow[nWierzcholkow - 1].Odleglosc(tablicaPunktow[0]);
        std::cout << "Obwod: " << sum << std::endl << std::endl;
    }
    friend void przesun(Wielokat& p, double x, double y);
};

void przesun(Punkt& p, double x, double y)
{
    p.x_ += x;
    p.y_ += y;
}
void przesun(Wielokat& w, double x, double y)
{
    for (int i = 0; i < w.nWierzcholkow; i++)
        przesun(w.tablicaPunktow[i], x, y);
}
int main()
{
    Wielokat w1;
    w1.WypiszWierzcholki();
    w1.ObliczIWypiszObwodWielokata();
    Wielokat w2(6);
    w2.WypiszWierzcholki();
    w2.ObliczIWypiszObwodWielokata();
    przesun(w2, 2, 2);
    w2.WypiszWierzcholki();
    //std::cout << std::endl << Punkt::GetnPunkt();
}