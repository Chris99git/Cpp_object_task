#include <iostream>
#include <iomanip>
using namespace std;
class KoloryRGB
{
private:
    int r;
    int g;
    int b;
public:
    KoloryRGB()
    {
        this->r = 255;
        this->g = 255;
        this->b = 255;
    }
    KoloryRGB(int r, int g, int b)
        :r(r), g(g), b(b)
    {}
    void Wypisz()const
    {
        cout << endl << dec << r << "." << g << "." << b << endl;
    }
    void WypiszHEX()const
    {
        cout << "#";
        cout << hex << setw(2) << setfill('0') << uppercase << r;
        cout << hex << setw(2) << setfill('0') << uppercase << g;
        cout << hex << setw(2) << setfill('0') << uppercase << b;
        cout << endl;
    }
};
int main()
{
    const KoloryRGB zielony(0, 128, 0);
    zielony.Wypisz();
    zielony.WypiszHEX();

    const KoloryRGB niebieski(0, 0, 255);
    niebieski.Wypisz();
    niebieski.WypiszHEX();

    const KoloryRGB g(77, 93, 83);
    g.Wypisz();
    g.WypiszHEX();
}
