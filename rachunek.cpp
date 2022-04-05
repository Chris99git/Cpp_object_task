#include <iostream>
using namespace std;
class RachunekOszczednosciowy
{
private:
    double stankonta;
    static int oprocentowanieroczne;
public:
    RachunekOszczednosciowy(double stankonta)
        : stankonta(stankonta)
    {
    }
    void ZmienOprocentowanie(int oprocentowanieroczne)const
    {
        this->oprocentowanieroczne = oprocentowanieroczne;
    }
    double aktualizujStanKonta()
    {
        double kwota = stankonta* oprocentowanieroczne / 100.0 / 12.0;
        stankonta = stankonta + kwota;
        return stankonta;
    }
    void Wypisz() const
    {
        cout << "Stan konta: " << stankonta << endl;
        cout << "Oprocentowanie: " << oprocentowanieroczne<< "%" << endl;
    }
};
int RachunekOszczednosciowy::oprocentowanieroczne=0;
int main()
{
    RachunekOszczednosciowy r1(2000);
    RachunekOszczednosciowy r2(3000);

    r1.ZmienOprocentowanie(3);
    r1.aktualizujStanKonta();
    r1.Wypisz();
    r2.aktualizujStanKonta();
    r2.Wypisz();

    r2.ZmienOprocentowanie(4);
    r1.aktualizujStanKonta();
    r1.Wypisz();
    r2.aktualizujStanKonta();
    r2.Wypisz();
}
