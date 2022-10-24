#include <iostream>
#include <string>
using namespace std;

enum culoare
{ 
	rosu = 5, 
	negru = 10, 
	verde
};

union Eticheta
{
	short v1;
	int v2;
	long long v3;
};

struct Carte
{
	int numarPagini;
	float pret;
	char denumire[51];
	char autor[21];
};

class TelefonMobil
{
public:
	float nivelBaterie;

	void incarca(float nivelIncarcare)
	{
		nivelBaterie += nivelIncarcare;
	}
protected:
	string producator;
private:
	string model;
};



int main()
{
	culoare c = culoare::negru;
	cout << c << endl;
	c = culoare::verde;
	cout << c << endl;
	c = (culoare)5;

	Eticheta eticheta;
	eticheta.v3 = 9999999;
	cout << eticheta.v3 << " " << eticheta.v1
		<< " " << eticheta.v2 << endl;
	eticheta.v2 = 7;
	cout << eticheta.v3 << " " << eticheta.v1
		<< " " << eticheta.v2 << endl;

	Carte carte1;
	carte1.pret = 50;
	carte1.numarPagini = 500;
	strcpy_s(carte1.denumire, "Arta razboiului");
	strcpy_s(carte1.autor, "Sun Tzu");

	Carte carte2{ 300, 40.5, "Avutia natiunilor", "Adam Smith" };
	cout << carte2.denumire;

	Carte* pc = &carte1;
	cout << pc->pret << endl;
	cout << (*pc).numarPagini << endl;

	TelefonMobil telefonPersonal;
	TelefonMobil telefonDeServiciu;

	telefonPersonal.nivelBaterie = 40;
	telefonPersonal.incarca(30);
	cout << telefonPersonal.nivelBaterie << endl;
}