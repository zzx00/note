#include <iostream>
using namespace std;

//常函数
class Person
{
private:
    /* data */
public:
    int m_a;
    //this指针的本质是指针常量，指针的指向是不可以修改的
    //this指针不可以修改指向，但可以修改指向的值
    //相当于Person * const this，如果值也不想改，可以变成const Person * const this
    //在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void ShowPerson() const {
        //m_a=100;   后面有const就不能修改成员变量
        m_b=100;
        cout<<m_b<<endl;
        m_b=200;
        cout<<m_b<<endl;
    }
    Person(/* args */);
    ~Person();
    mutable int m_b;//特殊变量，即使在常函数中也能被修改加关键字mutable
    void func(){}
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test02(){
    const Person p;//在对象前加const变为常对象
    //不允许修改指针指向的值
    
    //常对象只能调用常函数
    p.ShowPerson();//只能调用常函数
    //p.func();会报错，不允许修改对象的值，不能调用普通的成员函数
}

int main(){
    Person p;
    p.ShowPerson();
}