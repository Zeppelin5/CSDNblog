#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindCloset(vector<int> secretCode, int teamCode) {
	int min = 0;
	int pos_goodman = 0;
	for (int i = 0; i < secretCode.size(); i++) {
		int tmp = abs(secretCode[i] - teamCode);
		if (tmp < min) {
			min = tmp;
			pos_goodman = i;
		}
	}
	return pos_goodman;
}

int TeamCode(vector<int> secretCode) {
	int sum = 0;
	for (int i = 0; i < secretCode.size(); i++)
		sum = +secretCode[i];
	int TeamCode = sum / 2;
	return TeamCode;
}

int FindT(vector<int> secretCode, int num) {
	while (secretCode.size() > 1) {
		int teamcode = TeamCode(secretCode);
		int goodman = FindCloset(secretCode, teamcode);
		vector<int>::iterator it = secretCode.begin();
		for (int i = 0; i < goodman; i++) {
			it++;
		}
		secretCode.erase(it);
	}
	return secretCode[0];
}

int main() {
	int num;
	cin >> num;
	vector<int> secretCode(num);
	for (auto &c : secretCode)
		cin >> c;
	cout << FindT(secretCode, num) << endl;
	system("pause");
	return 0;
}
