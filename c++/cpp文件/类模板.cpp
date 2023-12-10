#include <iostream>
#include <string>
using namespace std;

//类模板
//template<class NameType,class AgeType>
template<class NameType,class AgeType=int>
class Person{
public:
    Person(NameType name,AgeType age){
        m_name=name;
        m_age=age;
    }
    NameType m_name;
    AgeType m_age;
    void showPerson(){
        cout<<m_name<<' '<<m_age<<endl;
    }

};
//1、类模板没有自动类型推导的使用方式
void test01(){
    //Person p("孙悟空",18);错误，无法自动类型推导，只能显式指定类型
    Person<string,int>p("Monkey",1000);
    p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
void test02(){
    Person<string>p("pig",999);
    p.showPerson();
}
int main(){
    test01();
    test02();
}