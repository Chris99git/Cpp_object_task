#include <iostream>
using namespace std;

struct Pkt
{
    unsigned x,y;
};
struct Girl
{
    Pkt a,b;
};

int main()
{
    int n;
    cin>>n;
    Girl G[10];
    Pkt J;
    //zapis wspó³rzêdnych dzia³ek do tablicy
    for(int i=0; i<n; ++i)
        cin>>G[i].a.x>>G[i].a.y>>G[i].b.x>>G[i].b.y;
    cin>>J.x>>J.y; //pozycja Jasia
    for(int i=0; i<n; ++i)
        if((G[i].a.x<=J.x)&&(J.x<=G[i].b.x)&&(G[i].a.y<=J.y)&&(J.y<=G[i].b.y))
            cout<<(n=i+1)<<endl;
    return 0;
}
