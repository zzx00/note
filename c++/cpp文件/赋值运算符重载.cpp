#include <iostream>
using namespace std;

//赋值运算符重载
class Person
{
private:
    /* data */
public:
    Person(int age);
    ~Person();
    int *m_Age;
    Person& operator=(Person &p){//要使用引用
        //编译器提供浅拷贝  m.Age=p.m_Age
        //应该先判断是否有属性在堆区，如果有，先释放干净，然后再深拷贝
        if(m_Age!=NULL){
            delete m_Age;
            m_Age=NULL;
        }
        m_Age=new int(*p.m_Age);
        return *this;
    }
};

Person::Person(int age)
{
    m_Age=new int(age);
}

Person::~Person()
{
    if(m_Age!=NULL){
        delete m_Age;
        m_Age=NULL;
    }
}

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3=p2=p1;
    //直接赋值会出现堆区空间被重复释放的问题，解决方案，利用深拷贝解决浅拷贝的问题
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    cout<<"p3的年龄为："<<*p3.m_Age<<endl;
}


int main(){
    test01();
    // int a=10;
    // int b=20;
    // int c=30;
    // a=b=c;

}
