#include <iostream> 
#include "Osoba.h"
using namespace std;

int main()
{
    Osoba o1;
    Osoba o2("adam","Nowak","Moskwa");
    Osoba o3(o2);
    o3.Wypisz();
    return 0;
}