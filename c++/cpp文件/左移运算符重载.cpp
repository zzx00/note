#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream &cout,Person p);
private:
    int m_A;
    int m_B;
public:
    Person(int a,int b);
    ~Person();
    
    //不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    //void operator<<(cout);

};

Person::Person(int a,int b)
{
    m_A=a;
    m_B=b;
}

Person::~Person()
{
}

//只能用全局函数重载左移运算符
//函数里面cout可以改成其他名字，因为引用相当于给cout起了别名，实质还是cout
ostream& operator<<(ostream &cout,Person p){//本质 operator (cout,p)   简化为cout<<p
//cout是输出流对象
    cout<<"m_A是："<<p.m_A<<endl<<"m_B是："<<p.m_B<<endl;
    return cout;
}

void test01(){
    Person p(10,10);
    //cout<<p;//后面不能往后加endl了，因为这是调用了一个函数，函数类型是void，如果返回类型仍是cout就能继续加endl了
    cout<<p<<endl;//换成ostream&类型就能继续用了，运用了链式编程思想
}

int main(){
    test01();
}