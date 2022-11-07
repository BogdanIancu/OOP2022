#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string nume;
	int* note;
	int nrNote;

public:
	Student()
	{
		nume = "Anonim";
		note = nullptr;
		nrNote = 0;
	}
	
	Student(string nume, int* note, int nrNote)
	{
		this->nume = nume;
		//we need to create deep copies
		//for dinamically allocated arrays
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

	//copy constructor is mandatory
	//when we have a pointer member
	Student(const Student& s)
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

	//destructor is mandatory
	//when we have a pointer member
	~Student()
	{
		if (this->note != nullptr)
		{
			delete[] this->note;
		}
	}

	//equals operator is mandatory
	//when we have a pointer member
	//this copies information from an existing object
	//into another existing object
	Student& operator=(const Student& s)
	{
		//by checking this we avoid auto-assignation
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

	int getNoGrades() {
		return nrNote;
	}

	//the getter needs to return a copy
	int* getGrades() {
		if (note != nullptr) {
			int* copy = new int[nrNote];
			for (int i = 0; i < nrNote; i++) {
				copy[i] = note[i];
			}
			return copy;
		}
		else return nullptr;
	}

	//version 2 of getter
	//this avoids possible memory leaks
	int getGrade(int index) {
		if (index >= 0 && index < nrNote && note != nullptr) {
			return note[index];
		}
		else return -1;
	}
};


int main()
{
	Student s1;
	int v[] { 10, 9, 8 };
	Student s2("john", v, 3);
	//copy constructor
	Student s3(s2);
	//still copy constructor
	Student s4 = s2;

	//equals operator
	s1 = s2;
	//chained call of equals operator
	//works only if the operator doesn't return void
	s1 = s2 = s3;

	int* grades = s4.getGrades();
	int nr = s4.getNoGrades();

	for (int i = 0; i < nr; i++)
	{
		cout << grades[i] << " ";
	}
	//we need to do this in order to avoi memory leaks
	delete[] grades;
	cout << endl;

	for (int i = 0; i < nr; i++)
	{
		cout << s4.getGrade(i) << " ";
	}
}