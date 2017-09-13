#include<queue>
#include<iostream>
using namespace std;

struct cmp1 {//小优先级
	bool operator() (int& a, int& b) {
		return a > b;
	}
};

struct number
{
	int x;
	bool operator< (const number &a)const {
		return a.x < x;
	}
};

int a[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
number num1[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };

int main() {
	priority_queue<int> que_def;
	priority_queue<int, vector<int>, cmp1> que1;

	for (int i = 0; a[i]; i++) {
		que_def.push(a[i]);
	}
	for (int i = 0; a[i]; i++) {
		cout << que_def.top() << " ";
		que_def.pop();
	}

	cout << "=========================" << endl;

	for (int i = 0; num1[i].x; i++) {
		que1.push(num1[i].x);
	}
	for (int i = 0; num1[i].x; i++) {
		cout << que1.top() << " ";
		que1.pop();
	}

	cout << "=========================" << endl;

	for (int i = 0; a[i]; i++) {
		que1.push(a[i]);
	}
	for (int i = 0; a[i]; i++) {
		cout << que1.top() << " ";
		que1.pop();
	}

	system("pause");
	return 0;
}
