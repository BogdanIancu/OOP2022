#include <iostream>
using namespace std;

class TelefonMobil
{
private:
	int nivelBaterie;

protected:
	string producator;

public:
	int x;
	TelefonMobil()
	{
		nivelBaterie = 0;
		producator = "";
	}

	TelefonMobil(int nivelBaterie) 
	{
		this->nivelBaterie = nivelBaterie;
		producator = "";
	}

	int getNivelBaterie()
	{
		return nivelBaterie;
	}

	void setNivelBaterie(int nivel)
	{
		nivelBaterie = nivel;
	}

	friend ostream& operator<<(ostream& out, TelefonMobil t)
	{
		out << "Nivel baterie: " << t.nivelBaterie << endl;
		out << "Producator: " << t.producator << endl;
		return out;
	}

	friend istream& operator>>(istream& in, TelefonMobil& t)
	{
		cout << "Nivel baterie: ";
		in >> t.nivelBaterie;

		cout << "Producator: ";
		in >> t.producator;

		return in;
	}
};

class TelefonMobilPliabil : public TelefonMobil
{
private:
	int dimensiunePliat;

public:
	float x = 0;
	TelefonMobilPliabil()
	{
		//setNivelBaterie(0);
		//producator = "";
		dimensiunePliat = 0;
	}

	TelefonMobilPliabil(int nivelBaterie, int dimensiune) : 
		TelefonMobil(nivelBaterie)
	{
		dimensiunePliat = dimensiune;
	}

	TelefonMobilPliabil(const TelefonMobilPliabil& t) : TelefonMobil(t)
	{
		//...
		dimensiunePliat = t.dimensiunePliat;
	}

	TelefonMobilPliabil& operator=(const TelefonMobilPliabil& t)
	{
		//(TelefonMobil)(*this) = (TelefonMobil)t;
		TelefonMobil::operator=(t);
		//...
		return *this;
	}

	friend ostream& operator<<(ostream& out, TelefonMobilPliabil t)
	{
		out << (TelefonMobil)t;
		out << "Dimensiune: " << t.dimensiunePliat;
		return out;
	}

	friend istream& operator>>(istream& in, TelefonMobilPliabil& t)
	{
		in >> (TelefonMobil&)t;
		cout << "Dimensiune pliat: ";
		in >> t.dimensiunePliat;
		return in;

	}
};

int main()
{
	TelefonMobil t1;
	t1.setNivelBaterie(50);
	TelefonMobilPliabil tmp1;
	tmp1.setNivelBaterie(100);
	t1 = tmp1;
	TelefonMobil& tr = t1;
	TelefonMobilPliabil& tpr = tmp1;
	tr = tpr;

	TelefonMobil* tp = &t1;
	TelefonMobilPliabil* tmp = &tmp1;
	tp = tmp;

	tmp1.TelefonMobil::x = 90;

	cout << tmp1;

	cin >> tmp1;
	cout << tmp1;
}