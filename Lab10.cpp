#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class InvalidIndexException : public exception
{
};

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

	void serialize()
	{
		ofstream f("student.bin", ios::binary);
		short dim = this->nume.length();
		f.write((char*)&dim, sizeof(dim));
		f.write(nume.c_str(), dim + 1);
		f.write((char*)&nrNote, sizeof(nrNote));
		for (int i = 0; i < nrNote; i++)
		{
			f.write((char*)&note[i], sizeof(note[i]));
		}
		f.close();
	}

	void deserialize()
	{
		ifstream f("student.bin", ios::binary);
		short dim = 0;
		f.read((char*)&dim, sizeof(dim));
		char* n = new char[dim + 1];
		f.read(n, dim + 1);
		nume = n;
		delete[] n;
		f.read((char*)&nrNote, sizeof(nrNote));
		delete[] note;
		note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
		{
			f.read((char*)&note[i], sizeof(note[i]));
		}
		f.close();
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

	int& operator[](int index)
	{
		if (index >= 0 && index < nrNote && note != nullptr)
		{
			return note[index];
		}
		//throw exception("Invalid index");
		//throw 120;
		throw InvalidIndexException();
	}

	friend ostream& operator<<(ostream&, Student);
	friend istream& operator>>(istream&, Student&);
	friend ofstream& operator<<(ofstream&, Student);
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

ofstream& operator<<(ofstream& f, Student s)
{
	f << s.nume << endl;
	f << s.nrNote << endl;
	for (int i = 0; i < s.nrNote; i++)
	{
		f << s.note[i] << endl;
	}
	return f;
}

istream& operator>>(istream& in, Student& s)
{
	cout << "Nume: ";
	//in >> s.nume;
	in >> ws;
	getline(in, s.nume);

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
	in >> (Student&)s;

	if (s.tipBursa != nullptr)
	{
		delete[] s.tipBursa;
	}

	cout << "Tip bursa: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	s.tipBursa = new char[strlen(buffer) + 1];
	strcpy_s(s.tipBursa, strlen(buffer) + 1, buffer);

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

	//cin >> sb1;
	//cout << endl;
	//cout << sb1;
	//cout << endl;

	cout << (string)sb1 << endl;

	try
	{
		cout << s4[1] << endl;
		cout << s4[5] << endl;
		//...
	}
	catch (InvalidIndexException& e)
	{
		cout << "Specific exception for invalid index" << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	catch (int x)
	{
		cout << "Error code: " << x;
	}
	catch (...)
	{
		cout << "Something went wrong";
	}
	//...
	ofstream f("file.txt");
	f << s4;
	f.close();

	ifstream g;
	g.open("file.txt");
	Student s9;
	g >> s9;

	s9.serialize();

	Student s10;
	s10.deserialize();
}