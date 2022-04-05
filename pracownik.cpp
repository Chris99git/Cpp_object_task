#include <iostream>
using namespace std;
class Pracownik
{
private:
    string imie;
    string nazwisko;
    string miejscowosc;
    double placa;
public:
    void wczytaj ()
    {
        cout<<"podaj imie: ";
        getline(cin,imie);
        cout<<"Podaj nazwisko: ";
        getline(cin,nazwisko);
        cout<<"Podaj miejscowosc: ";
        cin>>miejscowosc;
        cout<<"podaj place: ";
        cin>>placa;
        cout<<endl;
    }
    void wypisz()
    {
        cout<<"Imie: "<<imie<<endl;
        cout<<"nazwisko: "<<nazwisko<<endl;
        cout<<"miejscowosc: "<<miejscowosc<<endl;
        cout<<"placa: "<<placa<<endl;
        cout<<endl;
    }
    string getImie()
    {
        return imie;
    }
    void setImie(string imie)
    {
        this->imie=imie;
    }
    string getNazwisko()
    {
        return nazwisko;
    }
    void setNazwisko(string nazwisko)
    {
        this->nazwisko=nazwisko;
    }

    string getMiejscowosc()
    {
        return miejscowosc;
    }
    void setMiejscowosc(string miejscowosc)
    {
        this->miejscowosc=miejscowosc;
    }
    double getPlaca()
    {
        return placa;
    }
    void setPlaca(double placa)
    {
        this->placa=placa;
    }
    void inicjalizuj (string imie, string nazwisko, string miejscowosc, double placa)
    {
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->miejscowosc=miejscowosc;
        this->placa=placa;

    }
};
int main()
{
    Pracownik n1;
    n1.wczytaj();
    n1.wypisz();
    cout<<n1.getImie();
    cout<<"podaj nowe imie: "<<endl;
    string newImie;
    cin>>newImie;
    n1.setImie(newImie);
    n1.wypisz();
    n1.setNazwisko("Kowalski ");
    cout<<n1.getNazwisko()<<endl;
    n1.wypisz();

    Pracownik n2;
    cin.ignore();
    n2.wczytaj();
    n2.wypisz();
    cout<<n2.getMiejscowosc()<<endl;
    n2.setMiejscowosc("Limanowa");

    n2.setPlaca(5000);
    cout<<n2.getPlaca()<<endl;
    n2.wypisz();

    Pracownik p3;
    p3.inicjalizuj("Kasia","Chrzanowska","Limanowa",2500.59);
    p3.wypisz();

    Pracownik* dyrektor = new Pracownik;
    dyrektor->inicjalizuj("Adam","Kowalski","Warszawa",25454.32);
    dyrektor->wypisz();
    return 0;
}
