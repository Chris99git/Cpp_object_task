#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;

class Losowanie
{
private:
    int numerLosowania;
    string dataLosowania;
    int* wyniki;
public:
    Losowanie(int _numerLosowania,string _dataLosowania,int w1,int w2,int w3, int w4, int w5,int w6);
    ~Losowanie();
    Losowanie(const Losowanie& wzor);
    void Wypisz()const;
    void ZmienWynkiLosowania(int w1,int w2,int w3, int w4, int w5,int w6);
};
Losowanie::Losowanie(int _numerLosowania,string _dataLosowania,int w1,int w2,int w3, int w4, int w5,int w6)
:numerLosowania(_numerLosowania),dataLosowania(_dataLosowania)
{
    wyniki=new int[6];
    wyniki[0]=w1;
    wyniki[1]=w2;
    wyniki[2]=w3;
    wyniki[3]=w4;
    wyniki[4]=w5;
    wyniki[5]=w6;
}
Losowanie::Losowanie(const Losowanie& wzor)
{
    numerLosowania=wzor.numerLosowania;
    dataLosowania=wzor.dataLosowania;
    wyniki=new int[6];
    for(int i=0;i<6;i++)
        wyniki[i]=wzor.wyniki[i];
}

Losowanie::~Losowanie()
{
    cout<<endl<<"Usuwam losowanie: "<<numerLosowania<<endl;
}
void Losowanie::Wypisz() const
{
    cout<<endl<<"numer losowania: "<<numerLosowania;
    cout<<endl<<"data: "<<dataLosowania;
    cout<<endl<<"wyniki: ";
    for(int i=0;i<6;i++)
    cout<<wyniki[i]<<" ";
}
void Losowanie::ZmienWynkiLosowania(int w1,int w2,int w3, int w4, int w5,int w6)
{
    wyniki[0]=w1;
    wyniki[1]=w2;
    wyniki[2]=w3;
    wyniki[3]=w4;
    wyniki[4]=w5;
    wyniki[5]=w6;
}
int main()
{
    Losowanie l1(1,"lipiec 2000",3,7,3,13,5,8);
    l1.Wypisz();
    Losowanie l2(l1);
    l2.Wypisz();
    
    l1.ZmienWynkiLosowania(1,2,3,4,5,6);
    l1.Wypisz();
    l2.Wypisz();

    12=l1;
    l1.Wypisz();
    l2.Wypisz();

    l1.ZmienWynkiLosowania(10,20,30,40,50,60);
    l1.Wypisz();
    l2.Wypisz();
}
