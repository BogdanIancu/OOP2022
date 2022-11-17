#include <iostream>
#include <string>
using namespace std;

class Auto
{
private:
	char* producator;
	string model;
	float pret;

public:
	Auto()
	{
		producator = nullptr;
		model = "";
		pret = 0;
	}

	Auto(const char* producator, string model, float pret)
	{
		if (producator != nullptr)
		{
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
		this->model = model;
		this->pret = pret;
	}

	Auto(const Auto& a)
	{
		if (a.producator != nullptr)
		{
			this->producator = new char[strlen(a.producator) + 1];
			strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
		}
		this->model = a.model;
		this->pret = a.pret;
	}

	~Auto()
	{
		if (producator != nullptr)
		{
			delete[] producator;
		}
	}

	Auto& operator=(const Auto& a)
	{
		if (this != &a)
		{
			if (producator != nullptr)
			{
				delete[] producator;
			}

			if (a.producator != nullptr)
			{
				this->producator = new char[strlen(a.producator) + 1];
				strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
			}
			this->model = a.model;
			this->pret = a.pret;
		}
		return *this;
	}

	char* getProducator()
	{
		if (producator != nullptr)
		{
			char* copy = new char[strlen(producator) + 1];
			strcpy_s(copy, strlen(producator) + 1, producator);
			return copy;
		}
		return nullptr;
	}

	void setProducator(const char* producator)
	{
		if (producator != nullptr)
		{
			if (this->producator != nullptr)
			{
				delete[] this->producator;
			}
			this->producator = new char[strlen(producator) + 1];
			strcpy_s(this->producator, strlen(producator) + 1, producator);
		}
	}
};

int main()
{
	Auto a1;
	Auto a2("Dacia", "Logan", 9000);
	Auto a3 = a2;
	a1 = a3;
	cout << a1.getProducator() << endl;
	a2.setProducator("Renault");
	cout << a2.getProducator() << endl;
}