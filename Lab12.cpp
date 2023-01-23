#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;

//int add(int x, int y)
//{
//	return x + y;
//}

template <typename T>
T add(T x, T y)
{
	return x + y;
}

template <class T1, class T2>
T1 add(T1 x, T2 y)
{
	return x + y;
}

template <class T = int, int size = 1>
class Vector
{
private:
	T elements[size];
public:
	T& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return elements[index];
		}
		throw exception("invalid index!");
	}
};

int main()
{
	int a = 5;
	int b = 7;
	cout << add<int>(a, b) << endl;
	cout << add(a, b) << endl;

	float c = 2.5;
	cout << add<float, int>(c, b) << endl;

	Vector<double, 10> v1;
	v1[0] = 1.2;
	v1[1] = 2.5;
	//...
	cout << v1[1] << endl;

	Vector<> v2;
	Vector<long> v3;

	vector<float> w;
	w.push_back(2.5);
	w.push_back(3.2);
	w.push_back(7.8);

	for (int i = 0; i < w.size(); i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;

	w.pop_back();

	for (vector<float>::iterator it = w.begin(); it != w.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	for (float x : w)
	{
		cout << x << " ";
	}
	cout << endl;

	list<int> l;
	l.push_back(6);
	l.push_front(2);
	l.insert(++l.begin(), 5);

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(7);
	s.insert(1);

	for (int i : s)
	{
		cout << i << " ";
	}
	cout << endl;

	map<string, long> m;
	m.insert(make_pair("Ionel", 72367167));
	m.insert(pair<string, long>("Vasile", 2673675));
	cout << m["Ionel"] << endl;
}