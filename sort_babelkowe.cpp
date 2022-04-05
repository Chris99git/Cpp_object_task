#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Generuj(int *tab,int n)
{
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        tab[i]=rand()%100;
    }
}
void Wypisz(int *tab,int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
void Bubble (int* tab,int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if (tab[j]>tab[j+1])
            {
                tab[j]=tab[j]^tab[j+1];
                tab[j+1]=tab[j]^tab[j+1];
                tab[j]=tab[j]^tab[j+1];
//                int z;
//                z=tab[j];
//                tab[j]=tab[j+1];
//                tab[j+1]=z;
            }
        }
    }
}
void SorWstawianie(int *tab,int n)
{
    for(int i=1; i<n; i++)
    {
        int k=i-1;
        int x;
        x=tab[i];
        while(k>=0&&tab[k]>x)
        {
            tab[k+1]=tab[k];
            k--;
        }
        tab[k+1]=x;
    }
}
int main()
{
    int n;
    cin>>n;
    int *tab=new int[n];
    Generuj(tab,n);
    Wypisz(tab,n);
    Bubble(tab,n);
    Wypisz(tab,n);
    SorWstawianie(tab,n);
    Wypisz(tab,n);

}
