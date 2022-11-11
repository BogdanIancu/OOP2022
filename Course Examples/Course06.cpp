#include <iostream>
#include <string>
using namespace std;

int x = 5;

class TelefonMobil
{
public:
	const int id;
	float nivelBaterie;

	TelefonMobil() : id(0)
	{
		nivelBaterie = 0;
		producator = "";
		model = "";
		this->durataZilnicaUtilizare = nullptr;
		this->nrZile = 0;
	}

	TelefonMobil(string _producator, string _model) : TelefonMobil()
	{
		producator = _producator;
		model = _model;
	}

	TelefonMobil(float nivel, int id) : id(id)
	{
		nivelBaterie = nivel;
		this->durataZilnicaUtilizare = nullptr;
		this->nrZile = 0;
	}

	TelefonMobil(const TelefonMobil& telefon) : id(telefon.id)
	{
		producator = telefon.producator;
		model = telefon.model;
		nivelBaterie = telefon.nivelBaterie;

		if (telefon.durataZilnicaUtilizare != nullptr && telefon.nrZile > 0)
		{
			this->nrZile = telefon.nrZile;
			this->durataZilnicaUtilizare = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaUtilizare[i] = telefon.durataZilnicaUtilizare[i];
			}
		}
		else {
			this->durataZilnicaUtilizare = nullptr;
			this->nrZile = 0;
		}
	}

	TelefonMobil(int id, int* durataZilnicaUtilizare, int nrZile) : id(id)
	{
		if (durataZilnicaUtilizare != nullptr && nrZile > 0)
		{
			this->nrZile = nrZile;
			this->durataZilnicaUtilizare = new int[nrZile];
			for (int i = 0; i < nrZile; i++) 
			{
				this->durataZilnicaUtilizare[i] = durataZilnicaUtilizare[i];
			}
			this->producator = "";
		}
		else {
			this->durataZilnicaUtilizare = nullptr;
			this->nrZile = 0;
		}

		this->nivelBaterie = 0;
	}

	~TelefonMobil()
	{
		if (durataZilnicaUtilizare != nullptr) 
		{
			delete[] durataZilnicaUtilizare;
			durataZilnicaUtilizare = nullptr;
		}	
	}

	string getModel()
	{
		return model;
	}

	string getProducator()
	{
		return producator;
	}

	void setProducator(string producator)
	{
		if (producator.length() > 0)
		{
			this->producator = producator;
		}
	}

	void incarca(float nivelIncarcare)
	{
		nivelBaterie += nivelIncarcare;
	}

	static int getNivelMaximIncarcare() 
	{
		return nivelMaximIncarcare;
	}

	static void setNivelMaximIncarcare(int nivelMaximIncarcare)
	{
		TelefonMobil::nivelMaximIncarcare = nivelMaximIncarcare;
	}

	static float nivelMediuIncarcare(TelefonMobil* telefoane, int nrTelefoane)
	{
		float suma = 0;
		for (int i = 0; i < nrTelefoane; i++)
		{
			suma += telefoane[i].nivelBaterie;
		}
		return suma / nrTelefoane;
	}

protected:
	string producator;
private:
	string model;
	static int nivelMaximIncarcare;
	int* durataZilnicaUtilizare;
	int nrZile;
};

int TelefonMobil::nivelMaximIncarcare = 100;

TelefonMobil f(TelefonMobil t)
{
	t.nivelBaterie = 100;
	return t;
}


int main()
{
	TelefonMobil telefonPersonal;
	TelefonMobil telefonDeServiciu;

	telefonPersonal.nivelBaterie = 40;
	telefonPersonal.incarca(30);
	cout << telefonPersonal.nivelBaterie << endl;

	TelefonMobil altTelefon("Samsung", "S20");

	TelefonMobil unTelefon(40, 1);
	//TelefonMobil unTelefon = 40;

	TelefonMobil t5(altTelefon);

	{
		TelefonMobil t6 = altTelefon;
	}

	f(telefonPersonal);
	cout << endl;
	TelefonMobil* pTelefon = new TelefonMobil(75, 2);
	//...
	delete pTelefon;
	pTelefon = nullptr;

	cout << endl;
	cout << altTelefon.getModel() << endl;

	altTelefon.setProducator("Apple");
	cout << altTelefon.getProducator() << endl;

	altTelefon.setProducator("");
	cout << altTelefon.getProducator() << endl;

	int x = 3;
	cout << x << endl;

	cout << TelefonMobil::getNivelMaximIncarcare() << endl;
	altTelefon.setNivelMaximIncarcare(150);
	cout << TelefonMobil::getNivelMaximIncarcare() << endl;

	TelefonMobil vector[]{ telefonPersonal, unTelefon };
	cout << TelefonMobil::nivelMediuIncarcare(vector, 2) << endl;

	int durate[]{ 2, 4, 5 };
	TelefonMobil telefon5(7, durate, 3);
}