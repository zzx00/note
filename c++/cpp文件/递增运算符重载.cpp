#include <iostream>
using namespace std;

//重载递增运算符

//自定义整型
class MyInteger
{
    friend ostream& operator<<(ostream &cout,MyInteger m);
private:
    int m_num;
public:
    MyInteger(){
        m_num=0;
    }
    ~MyInteger();
    //重载前置++运算符
    MyInteger& operator++(){//使用引用返回的是自身，不是拷贝构造函数创造的新对象
    //返回引用是为了一直对一个数据进行操作
    //先进行++运算，再将自身返回
        m_num++;
        return *this;
    }

//重载后置++运算符
MyInteger operator++(int){   //int代表占位参数，可以用于区分前置和后置递增
//先记录当时的结果
    MyInteger temp=*this;
//然后进行递增
    this->m_num++;
//最后返回原来的结果
    return temp;//我们返回的是局部对象的值，所以返回类型不能是引用，要不然后面就是非法操作了
}    
};


ostream& operator<<(ostream &cout,MyInteger m){
    cout<<m.m_num<<endl;
    return cout;
}


MyInteger::~MyInteger()
{
}

void test01(){
    MyInteger m;
    cout<<++m;
    cout<<m;
    //注意这里不能两个连着写，不然会错，分开输出的对的
}

void test02(){
    MyInteger m;
    cout<<m++;
    cout<<m;
    //后置递增不能连续写，比如(m++)++
}

//前置递增返回引用，后置递增返回值
int main(){
    test01();
    test02();
}