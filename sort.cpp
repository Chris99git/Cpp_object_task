#include <iostream>
using namespace std;
struct SList    // typ listy jednokierunkowej
{
    SList * next;
    int data;
};
int main()
{
    SList * L;                       // wskaznik poczštku listy
    SList * e, * p;                  // wskazniki elementów listy
    int n;                             // liczba elementów do posortowania
    int v;                             // wartosc elementu
    L = new SList;                   // tworzymy pierwszego stra¿nika
    L->next = new SList;             // tworzymy drugiego stra¿nika
    L->next->next = NULL;              // drugi stra¿nik jest ostatni na liscie
    L->next->data = 2147483647;        // wartosc drugiego stra¿nika 2^31

    while (cin >> v && v != 0)
    {
        for(p = L; v > p->next->data; p = p->next) ; // czytamy element    szukamy miejsca wstawienia

        e = new SList; // tworzymy nowy element
        e->data = v;       // inicjujemy element
        e->next = p->next;
        p->next = e;      // element wstawiamy do listy L

    }
    e = new SList;
    e->data = 0;
    SList* temp = L->next;
    L->next = e;
    e->next = temp;
    // listê przesy³amy na wyjscie
    for(p = L->next; p->next; p = p->next)
        cout << p->data << endl;

    while(L)    // usuwamy listê z pamiêci
    {
        e = L;
        L = L->next;
        delete e;
    }
    return 0;
}
