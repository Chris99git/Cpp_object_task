#include <iostream>
using namespace std;
class Przedzial
{
private:
    double lewy;
    double prawy;
public:
    Przedzial()
    {
    }
    Przedzial(double _lewy,double _prawy)
    :lewy(_lewy),prawy(_prawy)
    {
    }
    ~Przedzial()
    {
        cout<<endl<<"przedzial usuniety ";
    }
    void Wypisz()const;
    friend void CzyWPrzedziale();
};
void Przedzial::Wypisz()const
    {
        cout<<endl<<lewy<<" "<<prawy;
    }
void CzyWPrzedziale(Przedzial p)
{

}
int main()
{
    Przedzial p1(2,6);
    const Przedzial p2(1,2);
    // Aby zadeklarowaæ obiekt sta³y nale¿y poprzedziæ nazwê typu s³owem kluczowym const
    p1.Wypisz();
    p2.Wypisz();
}
