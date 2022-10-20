#include <iostream>
using namespace std;

#define PI 3.14

int main()
{
	int* p = nullptr;
	cout << sizeof(p) << endl;
	int x = 5;
	p = &x;
	cout << p << endl;
	cout << *p << endl;

	const float pi = 3.14;

	int* const q = &x;
	*q = 4;

	const int* r = &x;
	int* t = (int*)r;
	*t = 12;
	cout << x << endl;

	void* pv = &x;
	cout << *((int*)pv) << endl;

	unsigned int dimensiune = 3;
	float v[3];
	cout << v << endl;
	//...
	cout << sizeof(v) / sizeof(v[0]) << endl;

	float* w = (float*)malloc(dimensiune * sizeof(float));
	cout << w[1] << endl;
	free(w);
	w = nullptr;
	cout << w << endl;

	float* z = new float[dimensiune];
	z[0] = 99.5f;
	delete[] z;

	float* y = new float(dimensiune);
	delete y;
}