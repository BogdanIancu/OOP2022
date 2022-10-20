#include <iostream>
#include <string>
using namespace std;

// passing by value
// x and y are copies of the a & b variables from main
void interschimba1(int x, int y) {
	int aux = x;
	x = y;
	y = aux;
}

// passing by reference
// x and y are the addresses (automatically extracted by the reference)
// of the a & b variables from main
void interschimba2(int& x, int& y) {
	int aux = x;
	x = y;
	y = aux;
}

// passsing by address/pointer
// x and y are the addresses
// of the a & b variables from main (see the call also)
void interschimba3(int* x, int* y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}


int main() {
	int n = 4;
	// dynamically allocated array with malloc
	int* w = (int*)malloc(n * sizeof(int));
	w[1] = 99;
	cout << "The default values will be different for every compiler: ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << w[i] << " ";
	// we use free for deallocation in this case
	free(w);
	// avoiding dangling pointers
	w = nullptr;

	// dynamically allocated array with new
	int* z = new int[n];
	// ... 
	// we use delete for deallocation in this case
	delete[] z;
	// avoiding dangling pointers
	z = nullptr;

	cout << endl;

	// statically allocated matrix
	float m[2][3];
	// we can compute the number of lines and columns
	cout << "Number of lines: ";
	cout << sizeof(m) / sizeof(m[0]) << " ";
	cout << "Number of columns: ";
	cout << sizeof(m[0]) / sizeof(m[0][0]) << endl;

	float k = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = ++k;
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	// dinamically allocated matrix (with new)
	//we cannot compute the numbers of lines and columns
	float** x = new float* [2];
	for (int i = 0; i < 2; i++) {
		x[i] = new float[3];
	}
	// ...
	// deallocation
	// it is always done in the reverse order of the allocation
	for (int i = 0; i < 2; i++) {
		delete[] x[i];
	}
	delete[] x;
	x = nullptr;

	cout << endl;

	// statically allocated char array
	char sir[30];
	// sir = "ceva"; will not work
	// it's like saying  v1 = v2
	// if v1 and v2 are two arrays

	// we use the secure versions strcpy_s
	strcpy_s(sir, "ceva");
	cout << sir << endl;

	// the length of the char array excluding \0
	cout << strlen(sir) << endl;

	// dinamically allocated char array
	char* sir2 = new char[strlen(sir) + 1];
	// the second argument of strcpy_s needs to be passed
	// for dinamically allocated destinations
	// and is the number of characters to be copied
	strcpy_s(sir2, strlen(sir) + 1, sir);
	cout << sir2 << endl;
	//...
	delete[] sir2;

	// string is a class
	// and we can use it as any other built-in type
	string s1;
	s1 = "ceva";
	string s2 = s1 + " cod!";
	cout << s2 << endl;

	// implicit casting from char* to string
	string s3 = sir;
	cout << s3 << endl;

	// explicit transformation of a string
	// into a (constant) char array
	const char* s4 = s2.c_str();
	cout << s4 << endl;
	// the length of a string
	cout << s2.length() << endl;

	int a = 3;
	int b = 5;

	//passing by value
	interschimba1(a, b);
	cout << a << " " << b << endl;

	//passing by referece
	interschimba2(a, b);
	cout << a << " " << b << endl;

	//passing by address
	interschimba3(&a, &b);
	cout << a << " " << b << endl;

	return 0;
}