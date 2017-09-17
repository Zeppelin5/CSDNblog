#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	srand((unsigned)time(0));
	vector<int> ary = { 1,2,2,2,5,6,7,7,9,10 };
	int n = 5;
	int tmp, count = 0;
	int len = ary.size();
	int max = (*max_element(ary.begin(), ary.end()));
	vector<int> hash(max+1);
	for (;;) {
		tmp = ary[rand()% len];
		if (hash[tmp] < 1) {
			hash[tmp]++;
			count++;
			cout << tmp << " ";
			if (count == 5)
				break;
		}
	}
	system("pause");
	return 0;
}
