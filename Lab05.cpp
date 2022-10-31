#include <iostream>
using namespace std;

class Masina
{
private:
	string producator;
	int nrKilometri;
	float pret;
	int anProductie;

public:
	/*Masina()
	{
		producator = "necunoscut";
		nrKilometri = 0;
		pret = 0;
		anProductie = 2022;
	}*/

	//this constructor will also play the role of the default constructor
	Masina(string producator = "necunoscut", int nrKilometri = 0, float pret = 0)
	{
		this->producator = producator;
		this->nrKilometri = nrKilometri;
		this->anProductie = 2022;
		//the same thing as this->pret
		(*this).pret = pret;
	}

	//copy constructor
	Masina(const Masina& m)
	{
		this->producator = m.producator;
		this->nrKilometri = m.nrKilometri;
		this->pret = m.pret;
		this->anProductie = m.anProductie;
	}

	//destructor
	~Masina()
	{
		cout << "destructor" << endl;
	}

	//getter
	string getProducator()
	{
		return producator;
	}

	//getter
	int getNrKilometri()
	{
		return nrKilometri;
	}

	//setter
	void setNrKilometri(int nrKilometri)
	{
		if (nrKilometri > 0 && nrKilometri >= this->nrKilometri)
			this->nrKilometri = nrKilometri;
	}
};

int main()
{
	Masina m1;
	Masina m2("Dacia", 10, 10000);
	Masina m3(m2); //copy constructor call
	Masina m4 = m2; //also copy constructor call

	cout << m2.getProducator() << endl;

	m4.setNrKilometri(50);
	cout << m4.getNrKilometri() << endl;

	m4.setNrKilometri(30);
	cout << m4.getNrKilometri() << endl;

	//dinamically allocated object
	Masina* m5 = new Masina("Renault");
	cout << m5->getProducator() << endl;
	delete m5;

	//dinamically allocated object array
	Masina* m6 = new Masina[3];
	cout << m6[2].getProducator() << endl;
	delete[] m6;
}