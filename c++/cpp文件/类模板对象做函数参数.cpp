#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
//类模板对象做函数参数
template<class T1,class T2>
class Person{
public:
    T1 m_Name;
    T2 m_Age;
    Person(T1 name,T2 age){
        m_Name=name;
        m_Age=age;
    }
    void showPerson(){
        cout<<m_Name<<' '<<m_Age<<endl;
    }
};


//1、指定传入参数
void printPerson(Person<string,int>&p){
    p.showPerson();
}

void test01(){
    Person<string,int>p("Monkey",100);
    printPerson(p);
}

template<typename T1,typename T2>
void printPerson2(Person<T1,T2>&p){
    p.showPerson();
    cout<<typeid(T1).name()<<endl;
    cout<<typeid(T2).name()<<endl;
}

//参数模板化
void test02(){
    Person<string,int>p("Pig",1000);
    printPerson2(p);
}

//将整个类模板化
template<class T>
void printPerson3(T &p){
    p.showPerson();
    cout<<typeid(T).name()<<endl;
}

void test03(){
    Person<string,int>p("abc",14);
    printPerson3(p);
}

int main(){
    test01();
    test02();
    test03();
}