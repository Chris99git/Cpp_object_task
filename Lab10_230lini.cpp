#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
#include <math.h>
#include<algorithm>
using namespace std;
const int MAX = 1000;
class BigNumber
{
private:
	int len; //dl liczby
	int tab[MAX]; // tablica cyfr (od końca)
	friend void wczytaj(BigNumber& x);
	friend void wypisz(const BigNumber& x);
	friend ostream& operator<< (ostream& wyjscie, const BigNumber& x);
	friend istream& operator>>(istream& wejscie, BigNumber& x);
	friend BigNumber operator+(BigNumber x, BigNumber y);
	friend BigNumber operator-(BigNumber& x, BigNumber& y);
	friend BigNumber operator*(BigNumber x, int y);
	friend BigNumber przesun(BigNumber x, int k);
	friend BigNumber operator*(BigNumber x, BigNumber y);
public:
	BigNumber& operator*=(int y)
	{
		BigNumber z; //wynik
		if (y == 0)
		{
			z.len = 1;
			z.tab[0] = 0;
			return z; //zwracamy 0
		}
		z.len = len;
		int c = 0; //przeniesienie
		for (int i = 0; i < len; i++)
		{
			z.tab[i] = (tab[i] * y + c) % 10;
			c = (tab[i] * y + c) / 10;
		}
		if (c > 0)
		{
			z.tab[z.len] = c;
			z.len++;
		}
		*this = z;
		return *this;
	}
	BigNumber operator=(const BigNumber &wzor)
	{
		//czy nie ma kopiowania na siebie
		if (this != &wzor)
		{
			//czasami trzeba zlikwidowac wnetrze obiektu
			//kopiujemy dane ze wzoru
			cout << "Uruchamiam operator przypisania " << endl;
			len = wzor.len;
			for (int i = 0; i < len; i++)
			{
				tab[i] = wzor.tab[i];
			}
		}
		return *this;
	}
};

void wczytaj(BigNumber& x)
{
	string s;
	cin >> s;
	x.len = s.length();
	int j = s.length()-1;
	for (int i = 0; i < x.len; i++)
	{
		x.tab[i] = s[j--] - 48;
	}
}
void wypisz(const BigNumber& x)
{
	for (int i = x.len - 1; i >= 0; i--)
	{
		cout << x.tab[i];
	}
}
ostream& operator<< (ostream& wyjscie, const BigNumber& x)
{
	for (int i = x.len - 1; i >= 0; i--)
	{
		wyjscie << x.tab[i];
	}
	return wyjscie;
}
istream& operator>>(istream& wejscie, BigNumber &x)
{
	string s;
	wejscie >> s;
	x.len = s.length();
	int j = s.length() - 1;
	for (int i = 0; i < x.len; i++)
	{
		x.tab[i] = s[j--] - 48;
	}
	return wejscie;
}
BigNumber operator+(BigNumber x, BigNumber y)
{
	BigNumber z; //wynik
	z.len = min(x.len, y.len);
	int c = 0;
	for (int i = 0; i < z.len; i++)
	{
		z.tab[i] = (x.tab[i] + y.tab[i] + c) % 10;
		c = (x.tab[i] + y.tab[i] + c) / 10;
	}
	//jezeli liczba x jest dluzsza
	while (z.len< x.len)
	{
		z.tab[z.len] = (x.tab[z.len] + c) % 10;
		c = (x.tab[z.len] + c) / 10;
		z.len++;
	}
	while (z.len < y.len)
	{
		z.tab[z.len] = (y.tab[z.len] + c) % 10;
		c = (y.tab[z.len] + c) / 10;
		z.len++;
	}
	//jesli zostalo jakies przniesienie to c=1
	if (c > 0)
	{
		z.tab[z.len] = c;
		z.len++;
	}
	return z;
}
BigNumber operator-(BigNumber& x, BigNumber& y)
{
	BigNumber z;
	z.len = x.len;
	int c = 0;
	for (int i = 0; i < x.len; i++)
	{
		if (i < y.len)
			z.tab[i] = x.tab[i] - y.tab[i] + c;
		else
			z.tab[i] = x.tab[i] + c;
		if (z.tab[i] < 0)
		{
			z.tab[i] += 10;
			c = -1;
		}
		else
		{
			c = 0;
		}
	}
	//usuwamy ewentualne zera wiodace
	while (z.len > 1 && z.tab[z.len - 1] == 0)
	{
		z.len--;
	}
	return z;
}
BigNumber operator*(BigNumber x, int y)
{
	BigNumber z;
	if (y == 0)
	{
		z.len = 1;
		z.tab[0] = 0;
		return z;
	}
	z.len = x.len;
	int c = 0;
	for (int i = 0; i < x.len; i++)
	{
		z.tab[i] = (x.tab[i] * y + c) % 10;
		c = (x.tab[i] * y + c) / 10;
	}
	if (c > 0)
	{
		z.tab[z.len] = c;
		z.len++;
	}
	return z;
}
//funkcja mnozy x przez 10 ^ k 
// czyli na koncu wstawia k zer
BigNumber przesun(BigNumber x, int k)
{
	for (int i = x.len - 1; i >= 0; i--)
	{
		x.tab[i + k] = x.tab[i];
	}
	for (int i = 0; i < k; i++)
	{
		x.tab[i] = 0;
	}
	x.len += k;
	return x;
}
BigNumber operator*(BigNumber x, BigNumber y)
{
	BigNumber z; 
	z.len = 1;
	z.tab[0] = 0;
	for (int i = 0; i < y.len; i++)
	{
		BigNumber temp = (x * y.tab[i]);
		temp = przesun(temp, i);
		z = z + temp;
	}
	return z;
}
int main()
{
	BigNumber x;
	wczytaj(x);
	wypisz(x);
	cout << endl << x;
	BigNumber y;
	cin >> y;
	cout << y;
	BigNumber z;
	z = x + y;
	cout <<endl<< z<<endl;
	z = x - y;
	cout << endl << z << endl;
	z = x * 7;
	cout << endl << z << endl;
	cout << endl << x << endl;
	x *= 7;
	cout << endl << x << endl;
	z = x * y;
	cout << endl << z << endl;
}