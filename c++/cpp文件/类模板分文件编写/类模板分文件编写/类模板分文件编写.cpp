#include <iostream>
#include <string>
#include "Person.hpp"
//#include "Person.cpp"//��Ϊ.cpp�ļ�
//��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
using namespace std;

//�ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ�𣬽���׺��Ϊ.hpp�ļ���Լ����

//ctrl+k+cע��

//��ģ����ļ���д�������Լ����

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