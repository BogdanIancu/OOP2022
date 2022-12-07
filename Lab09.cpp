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

	Student() :nrMatricol(0)
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

	int getNote(int index) {
		if (index >= 0 && index < nrNote && note != nullptr) {
			return note[index];
		}
		else return -1;
	}
	void setNote(int* note, int nrNote) {
		if (note != nullptr && nrNote > 0) {
			delete[] this->note;
			this->note = new int[nrNote];
			for (int i = 0; i < nrNote; i++) {
				this->note[i] = note[i];
			}
			this->nrNote = nrNote;
		}
	}

	static void setUniversitate(string universitate) {
		Student::universitate = universitate;
	}

	static string getUniversitate() {
		return universitate;
	}

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

	bool operator!() {
		return nrNote <= 0;
	}

	Student& operator++()
	{
		if (note != nullptr && nrNote > 0)
		{
			note[0]++;
		}
		return *this;
	}

	Student operator++(int i)
	{
		Student copie = *this;
		if (note != nullptr && nrNote > 0)
		{
			note[0]++;
		}
		return copie;
	}

	explicit operator string()
	{
		return nume;
	}

	friend ostream& operator<<(ostream&, Student);
	friend istream& operator>>(istream&, Student&);
};
string Student::universitate = "ASE";

ostream& operator<<(ostream& out, Student s)
{
	out << "Nr matricol: " << s.nrMatricol << endl;
	out << "Nume: " << s.nume << endl;
	out << "Nr note: " << s.nrNote << endl;
	out << "Note: ";
	for (int i = 0; i < s.nrNote; i++)
	{
		out << s.note[i] << " ";
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, Student& s)
{
	cout << "Nume: ";
	in >> s.nume;

	cout << "NrNote: ";
	in >> s.nrNote;

	if (s.note != nullptr)
	{
		delete[] s.note;
		s.note = nullptr;
	}

	s.note = new int[s.nrNote];
	cout << "Note: ";
	for (int i = 0; i < s.nrNote; i++)
	{
		in >> s.note[i];
	}

	return in;
}

//public inheritance
class StudentBursier : public Student
{
private:
	char* tipBursa;
	float valoare;

public:
	StudentBursier()
	{
		tipBursa = nullptr;
		valoare = 0;
	}

	//calling the base constructor
	StudentBursier(int nrMatricol, string nume, int nrNote, int* note,
		const char* tipBursa, float valoare) : Student(nrMatricol, nume, note, nrNote)
	{
		if (tipBursa != nullptr)
		{
			this->tipBursa = new char[strlen(tipBursa) + 1];
			strcpy_s(this->tipBursa, strlen(tipBursa) + 1, tipBursa);
		}
		else
		{
			this->tipBursa = nullptr;
		}
		this->valoare = valoare;

	}

	//calling the base constructor in the case of the copy constructor
	StudentBursier(const StudentBursier& sb) : Student(sb)
	{
		this->valoare = sb.valoare;
		if (sb.tipBursa != nullptr)
		{
			this->tipBursa = new char[strlen(sb.tipBursa) + 1];
			strcpy_s(this->tipBursa, strlen(sb.tipBursa) + 1, sb.tipBursa);
		}
		else
		{
			this->tipBursa = nullptr;
		}
	}

	~StudentBursier()
	{
		if (tipBursa != nullptr)
		{
			delete[] tipBursa;
			tipBursa = nullptr;
		}
	}

	StudentBursier& operator=(const StudentBursier& sb)
	{
		if (this != &sb)
		{
			//calling the base implementation of the equals operator

			//option #1
			//(Student)(*this) = (Student)sb;

			//option #2
			Student::operator=(sb);

			if (tipBursa != nullptr)
			{
				delete[] tipBursa;
				tipBursa = nullptr;
			}

			this->valoare = sb.valoare;
			if (sb.tipBursa != nullptr)
			{
				this->tipBursa = new char[strlen(sb.tipBursa) + 1];
				strcpy_s(this->tipBursa, strlen(sb.tipBursa) + 1, sb.tipBursa);
			}
			else
			{
				this->tipBursa = nullptr;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream&, StudentBursier);
	friend istream& operator>>(istream&, StudentBursier&);
};

ostream& operator<<(ostream& out, StudentBursier s)
{
	//calling the operator for student
	out << (Student)s << endl;

	if (s.tipBursa != nullptr)
	{
		out << "Tip bursa: " << s.tipBursa << endl;
	}
	out << "Valoare: " << s.valoare << endl;

	return out;
}

istream& operator>>(istream& in, StudentBursier& s)
{
	//calling the operator for student
	in >> (Student&)s;

	if (s.tipBursa != nullptr)
	{
		delete[] s.tipBursa;
	}

	cout << "Tip bursa: ";
	string buffer;
	in >> buffer;
	s.tipBursa = new char[buffer.length() + 1];
	strcpy_s(s.tipBursa, buffer.length() + 1, buffer.c_str());

	cout << "Valoare: ";
	in >> s.valoare;

	return in;
}

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

	int n[]{ 7,8 };
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

	string x = (string)s1;
	cout << x << endl;

	StudentBursier sb1;
	//upcasting
	s5 = sb1;
	StudentBursier sb2(123, "Ana", 2, n, "de merit", 800);

	cout << endl << sb2;
	cout << endl;
	StudentBursier sb3 = sb2;
	sb1 = sb3;

	cin >> sb1;
	cout << endl;
	cout << sb1;
	cout << endl;

	cout << (string)sb1 << endl;
}