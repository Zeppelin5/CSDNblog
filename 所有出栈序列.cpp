#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int number = 0;
void func(vector<int>kind, int count[], int n, vector<int> A)
{
	if (count[0] >= 1)
	{
		kind.push_back(1);
		count[0]--;
		func(kind, count, n, A);
		count[0]++;
		kind.pop_back();
	}
	if ((count[1] >= 1) && (count[1]>count[0]))
	{
		kind.push_back(0);
		count[1]--;
		func(kind, count, n, A);
		count[1]++;
		kind.pop_back();
	}
	if (kind.size() == 2 * n)
	{
		vector<int>::iterator iter;
		stack<int>stk;
		int j = 0;
		for (iter = kind.begin(); iter != kind.end(); iter++)
		{
			//cout<<(*iter)<<" ";
			if (1 == (*iter))
			{
				stk.push(A[j]);
				j++;
			}
			else
			{
				cout << stk.top() << " ";
				stk.pop();
			}
		}
		number++;
		cout << endl;
	}
}

int main()
{
	int n, i;
	cout << "please input the number:" << endl;
	cin >> n;
	//int A[n];
	vector<int> A(n);
	cout << "please input the push sequence:" << endl;
	for (i = 0; i<n; i++)
	{
		cin >> A[i];
	}
	int count[2] = { n - 1,n };
	vector<int>kind;
	kind.push_back(1);

	cout << "the result is:" << endl;
	func(kind, count, n, A);
	cout << "total:" << number << endl;

	system("pause");
	return 0;
}
