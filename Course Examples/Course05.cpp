#include <iostream>
#include <string>
using namespace std;

int x = 5;

class TelefonMobil
{
public:
	float nivelBaterie;

	TelefonMobil()
	{
		nivelBaterie = 0;
		producator = "";
		model = "";
	}

	TelefonMobil(string _producator, string _model) : TelefonMobil()
	{
		producator = _producator;
		model = _model;
	}

	TelefonMobil(float nivel) : TelefonMobil()
	{
		nivelBaterie = nivel;
	}

	TelefonMobil(const TelefonMobil& telefon)
	{
		producator = telefon.producator;
		model = telefon.model;
		nivelBaterie = telefon.nivelBaterie;
	}

	~TelefonMobil()
	{
		cout << "s-a apelat destructorul" << endl;
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

protected:
	string producator;
private:
	string model;
};

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

	//TelefonMobil unTelefon(40);
	TelefonMobil unTelefon = 40;

	TelefonMobil t5(altTelefon);

	{
		TelefonMobil t6 = altTelefon;
	}

	f(telefonPersonal);
	cout << endl;
	TelefonMobil* pTelefon = new TelefonMobil(75);
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
}