#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <xfunctional>
#include <algorithm>
#include <deque>
#include <functional>
using namespace std;

enum Color
{
	RED = 0,
	BLACK = 1
};

struct RBTreeNode
{
	RBTreeNode*left, *right, *parent;
	int   key;
	int data;
	Color color;
};

class Base {
public:
	virtual void Print() {
		cout << "Base print" << endl;
	}
	virtual ~Base() {
		cout << "Base Destructor" << endl;
	}
};

class Derived :public Base {
private:
	void Print() {
		cout << "Derived print" << endl;
	}
	~Derived() {
		cout << "Derived Destructor" << endl;
	}
	int d_a;
};

bool compare(int a, int b) {
	return  a < b;
}


int main() {
	cout << "Map----------------------------------" << endl;
	map<int, string, greater<int>> ms;
	ms.insert(pair<int, string>(1, "aa"));
	ms.insert(pair<int, string>(2, "bb"));
	ms.insert(pair<int, string>(3, "cc"));
	ms.insert(pair<int, string>(3, "dd"));
	ms.insert(pair<int, string>(-1, "dd1"));
	for (map<int, string, greater<int>>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << (*it).first << ", " << (*it).second << endl;
	}
	cout << "Map after erase:" << endl;
	ms.erase(2);
	for (map<int, string, greater<int>>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << (*it).first << ", " << (*it).second << endl;
	}

	cout << endl<<"Vector----------------------------------" << endl;
	vector<int> ary = { 2,3,4,1,4,0,6,5 };
	sort(ary.begin(), ary.end(), compare);
	for (auto c : ary)
		cout << c << " ";
	cout << endl;
	reverse(ary.begin(),ary.end());
	for (auto c : ary)
		cout << c << " ";
	cout << "After remove" << endl;
	vector<int>::iterator it_remove;
	it_remove = remove(ary.begin(), ary.end(), 4);
	for (auto c : ary)
		cout << c << " ";
	cout << endl;

	//print(ary);
	//for_each(ary.begin(), ary.end(), print<int>);

	cout << endl << "Deque----------------------------------" << endl;
	deque<int> de;
	for (int i = 1; i <= 9; i++) {
		de.push_back(i*2);
	}
	for (auto c : de)
		cout << c << " ";
	cout << endl;
	deque<int>::iterator it_de1, it_de2;
	it_de1 = find(de.begin(), de.end(), 2);
	it_de2 = find(de.begin(), de.end(), 2);
	//for_each(it_de1, it_de2, print<int>);
	deque<int>::reverse_iterator rit_de;

	cout << endl << "函数对象----------------------------------" << endl;
	minus<int> int_minus;
	cout << int_minus(3, 4) << endl;

	cout << endl << "函数适配器bind1st,bind2nd----------------------------------" << endl;
	binder1st<minus<int>> minusob = bind1st(minus<int>(), 10);
	cout <<"binder1st minusob(20): " << minusob(20) << endl;
	binder2nd<minus<int>> minusob2 = bind2nd(minus<int>(), 10);
	cout << "binder2nd minusob(20): " << minusob(20) << endl;

	vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//返回数组中大于等于 或 小于等于 n的数: count_if(vec.begin(), vec.end(), bind1st(less_equal<int>(), n));
	int bigger = count_if(vec.begin(), vec.end(), bind1st(less_equal<int>(), 3));//3<=bigger
	int smaller = count_if(vec.begin(), vec.end(), bind1st(greater_equal<int>(), 3));//3>=smaller
	cout << bigger << " " << smaller << endl;
	int bigger2 = count_if(vec.begin(), vec.end(), bind2nd(greater_equal<int>(), 3));//bigger2>=3
	int smaller2 = count_if(vec.begin(), vec.end(), bind2nd(less_equal<int>(), 3));//smaller2<=3
	cout << bigger2 << " " << smaller << endl;


	system("pause");
	return 0;
}
