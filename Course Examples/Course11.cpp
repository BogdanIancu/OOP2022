#include <iostream>
using namespace std;

class Comparabil
{
public:
	virtual int compara(Comparabil* c) = 0;
};

class Animal
{
public:
	virtual void scoateSunet() = 0;
};

class Pisica : public Animal
{
	//...
public:
	void scoateSunet() override
	{
		cout << "miau" << endl;
	}
};

class Caine : public Animal, public Comparabil
{
public:
	int varsta;

	void scoateSunet() override
	{
		cout << "ham" << endl;
	}

	int compara(Comparabil* c)
	{
		Caine* caine = (Caine*)c;
		if (this->varsta < caine->varsta) return -1;
		else if (this->varsta > caine->varsta) return 1;
		else return 0;
	}
};

int main()
{
	Animal* animale[2];
	Caine c;
	Pisica p;
	animale[0] = &c;
	animale[1] = &p;
	for (int i = 0; i < 2; i++)
	{
		animale[i]->scoateSunet();
	}

	c.varsta = 4;
	Caine c2;
	c2.varsta = 5;

	cout << c.compara(&c2) << endl;
}