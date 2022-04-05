#include <iostream>
#include <iomanip>
using namespace std;
class Pilkarz
{
private:
    string imie;
    string nazwisko;
    string klub;
    double wzrost;
    double waga;
    short tempo;
    short strzaly;
    short podania;
    short drybling;
    short obrona;
    short fizycznosc;
    string slaba_noga;
    string sztuczki;
    int cena_zawodnika;

public:
    Pilkarz()
    {
    }
    Pilkarz(string imie, string nazwisko, string klub, double wzrost, double waga, short tempo, short strzaly, short podania, short drybling, short obrona, short fizycznosc, string slaba_noga, string sztuczki, double cena_zawodnika)
        : imie(imie), nazwisko(nazwisko), klub(klub), wzrost(wzrost), waga(waga), tempo(tempo), strzaly(strzaly), podania(podania), drybling(drybling), obrona(obrona), fizycznosc(fizycznosc), slaba_noga(slaba_noga), sztuczki(sztuczki), cena_zawodnika(cena_zawodnika)
    {
    }
    double OcenaOgolna() const
    {
        return double(tempo + strzaly + podania + drybling + obrona + fizycznosc) / 6;
    }
    void Wypisz() const
    {
        cout << "========== DANE PILKARZA ==========\n\n"
            << imie << " " << nazwisko
            << "\nWzrost: " << wzrost << "m"
            << "\nWaga: " << waga << "kg"
            << "\nKlub: " << klub
            << "\nCena: " << cena_zawodnika
            << "\n\n==================================="
            << "\nOcena ogolna: " <<setprecision(4) << OcenaOgolna()
            << "\n==================================="
            << "\n\n========== UMIEJETNOSCI ==========="
            << "\n\nTempo: " << tempo
            << "\nStrzaly: " << strzaly
            << "\nPodania: " << podania
            << "\nDrybling: " << drybling
            << "\nObrona: " << obrona
            << "\nFizycznosc: " << fizycznosc
            << "\n\n===== DODATKOWE  UMIEJETNOSCI ====="
            << "\n\nSlaba noga: " << slaba_noga
            << "\nSztuczki: " << sztuczki << "\n";
    }
};
int main()
{
    Pilkarz p1("Ronaldo", "Nazari", "Hiszpania", 1.65, 67, 91, 91, 92, 94, 44, 75, "***", "***", 130210000);
    p1.Wypisz();
}