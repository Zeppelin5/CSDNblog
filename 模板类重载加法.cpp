#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <class T1, class T2>
class Point {
public:
	T1 a;
	T2 b;
	Point():a(0),b(0){}
	Point(T1 ta, T2 tb) {
		a = ta; b = tb;
	}
	Point<T1, T2>& operator=(Point<T1, T2> &pt) {
		this->a = pt.a;
		this->b = pt.b;
		return *this;
	}
	friend Point<T1, T2> operator+(const Point<T1, T2>& pt1, const Point<T1, T2>& pt2);
};

template<class T1,class T2>
Point<T1, T2> operator+(Point<T1, T2>& pt1, Point<T1, T2>& pt2) {
	Point<T1, T2> tmp(pt1);
	tmp.a += pt2.a;
	tmp.b += pt2.b;
	return tmp;
}

template<class T1,class T2>
ostream& operator<< (ostream& os, Point<T1, T2>& pt) {
	os << "(" << pt.a << ", ";
	os<< pt.b << ")";
	return os;
}

int main() {
	Point<int,int> A(2, 3);
	Point<int,int> B(4, 5);
	Point<int, int> C;
	C= A + B;
	cout << C << endl;

	system("pause");
	return 0;
}
