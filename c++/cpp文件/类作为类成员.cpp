#include <iostream>
#include <string>
using namespace std;


class Phone
{
private:
    /* data */
public:
    Phone(string name){
        cout<<"Phone构造函数调用"<<endl;
        p_name=name;
    }
    string p_name;
    ~Phone(){cout<<"Phone析构函数调用"<<endl;}
};




class Person
{
private:
    /* data */
public:
    
    Person(string name,string name2):M_name(name),m_phone(name2){
        //隐式转换法：phone m_phone=name2;
        cout<<"Person构造函数调用"<<endl;
    }
    string M_name;
    Phone m_phone;
    ~Person(){cout<<"Person析构函数调用"<<endl;}
};

void test(){
    Person A("张三","iphone 12");
    cout<<A.M_name<<' '<<A.m_phone.p_name<<endl;
}

int main(){
    test();
}