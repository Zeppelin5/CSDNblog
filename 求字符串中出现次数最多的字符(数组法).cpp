#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
	string str;
	cin >> str;
	vector<int> asc(128);
	for (int i = 0; i < str.length(); i++) {
		int tmp = str[i];
		asc[tmp]++;
	}

	cout << "最大的字符出现次数是：" << *max_element(asc.begin(),asc.end()) << endl;
	vector<int>::iterator maxit = max_element(asc.begin(), asc.end());
	int pos = distance(asc.begin(), maxit);
	cout << "出现最多的字符是：" << char(pos) << endl;

	system("pause");
	return 0;
}
