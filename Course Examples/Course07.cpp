#include <iostream>
using namespace std;

class Baterie
{
private:
	string producator;
	int nivelBaterie = 0;

	friend class TelefonMobil;
	friend void descarca(Baterie);
};

class TelefonMobil
{
private:
	string producator;
	Baterie baterie;

public:
	TelefonMobil()
	{
		producator = "";
		baterie.nivelBaterie = 0;
	}

	void incarca(int nivel)
	{
		baterie.nivelBaterie += nivel;
		if (baterie.nivelBaterie > 100) {
			baterie.nivelBaterie = 100;
		}
	}

	bool operator!()
	{
		return (baterie.nivelBaterie > 0);
	}
};

void descarca(Baterie b)
{
	b.nivelBaterie = 0;
}

int main()
{
	TelefonMobil t1;

	int x = 5;
	int y = ++x;
	int z = x++;

	cout << !t1 << endl;
	cout << t1.operator!() << endl;
}