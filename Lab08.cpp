#include <iostream>
#include <string>
using namespace std;

class Auto
{
private:
	char* producator;
	string model;
	float pret;
	static char charInvalid;

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
		else
		{
			this->producator = nullptr;
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
		else
		{
			this->producator = nullptr;
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
			if (a.producator != nullptr)
			{
				if (producator != nullptr)
				{
					delete[] producator;
				}

				this->producator = new char[strlen(a.producator) + 1];
				strcpy_s(this->producator, strlen(a.producator) + 1, a.producator);
			}
			this->model = a.model;
			this->pret = a.pret;
		}
		return *this;
	}

	Auto operator+(Auto a)
	{
		Auto copie = *this;
		copie.pret = copie.pret + a.pret;

		return copie;
	}

	Auto operator+(float val)
	{
		Auto copie = *this;
		copie.pret += val;

		return copie;
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

	//avoids a possible memory leak
	//see lines 203-205 for details
	string getProducatorAsString()
	{
		string copie = producator;
		return copie;
	}

	//index operator that works
	//as setter + getter
	char& operator[](int index)
	{
		if (producator != nullptr && index >= 0 && index < strlen(producator))
		{
			return producator[index];
		}
		else
			return charInvalid;
	}

	//operators are not combined by default
	//even if we overloaded + and =
	//we still need to overload += if we want it
	void operator+=(float valoare)
	{
		this->pret += valoare;
	}

	//operators overloaded as global functions
	//need to be declared as friend
	//in order to get access to private/protected fields
	friend Auto operator+(float valoare, Auto a);
	friend ostream& operator<<(ostream& out, Auto a);
	friend istream& operator>>(istream& in, Auto& a);
};
char Auto::charInvalid = -1;

//float + Auto operator
//we do this to keep the operator commutative
Auto operator+(float valoare, Auto a)
{
	a.pret += valoare;
	return a;
}

//printing operator
ostream& operator<<(ostream& out, Auto a)
{
	out << "Producator: ";
	if (a.producator != nullptr)
	{
		out << a.producator;
	}
	out << endl;
	out << "Model: " << a.model << endl;
	out << "Pret: " << a.pret << endl;

	return out;
}

//reading operator
istream& operator>>(istream& in, Auto& a)
{
	cout << "Producator: ";
	string buffer;
	in >> buffer;
	a.setProducator(buffer.c_str());

	cout << "Model: ";
	in >> a.model;

	cout << "Pret: ";
	in >> a.pret;

	return in;
}

int main()
{
	Auto a1;
	Auto a2("Dacia", "Logan", 9000);
	Auto a3 = a2;
	a1 = a3;

	char* producator = a1.getProducator();
	cout << producator << endl;
	delete[] producator;

	a2.setProducator("Renault");
	cout << a2.getProducatorAsString() << endl;

	Auto a4 = a2 + a3;
	Auto a5 = a4 + 2000;
	Auto a6 = 2000 + a5;

	cout << a6[2] << endl;
	a6[2] = 'N';

	a6 += 5000;
	cout << a6;

	cin >> a1;
	cout << a1;
}