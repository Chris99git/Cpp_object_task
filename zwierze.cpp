#include <iostream>
using namespace std;

class Zwierze
{
public:
	virtual void prezentuj() = 0; 
	virtual void dajGlos() = 0;
//	void prezentuj()
//	{
//		cout << "jestem zwierzakiem" << end;
//	}
private:

};

class Ssak: public Zwierze
{
public:
	void prezentuj()
	{
		cout << " jestem ssakiem " << endl;
	}

};

class Ptak: public Zwierze
{
public:
	void prezentuj()
	{
		cout << " jestem ptakiem " << endl;
	}
};

class Kot: public Ssak
{
public:
	void dajGlos()
	{
		cout << "Mial miau" << endl;
	}
};
class Pies: public Ssak
{
public:
	void dajGlos()
	{
		cout << "Hau, hau" << endl;
	}
};

class Kaczka: public Ptak
{
public:
	void dajGlos()
	{
		cout << "Kwa, Kwa" << endl;
	}
	void prezentuj()
	{
		cout << "Jestem kaczka dziwavczka" << endl;
	}
};

class Ges : public Ptak
{
public:
	void dajGlos()
	{
		cout << "ge ge" << endl;
	}
	void prezentuj()
	{
		cout << "Jestem ges " << endl;
	}
};
int main()
{
	Zwierze *farma[4];
//	farma = new Zwierze[];
	farma[0] = new Pies();
	farma[1] = new Kot();
	farma[2] = new Kaczka();
	farma[3] = new Ges();

	for (int i = 0; i < 4; i++)
	{
		cout << "======================" << endl;
		farma[i]->prezentuj();
		farma[i]->dajGlos();
	}
	Zwierze* wnz;
	wnz = new Kot();
	wnz->dajGlos();
}