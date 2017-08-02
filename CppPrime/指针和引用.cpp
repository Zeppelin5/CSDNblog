#include<iostream>  
#include<string>  
#include<vector>  
#include<ctime>  
#include<cstdlib>  
using namespace std;

int main() {
	srand((unsigned)time(NULL));
	int a[10]; //用随机数造一个数组a  
	for (auto &men : a)
		men = rand() % 100;

	int b = 5;
	int c = 9;
	int *p = &b;//左值是一个整型指针，右值是b的地址，这样int型指针p指向了b  

	cout << "p所指对象的值 " << *p << endl;//输出p所指对象的值，也就是b的值  
	cout << "输出指针p的值 " << p << endl;//输出指针p的值，因为p记录了b的地址，所以输出也就是b地址的值  

	p = &c;//重新把p指向c；  
	cout << "输出p所指对象的值,重新指向c，故输出c值 " << *p << endl;//输出p所指对象的值，也就是c的值  

	int &q = c;//表示int型引用p绑定了c，p是c的别名
	cout << "输出q绑定对象c的值 " << q << endl;//间q即见c,此时输出c的值9  

	int *k = a;//这种赋值法只在定义指针时合法。左值须为一个新定义指针，右值须为一个地址，此时为数组a的首元素地址  
	cout << "输出k所指对象的值，即a[0]的值 " << *k << endl;//输出k所指对象的值，也就是a[0]的值  
	int *r;
	r = &b;//正确，左指针，右地址，r指向b
	//*r = &b;//错误，会提示：无法从“int *”转换为“int”
	//*r = a;// 错误，会提示：无法从“int [10]”转换为“int”
	r = a;//正确，左指针，右地址，r指向数组a首地址

	//int *g=b;//错误，右值b为一个整型变量，须为指针，可以改为：  
	//int *g = (int*)b;//运行可能出错，非常危险的操作，  
	//相当于把b的值作为指针g的地址值，若表示一个内存值（如0x113397d8，则赋值后g指向这个地址），  
	//改变g会导致这个地址的对象值发生变化，若这个地址正好是系统关键变量，计算机可能会运行故障。  

	//*k=p;//错误，可以改为下两句：  
	*k = *p;//正确，把p所指对象的值赋给k所指对象的值，*k输出9，但k本身地址值没变  
	k = p;//正确，此时k指向p所指的对象，k和p都指向c，*k输出9，k输出为c的地址  

	getchar();
	return 0;
}
