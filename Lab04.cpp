#include<iostream>
using namespace std;

enum day {monday = 5, tuesday = 10, wednesday = 15};

union uniqueId
{
	short v1;
	int v2;
	long long v3;
};

struct book
{
	int noPages;
	float price;
	char author[21];
	char title[21];
};

class student
{
public:
	//attributes
	string name;
	int group;
	char series;

	//default constructor
	student()
	{
		name = "anonymous";
		group = 0;
		series = 'A';
		paidScholarship = true;
	}

	//constructor with parameters
	student(string name, bool paidScholarship)
	{
		//this is the address of the current object
		//its usage is mandatory only when we have
		//a parameter with the same name as an attribute
		this->name = name;
		this->paidScholarship = paidScholarship;
		group = 0;
		series = 'A';
	}

	//method
	void giveScholarship()
	{
		paidScholarship = false;
	}


private:
	bool paidScholarship;
};
int main()
{
	//:: it's called resolution operator
	day d1 = day::monday; 
	cout << d1 << endl;
	d1 = (day)15; //explicit cast
	cout << d1 << endl;

	uniqueId id1;
	id1.v3 = 99;
	cout << id1.v1 << endl;
	//the size of book is 52 because of padding
	cout << sizeof(book) << endl;

	//this way of initializing can be used by structs
	//but not by classes
	book b1{ 200, 50, "Ion Creanga", "Povesti" };
	cout << b1.author << endl;
	book b2;
	strcpy_s(b2.title, "Black Swan");
	cout << b2.title << endl;

	//default constructor call
	student s1;
	//accesing attributes
	s1.name = "John";
	s1.group = 1068;
	s1.series = 'G';
	//method call
	s1.giveScholarship();

	student s2;
	//constructor with parameters call
	student s3("George", true);
}