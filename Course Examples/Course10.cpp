#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
private:
	string nume;
	int nrMatricol;
	float medie;

public:
	Student(string n, int nr, float m)
	{
		nume = n;
		nrMatricol = nr;
		medie = m;
	}

	friend ostream& operator<<(ostream&, Student);
	friend ofstream& operator<<(ofstream&, Student);
	friend istream& operator>>(istream&, Student&);
};

ostream& operator<<(ostream& out, Student s)
{
	out << "Nume: " << s.nume << endl;
	out << "Matricol: " << s.nrMatricol << endl;
	out << "Medie: " << s.medie << endl;
	return out;
}

ofstream& operator<<(ofstream& f, Student s)
{
	f << s.nume << endl;
	f << s.nrMatricol << endl;
	f << s.medie << endl;
	return f;
}

istream& operator>>(istream& in, Student& s)
{
	in >> ws;
	getline(in, s.nume);
	in >> s.nrMatricol;
	in >> s.medie;
	return in;
}

int main()
{
	char nume[31];
	cin >> ws;
	cin.getline(nume, 30);
	char x;
	cin.get(x);
	cout << nume << endl;
	cout << x << endl;

	string surname;
	cin.ignore(INT32_MAX, '\n');
	getline(cin, surname);
	cout << surname;

	Student s("Ion Popescu", 12345, 9.7);
	cout << s;
	ofstream fisier("student.txt");
	fisier << s;

	Student t("", 0, 0);
	ifstream fisier2("student.txt");
	fisier2 >> t;
	cout << t;
}