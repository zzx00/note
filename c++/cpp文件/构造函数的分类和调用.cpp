#include <iostream>
using namespace std;

class Person
{
private:
    int age;
public:
    Person();                   //默认构造函数
    Person(int);                //有参构造函数
    Person(const Person &p){    //拷贝构造函数
        //将当前对象属性拷贝到新对象上
        age=p.age;
        cout<<"拷贝构造函数调用"<<endl;
    }
    ~Person();
};

Person::Person(){
    cout<<"默认构造函数调用"<<endl;
}

Person::Person(int a){
    age=a;
    cout<<"有参构造函数调用"<<endl;
}

Person::~Person(){
}

int main(){
    //括号法
    Person P1;          //默认
    Person p2(10);      //有参
    Person p3(p2);      //拷贝
    //调用默认构造函数时不要加()!加了()编译器会认为是一个函数的声明
    //Person p1();不对

    //显示法
    Person p4;
    Person p5=Person(10);
    Person p6=Person(p2);
    //Person(10)匿名对象   特点：当前行结束后系统会回收 
    //不要用拷贝构造函数初始化匿名对象    编译器会认为Person(P3)==Person p3;
    //Person(p3);重定义

    //隐式转换法
    Person p7=10;       //相当于Person p7=Person(10);
    Person p8=p7;
}
