#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string nume;
	int* note;
	int nrNote;
	static string universitate;

public:
	const int nrMatricol;

	//constants are initialized in the constructor header
	Student():nrMatricol(0)
	{
		nume = "Anonim";
		note = nullptr;
		nrNote = 0;
	}

	Student(int nrMatricol, string nume, int* note, int nrNote) : nrMatricol(nrMatricol)
	{
		this->nume = nume;
		if (note != nullptr && nrNote > 0)
		{
			this->note = new int[nrNote];
			for (int i = 0; i < nrNote; i++)
			{
				this->note[i] = note[i];
			}
			this->nrNote = nrNote;
		}
		else
		{
			this->note = nullptr;
			this->nrNote = 0;
		}
	}

	Student(const Student& s) : nrMatricol(s.nrMatricol)
	{
		this->nume = s.nume;
		if (s.note != nullptr && s.nrNote > 0)
		{
			this->note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
			{
				this->note[i] = s.note[i];
			}
			this->nrNote = s.nrNote;
		}
		else
		{
			this->note = nullptr;
			this->nrNote = 0;
		}
	}

	~Student()
	{
		if (this->note != nullptr)
		{
			delete[] this->note;
		}
	}

	//the equals operator cannot copy the const field
	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			if (this->note != nullptr)
			{
				delete[] this->note;
			}
			if (s.note != nullptr && s.nrNote > 0)
			{
				this->note = new int[s.nrNote];
				for (int i = 0; i < s.nrNote; i++)
				{
					this->note[i] = s.note[i];
				}
				this->nrNote = s.nrNote;
			}
			else
			{
				this->note = nullptr;
				this->nrNote = 0;
			}
		}
		return *this;
	}

	int getNrNote() {
		return nrNote;
	}

	int* getNote() {
		if (note != nullptr) {
			int* copy = new int[nrNote];
			for (int i = 0; i < nrNote; i++) {
				copy[i] = note[i];
			}
			return copy;
		}
		else return nullptr;
	}

	//this is an overload of the previous function
	int getNote(int index) {
		if (index >= 0 && index < nrNote && note != nullptr) {
			return note[index];
		}
		else return -1;
	}
	void setNote(int *note,int nrNote) {
		if (note != nullptr && nrNote > 0) {
			delete[] this->note;
			this->note = new int[nrNote];
			for (int i = 0; i < nrNote; i++) {
				this->note[i] = note[i];
			}
			this->nrNote = nrNote;
		}
	}

	//the setter for a static field should be static
	static void setUniversitate(string universitate) {
		Student::universitate = universitate;
	}

	//the getter for a static field should be static
	static string getUniversitate() {
		return universitate;
	}

	//another case of static method, might be a method
	//that processes an array of students instead of a single one (this)
	static float nrMediuNote(Student* studenti, int nrStudenti)
	{
		float suma = 0;
		if (studenti != nullptr && nrStudenti > 0)
		{
			for (int i = 0; i < nrStudenti; i++)
			{
				suma += studenti[i].nrNote;
			}
			suma /= nrStudenti;
		}
		return suma;
	}

	//operator overloading
	bool operator!() {
		return nrNote <= 0;
	}

	//pre-incrementation
	Student& operator++()
	{
		if (note != nullptr && nrNote > 0)
		{
			note[0]++;
		}
		return *this;
	}

	//post-incrementation
	Student operator++(int i)
	{
		Student copie = *this;
		if (note != nullptr && nrNote > 0)
		{
			note[0]++;
		}
		return copie;
	}
};
//static fields should be initialized outline
string Student::universitate = "ASE";

int main()
{
	Student s1;
	int v[]{ 10, 9, 8 };
	Student s2(123, "john", v, 3);
	Student s3(s2);
	Student s4 = s2;

	s1 = s2;
	s1 = s2 = s3;

	int* grades = s4.getNote();
	int nr = s4.getNrNote();

	for (int i = 0; i < nr; i++)
	{
		cout << grades[i] << " ";
	}
	delete[] grades;
	cout << endl;

	int n[] {7,8};
	s4.setNote(n, 2);
	for (int i = 0; i < s4.getNrNote(); i++)
	{
		cout << s4.getNote(i) << " ";
	}
	cout << endl;
	cout << Student::getUniversitate() << endl;
	s3.setUniversitate("Politehnica");
	cout << s4.getUniversitate() << endl;

	Student studenti[]{ s3, s4 };
	cout << Student::nrMediuNote(studenti, 2) << endl;

	cout << !s4 << endl;

	Student s5 = ++s4;
	cout << s4.getNote(0) << endl;
	cout << s5.getNote(0) << endl;

	Student s6 = s4++;
	cout << s4.getNote(0) << endl;
	cout << s6.getNote(0) << endl;
}