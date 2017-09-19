#include<iostream>
#include<vector>
#include<memory>
using namespace std;

template<class T>
class Smartptr {
public:
	Smartptr();
	Smartptr(const Smartptr& rhs);
	Smartptr &operator=(const Smartptr& rhs);
	~Smartptr();
	T* operator-> ();
	T& operator* ();
private:
	void decrRef() {
		if (--*m_pRef == 0) {
			delete m_ptr;
			delete m_pRef;
		}
	}
	T* m_ptr;
	int* m_pRef;
};

template<class T>
Smartptr<T>::Smartptr(T *p) {
	m_ptr = p;
	m_pRef = new int(1);
}

template<class T>
Smartptr<T>::Smartptr(const Smartptr<T>& src) {
	m_ptr = src.m_ptr;
	m_pRef++;
	m_pRef = src.m_pRef;
}

template<class T>
Smartptr<T>::~Smartptr() {
	decrRef();
}

template<class T>
Smartptr<T>& Smartptr<T>::operator=(const Smartptr<T>& rhs) {
	++*rhs.m_pRef;
	decrRef();
	m_ptr = rhs.m_ptr;
	m_pRef = rhs.m_pRef;
	return *this;
}

int main()
{

	system("pause");
	return 0;
}
