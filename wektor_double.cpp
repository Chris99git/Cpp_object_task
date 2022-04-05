#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;
 
class VectorDouble
{
private:
	double *tablica;
	int MaxElemety;
	int IloscElemenotow;
public:
	VectorDouble ()
	{}
	VectorDouble(size_t MaxElemety)
	{
		this->MaxElemety = MaxElemety;
		tablica = new double[MaxElemety];
		IloscElemenotow = 0;
	}
	VectorDouble(const VectorDouble& vectorDouble)
	{
		MaxElemety = vectorDouble.MaxElemety;
		tablica = new double[MaxElemety];
		IloscElemenotow = vectorDouble.IloscElemenotow;
		for (size_t i = 0; i < IloscElemenotow; i++)
			tablica[i] = vectorDouble.tablica[i];
	}
	~VectorDouble()
	{
		delete[] tablica;
	}
 
	void pushBack(double element)
	{
		if (IloscElemenotow >= MaxElemety)
		{
			double* temp = new double[MaxElemety *= 2];
			for (size_t i = 0; i < IloscElemenotow; i++)
				temp[i] = tablica[i];
			delete[] tablica;
			tablica = temp;
		}
		tablica[IloscElemenotow++] = element;
	}
	void pop()
	{
		if (IloscElemenotow)
			IloscElemenotow--;
	}
	size_t capacity() const
	{
		return MaxElemety;
	}
	size_t size() const
	{
		return IloscElemenotow;
	}
	void reverse()
	{
		for (size_t i = 0; i < IloscElemenotow / 2; i++)
			swap(tablica[i], tablica[IloscElemenotow - i - 1]);
	}
 
	void writeAll() const
	{
		for (size_t i = 0; i < IloscElemenotow; i++)
		{
			if (!(i % 5))
				cout << endl;
			cout << setw(7) << tablica[i] << " ";
		}
		cout << endl;
	}
};
 
int main()
{
	srand(time(NULL));
	VectorDouble vector1(5);
	for (size_t i = 0; i < 12; i++)
		vector1.pushBack(double(rand()) / double(rand()));
	vector1.writeAll();
	VectorDouble vector2;
	for (size_t i = 0; i < 10; i++)
		vector2.pushBack(double(rand()) / double(rand()));
	vector2.writeAll();
	vector2.reverse();
	vector2.writeAll();
}