#include <iostream>
#include "pthread.h"
#pragma comment(lib, "pthreadVC2.lib")
using namespace std;

class CSingleton {
public:
	static CSingleton* getInstance();
	static pthread_mutex_t mutex;
	static void cleanInstance();
	int getValue() {
		return m_iValue;
	}
	void setValue(int iValue) {
		m_iValue = iValue;
	}
private:
	int m_iValue;
	static CSingleton* m_pSingleton;
	CSingleton() {
		pthread_mutex_init(&mutex, NULL);
		cout << "Constructor" << endl;
	}

	~CSingleton() {
		cout << "Destructor" << endl;
	}
};

pthread_mutex_t CSingleton::mutex;
CSingleton* CSingleton::m_pSingleton = NULL;

CSingleton* CSingleton::getInstance() {
	if (m_pSingleton == NULL) {
		pthread_mutex_lock(&mutex);
		if (m_pSingleton == NULL) {
			m_pSingleton = new CSingleton();
		}
		pthread_mutex_unlock(&mutex);
	}
	return m_pSingleton;
}

void CSingleton::cleanInstance() {
	delete m_pSingleton;
}

int main()
{
	CSingleton* pSingleton1 = CSingleton::getInstance();
	CSingleton* pSingleton2 = CSingleton::getInstance();
	pSingleton1->setValue(123);
	if (pSingleton1->getValue() == pSingleton2->getValue())
	{
		cout << "Two objects is the same instance" << endl;
	}
	else
	{
		cout << "Two objects isn't the same instance" << endl;
	}

	CSingleton::cleanInstance();

	system("pause");
	return 0;
}
