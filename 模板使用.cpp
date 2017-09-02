#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
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
	void Print();
	friend Point<T1, T2> operator+(const Point<T1, T2>& pt1, const Point<T1, T2>& pt2);
};

template<class T1,class T2>
void Point<T1, T2>::Print() {
	cout << this->a << ", " <<this->b << endl;//this可要可不要
}


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

template<class T>
class Base {
public:
	void work(int num) {
		cout << num << endl;
	}
};

template<class T,int num>
class Derived: public Base<T>{
public:
	void work() {
		Base<T>::work(num);
	}
};

int main() {
	Point<int,int> A(2, 3);
	Point<int,int> B(4, 5);
	Point<int, int> C; 
	C= A + B;
	cout << C <<" "<<"Overloading Done" <<endl;

	cout << endl << "auto_ptr 使用" << endl;
	auto_ptr<Point<int, int>> D(new Point<int, int>(1, 2));
	D->Print();

	cout << endl << "模板分离使用" << endl;
	Derived<int, 1> d1;
	d1.work();
	Derived<int, 2> d2;
	d2.work();

	system("pause");
	return 0;
}
