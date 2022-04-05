#include <iostream>
using namespace std;
int main()
{
    int n;
    int x1[10],y1[10],x2[10],y2[10]; // wspolrzedne dzialki w tablicy
    cin>>n;
    int i;//licznik

    //zapis wspó³rzêdnych dzia³ek do tablicy
    for(i=0; i<n; i++)
    {
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
    }
    int x,y;//pozycja Jasia
    cin>>x>>y;
    //gdzie jest Jas?
    for(i=0; i<n; i++)
    {
        if(x>=x1[i]&&y>=y1[i]&&x<=x2[i]&&y<=y2[i])
            cout<<i+1;//kolezanki liczymy od 1 nie od 0
    }
    return 0;
}
