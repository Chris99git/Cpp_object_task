#include <iostream>
using namespace std;
struct Student
{
    string imie;
    string nazwisko;
    string nrIndeksu;
    double oceny[5];
};
void wczytaj (Student& k)
{
    cout<<endl<<"podaj imie: ";
    cin>>k.imie;
    cout<<endl<<"podaj nazwisko: ";
    cin>>k.nazwisko;
    cout<<endl<<"podaj nr indeksu: ";
    cin>>k.nrIndeksu;
    cout<<endl<<"podaj oceny: ";
    for(int i=0; i<5; i++)
    {
        cin>> k.oceny[i];
    }
    cout<<endl;
}
void wypisz(Student k)
{
    cout<<endl<<"imie: " << k.imie;
    cout<<endl<<"nazwisko: " << k.nazwisko;
    cout<<endl<<"nr_indeksu: " << k.nrIndeksu;
    cout<<endl;
}
double sredniaOcen (Student k)
{
    double sum= 0;
    for(int i=0; i<5; i++)
    {
        sum+=double(k.oceny[i]);
    }
    return sum/5;
}
int main()
{
    Student k1;
    wczytaj(k1);
    wypisz(k1);
    cout <<"Srednia ocen: "<<sredniaOcen(k1)<<endl;

    Student* k2= new Student;
    wczytaj(*k2);
    wypisz(*k2);
    cout <<"Srednia ocen: "<<sredniaOcen(*k2)<<endl;
    delete k2;
    return 0;
}
