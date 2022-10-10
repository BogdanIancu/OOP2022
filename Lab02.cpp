#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    int x = 30;

    int* p = nullptr;
    // NULL is basically just 0 and
    // it ca be used with any data type
    //x = NULL;
    // In C++ we used nullptr because
    // it can be used just with pointers
    //x = nullptr;

    // this will display the address
    // 0 in this case
    cout << p << endl;
    // p saves the address of variable x
    p = &x;

    cout << p << endl;
    // this will display the value from
    // the address saved in p (x in this case)
    cout << *p << endl;

    // this is be 4 on a x86 architecture
    // or 8 on an x64 architecture
    cout << sizeof(p) << endl;

    // r is a reference, it saves the address of x
    int& r = x;
    x++;
    // references show the value not the address
    // when they are used
    cout << r << endl;

    p = nullptr;
    // this will increment p
    // with sizeof(int)
    p++;
    cout << p << endl;

    // q will be the value of p
    // + 3 * sizeof(int)
    int* q = p + 3;
    cout << q << endl;

    // similar for -
    q = q - 2;
    cout << q << endl;
    // the difference between two pointers
    // will be in this case the number of ints
    // that can fit between the two addresses
    // (keep in mind that it can be negative)
    cout << p - q << endl;

    // pointers to void can be used to save
    // any kind of pointer
    void* t = &x;
    // whenever we need the value from that address
    // we need to cast them to the desired type
    cout << *((int*)t) << endl;

    const int n = 5;

    // statically allocated array
    // the size is mandatory to be a constant
    int v[5];
    v[0] = 99;
    // we can compute the size of statically
    // allocated arrays only
    // (this will not work for dinamically allocated arrays)
    cout << sizeof(v) / sizeof(v[0]) << endl;
}