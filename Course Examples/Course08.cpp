#include <iostream>
#include <fstream>
using namespace std;

class TelefonMobil
{
private:
	char* producator;
	int* durataZilnicaUtilizare;
	int nrZile;
	static int durataInvalida;

public:
	TelefonMobil()
	{
		producator = nullptr;
		durataZilnicaUtilizare = nullptr;
		nrZile = 0;
	}

	TelefonMobil(const char* producator, const int* durataZilnicaUtilizare,
		int nrZile) : TelefonMobil()
	{
		if (producator != nullptr)
		{
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
		if (durataZilnicaUtilizare != nullptr && nrZile > 0)
		{
			this->durataZilnicaUtilizare = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaUtilizare[i] = durataZilnicaUtilizare[i];
			}
			this->nrZile = nrZile;
		}
	}

	TelefonMobil(const TelefonMobil& t) : 
		TelefonMobil(t.producator, t.durataZilnicaUtilizare, t.nrZile)
	{
	}

	~TelefonMobil()
	{
		delete[] producator;
		delete[] durataZilnicaUtilizare;
	}

	TelefonMobil& operator=(const TelefonMobil& t)
	{
		if (this != &t)
		{
			delete[] producator;
			delete[] durataZilnicaUtilizare;

			if (t.producator != nullptr)
			{
				this->producator = new char[strlen(t.producator) + 1];
				strcpy_s(this->producator, strlen(t.producator) + 1, t.producator);
			}
			if (t.durataZilnicaUtilizare != nullptr && t.nrZile > 0)
			{
				this->durataZilnicaUtilizare = new int[t.nrZile];
				for (int i = 0; i < t.nrZile; i++)
				{
					this->durataZilnicaUtilizare[i] = t.durataZilnicaUtilizare[i];
				}
				this->nrZile = t.nrZile;
			}
		}
		return *this;
	}

	int& operator[](int index)
	{
		if (durataZilnicaUtilizare != nullptr && index >= 0 && index < nrZile)
		{
			return durataZilnicaUtilizare[index];
		} 
		else
		{
			return durataInvalida;
		}

	}

	friend ostream& operator<<(ostream&, TelefonMobil);
	friend istream& operator>>(istream& in, TelefonMobil& t);
};

int TelefonMobil::durataInvalida = -1;

ostream& operator<<(ostream& out, TelefonMobil t)
{
	out << "Producator: " << (t.producator != nullptr ? t.producator : "") << endl;
	out << "Nr zile: " << t.nrZile << endl;
	if (t.durataZilnicaUtilizare != nullptr)
	{
		for (int i = 0; i < t.nrZile; i++)
		{
			out << "Durata ziua " << (i + 1) << ": " 
				<< t.durataZilnicaUtilizare[i] << endl;
		}
	}
	return out;
}

istream& operator>>(istream& in, TelefonMobil& t)
{
	cout << "Producator: ";
	delete[] t.producator;
	//char sir[100];
	//in >> sir;
	//t.producator = new char[strlen(sir) + 1];
	//strcpy_s(t.producator, strlen(sir) + 1, sir);
	string buffer;
	in >> buffer;
	t.producator = new char[buffer.length() + 1];
	strcpy_s(t.producator, buffer.length() + 1, buffer.c_str());
	cout << "Nr zile: ";
	in >> t.nrZile;
	delete[] t.durataZilnicaUtilizare;
	t.durataZilnicaUtilizare = new int[t.nrZile];
	for (int i = 0; i < t.nrZile; i++)
	{
		cout << "Durata zilnica pentru ziua " << (i + 1) << ": ";
		in >> t.durataZilnicaUtilizare[i];
	}
	return in;
}

int main()
{
	int durate[]{ 1, 2, 3 };
	TelefonMobil t1;
	TelefonMobil t2("Nokia", durate, 3);
	TelefonMobil t3 = t2;
	t1 = t3;
	cout << t1;
	cin >> t2;
	cout << t2;
	t2[0] = 24;
	cout << t2[0] << endl;
}