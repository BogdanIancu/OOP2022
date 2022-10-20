#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
//#pragma warning(disable:4996);
using namespace std;

void elementePare(int*& vector, int* dimensiune)
{
	if (vector != nullptr && *dimensiune > 0)
	{
		short nrElementePare = 0;
		for (int i = 0; i < *dimensiune; i++) 
		{
			if (vector[i] % 2 == 0) {
				nrElementePare++;
			}
		}
		int* vectorElementePare = new int[nrElementePare];
		int k = 0;
		for (int i = 0; i < *dimensiune; i++) {
			if (vector[i] % 2 == 0) {
				vectorElementePare[k++] = vector[i];
			}
		}
		delete[] vector;
		vector = vectorElementePare;
		*dimensiune = nrElementePare;
	}
}

int main()
{
	//int v[3];
	//int w[5];
	//v = w;
	char sir1[20];
	strcpy_s(sir1, "oop");
	cout << strlen(sir1) << endl;
	char* sir2 = new char[strlen(sir1) + 1];
	strcpy_s(sir2, strlen(sir1) + 1, sir1);
	cout << sir2 << endl;
	char* sir3 = new char[strlen(sir2) + strlen("!!!") + 1];
	strcpy_s(sir3, strlen(sir2) + 1, sir2);
	strcat_s(sir3, strlen(sir2) + strlen("!!!") + 1, "!!!");
	cout << sir3 << endl;
	delete[] sir2;
	sir2 = nullptr;

	string s1 = "abcd";
	cout << s1 << endl;
	string s2 = sir3;

	const char* sir4 = s1.c_str();
	cout << sir4 << endl;
	char* sir5 = new char[strlen(sir4) + 1];
	strcpy_s(sir5, strlen(sir4) + 1, sir4);
	cout << sir5 << endl;

	delete[] sir5;
	sir5 = nullptr;

	delete[] sir3;
	sir3 = nullptr;

	int* v = new int[5] {1, 2, 3, 4, 5};
	int dim = 5;
	elementePare(v, &dim);
	for (int i = 0; i < dim; i++)
	{
		cout << v[i] << " ";
	}
}