#include<iostream>
#include<iomanip>
using namespace std;

class String {
	friend ostream& operator<<(ostream&, String&);
	friend istream& operator>>(istream&, String&);
public:
	String(const char*str=NULL) {
		if (!str)
			m_data = 0;
		else {
			m_data = new char[strlen(str) + 1];
			strcpy(m_data, str);
		}
	}
	String(const String &other) {
		if (!other.m_data)
			m_data = 0;
		else {
			m_data = new char[strlen(other.m_data) + 1];
			strcpy(m_data, other.m_data);
		}
	}
	String& operator=(const String& other) {
		if (this != &other) {
			delete[]m_data;
			if (!other.m_data)
				m_data = 0;
			else {
				m_data = new char[strlen(other.m_data) + 1];
				strcpy(m_data, other.m_data);
			}
		}
		return *this;
	}

	String operator+(const String &other)const {
		String newString;
		if (!other.m_data) {
			newString = *this;
		}
		else if (!m_data)
			newString = other;
		else {
			newString.m_data = new char[strlen(m_data) + strlen(other.m_data) + 1];
			strcpy(newString.m_data, m_data);
			strcat(newString.m_data, other.m_data);
		}
		return newString;
	}
	bool operator==(const String &other) {
		if (strlen(other.m_data) != strlen(m_data))
			return false;
		return strcmp(m_data, other.m_data) ? false : true;//strcmp相等时返回0
	}
	char& operator[](unsigned c) {
		if (c >= 0 && c <= strlen(m_data))
			return m_data[c];
	}
private:
	char* m_data;
};

ostream& operator<< (ostream& output, String& other)
{
	output << other.m_data;
	return output;
}
istream& operator>> (istream& input, String& other) {
	char tmp[256];
	input >> tmp;
	other = tmp;
	return input;
}

int main() {
	String str1("abc");
	String str2 = "hello";
	String str3 = str1 + str2;
	String str4 = "abc";
	
	cout << str1 << endl << str2 << endl << str3 << endl << str4 << endl << str4[2] << endl;
	if (str1 == str4)
		cout << "str1 and str4 is equal." << endl;
	else
		cout << "Not equal." << endl;

	String str5;
	cin >> str5;
	cout << str5 << endl;
	system("pause");
	return 0;
}
