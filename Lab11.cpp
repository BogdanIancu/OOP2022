#include <iostream>
#include <string>
using namespace std;

//abstract class
class Taxable
{
public:
	//pure virtual method
	virtual float computeTax() = 0;
};

class Auto : public Taxable
{
protected:
	string producer;
	float speed;

public:
	Auto()
	{
		producer = "";
		speed = 0;
	}

	Auto(string producer, float speed)
	{
		this->producer = producer;
		this->speed = speed;
	}

	//overriding
	float computeTax()
	{
		return 50;
	}
};

class House
{
protected:
	string producer;
	float price;

public:
	House()
	{
		producer = "";
		price = 0;
	}

	House(string producer, float price)
	{
		this->producer = producer;
		this->price = price;
	}

	//virtual method
	virtual float computePrice()
	{
		return price * 1.19;
	}
};

class Camper : public Auto, public House
{
private:
	int noOfSeats;
	string producer;

public:
	Camper()
	{
		noOfSeats = 2;
		//Auto::producer = "Fiat";
		//House::producer = "ABC";
		producer = "Citroen";
		price = 500;
	}

	Camper(string producer, float price, int noOfSeats) : House(producer, price), Auto()
	{
		this->noOfSeats = noOfSeats;
	}

	//overriding without keyword
	float computePrice()
	{
		return price * 1.19 + 10000;
	}

	//overriding with keyword
	float computeTax() override
	{
		return 100;
	}
};

int main()
{
	Auto a1("Dacia", 50);
	House h1("One Properties", 500000);
	Camper c1;

	a1 = c1;
	h1 = c1;

	cout << c1.computePrice() << endl;
	cout << h1.computePrice() << endl;

	//overriding works just on pointers or references
	House* p;
	p = &h1;
	cout << p->computePrice() << endl;
	p = &c1;
	cout << p->computePrice() << endl;
	bool ok = false;
	//if (ok)
	//{
	//	cout << a1.computeTax();
	//}
	//else
	//{
	//	cout << c1.computeTax();
	//}
	Taxable* t;
	if (ok)
	{
		t = &a1;
	}
	else
	{
		t = &c1;
	}

	cout << t->computeTax();
}