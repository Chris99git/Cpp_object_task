#include <iostream>
#include <cstdlib>
using namespace std;

int const LIMIT = 30;
struct Kolejka
{
    int tab[LIMIT];
    int rear; //indeks ostatniego elementu kolejki
    int front; //indeks pierwszego elementu kolejki
};

//Tworzy kolejke pusta
void makeNull(Kolejka &Q)
{
    Q.rear = -1;
    Q.front = 0;
}

//Sprawdza czy kolejka jest pusta
bool empty(Kolejka Q)
{
//    if(Q.rear+1 == Q.front || (Q.rear==LIMIT-1 && Q.front==0))
//    if((Q.rear+1)&LIMIT==Q.front)
//    {return true;}
//    else {return false;}
    return ((Q.rear+1)%LIMIT==Q.front);
}

//Sprawdza czy kolejka jest pelna
bool full(Kolejka Q)
{
    return ((Q.rear+2)%LIMIT == Q.front);
}

//Wstawia element x na koniec kolejki Q
void enqueue(Kolejka &Q,int x)
{
    if(!full(Q))
    {
//        if(Q.rear!=LIMIT-1){
//            Q.rear++;
//            Q.tab[Q.rear]==x;
//        }
//        else{
//            Q.rear=0;
//            Q.tab[Q.rear]=x;
//        }
        Q.rear=(Q.rear+1)%LIMIT;
        Q.tab[Q.rear]=x;
    }

}

//Usuwa element z pocz¹tku kolejki
void dequeue(Kolejka &Q)
{
    if(!empty(Q))
    {
       Q.front=(Q.front+1)%LIMIT;
    }

}

//Zwraca element z poczatku kolejki
int first(Kolejka Q)
{
    return Q.tab[Q.front];
}

//wypisuje kolejke
void print(Kolejka Q)
{
    if(!empty(Q))
    {
    int i=Q.front;
    cout<<endl<<"zawartosc kolejki: ";
    while(i!=Q.rear)
    {
        cout<<" "<<Q.tab[i];
        i=(i+1)%LIMIT;
    }
    cout<<" "<<Q.tab[Q.rear]<<endl;
    }
}

int main()
{
    Kolejka k1;
    makeNull(k1);
    cout<<endl<<empty(k1);
    cout<<endl<<full(k1);
    for(int i=0; i<30;i++)
    {
        enqueue(k1,i);
    }
    cout<<endl<<full(k1);
    dequeue(k1);
    cout<<endl<<full(k1);
    print(k1);
    return 0;
}
