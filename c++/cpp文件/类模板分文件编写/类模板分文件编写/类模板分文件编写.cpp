#include <iostream>
#include <string>
#include "Person.hpp"
//#include "Person.cpp"//改为.cpp文件
//第一种解决方式：直接包含源文件
using namespace std;

//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀改为.hpp文件（约定）

//ctrl+k+c注释

//类模板分文件编写的问题以及解决

//template<class T1,class T2>
//class Person{
//public:
//	Person(T1 Name, T2 Age);
//	void showPerson();
//	T1 m_Name;
//	T2 m_Age;
//};

//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age){
//	m_Name = name;
//	m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson(){
//	cout << m_Name << ' ' << m_Age << endl;
//}

void test01(){
	Person<string, int>p("Bella", 18);
	p.showPerson();
}


int main(){
	test01();
	system("pause");
}