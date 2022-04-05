#include <iostream>
using namespace std;
class Samochod
{
protected:
    double spalanie;
    double amortyzacja;
public:
    Samochod(double _spalanie, double _amortyzacja)
        :spalanie(_spalanie),amortyzacja(_amortyzacja)
    {
    }
    //te metody s¹ virtual ze w klasie transport funkcja wykonaj trase dostaje jako parametr
    //referencje na samochod. Gdyby te metody nie by³y virtual funkcja wykonajtrase wywolalaby funkcje obliczspalanie
    //i oblicz amortyzacje zawsze z samochodu czyli dla samochodciezarowego i osobowego
    //Zwrocilaby 0. Je¿eli te metody dodamy jako
    virtual double ObliczSpalanie(double liczbaKilometrow)
    {
        return 0;
    }
    virtual double ObliczAmortyzacje(double liczbaKilometrow)
    {
        return 0;
    }
};
class SamochodOsobowy: public Samochod
{
public:
    SamochodOsobowy(double _spalanie, double _amortyzacja)
        :Samochod(_spalanie,_amortyzacja)
    {
    }
    double ObliczSpalanie(double liczbaKilometrow)
    {
        return (liczbaKilometrow*spalanie)/100;
    }
    double ObliczAmortyzacje(double liczbaKilometrow)
    {
        return (liczbaKilometrow*amortyzacja)/100;
    }
};
class SamochodCiezarowy : public Samochod
{
private:
private:
    double ladownoscNaczepy;
    double ladownoscPrzyczepy;
public:
    SamochodCiezarowy(double _spalanie, double _amortyzacja, double _ladownoscNaczepy, double _ladownoscPrzyczepy)
        :Samochod(_spalanie, _amortyzacja), ladownoscNaczepy(_ladownoscNaczepy),ladownoscPrzyczepy(_ladownoscPrzyczepy)
    {

    }
    double ObliczSpalanie(double liczbaKilometrow)
    {
        return (liczbaKilometrow + ladownoscNaczepy + ladownoscPrzyczepy)*spalanie/100;
    }
    double ObliczAmortyzacje(double liczbaKilometrow)
    {
        return (liczbaKilometrow + ladownoscNaczepy + ladownoscPrzyczepy)*amortyzacja/100;
    }

};
class Transport
{
private:
    double kosztyPaliwa;
    double kosztyAmortyzacji;
public:
    Transport()
        :kosztyPaliwa(0),kosztyAmortyzacji(0)
    {
    }
    void WykonajTrase(Samochod& samochod, double liczbaKilometrow)
    {
        kosztyPaliwa += samochod.ObliczSpalanie(liczbaKilometrow);
        kosztyAmortyzacji += samochod.ObliczAmortyzacje(liczbaKilometrow);
    }
    void Wyswietl() const
    {
        cout<<endl<<"koszty paliwa: "<<kosztyPaliwa;
        cout<<endl<<"koszty amortyzacji: "<<kosztyAmortyzacji;
    }
};
int main()
{
    Transport transport;

    SamochodOsobowy so(8,20);
    transport.WykonajTrase(so,100);

    SamochodCiezarowy sc(20,50,100,200);
    transport.WykonajTrase(sc,200);
    transport.Wyswietl();
}
