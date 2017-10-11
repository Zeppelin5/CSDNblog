#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
	string str;
	cin >> str;
	map<char, int> char_count;
	for (int i = 0; i < str.length(); i++) {
		++char_count[str[i]];
	}
	int max = 0;
	
	for (auto &m : char_count) {
		if (m.second > max)
			max = m.second;
	}
	cout << endl;
	for (auto &m : char_count) {
		if (m.second == max)
			cout << "出现最多的字符是：" << m.first << endl << "出现了" << m.second << "次" << endl;
	}
	system("pause");
	return 0;
}
