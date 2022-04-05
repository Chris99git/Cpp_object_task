#include <iostream>
using namespace std;
class Mieszkanie
{
private:
    string adres;
    double powierzchnia;
    double cena;
    static int liczbaMieszkan;
public:
    Mieszkanie(double powierzchnia, double cena, int liczbaMieszkan);
    ~Mieszkanie()
    {

    }

    static int wyswietlLiczbeMieszkan()
    {
        return liczbaMieszkan;
    }
    void drukuj()
    {
        cout<<endl<<adres<<endl<<powierzchnia<<endl<<cena<<endl<<liczbaMieszkan<<endl;
    }

};
int Mieszkanie::liczbaMieszkan=0;
Mieszkanie::Mieszkanie(double powierzchnia, double cena,int liczbaMieszkan)
{
    return liczbamieszkan++;
}
Mieszkanie::~Mieszkanie()
{
    cout<<endl<<elo;
    return liczbaMieszkan--;
}

int main()
{
    Mieszkanie m1("kowala",25,200000);
    m1.drukuj();
}
