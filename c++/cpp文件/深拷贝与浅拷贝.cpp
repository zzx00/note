#include <iostream>
using namespace std;

class Person
{
private:
    
public:
    int m_age;
    int *m_height;
    Person(){
        cout<<"无参构造函数调用！"<<endl;
    }
    Person(int age,int height){
        m_age=age;
        m_height=new int(height);
        cout<<"有参构造函数调用！"<<endl;
    }
    Person(const Person &p){
        cout<<"拷贝构造函数调用！"<<endl;
        m_age=p.m_age;//编译器默认实现

        //深拷贝
        m_height=new int(*p.m_height);
    }
    ~Person(){
        //析构代码，将堆区开辟的数据释放操作
        if(m_height!=NULL){
            delete m_height;
            m_height=NULL;
        }
        cout<<"析构函数调用！"<<endl;
    }
};

void test1(){
    Person p1(18,160);
    cout<<p1.m_age<<' '<<*p1.m_height<<endl;
    Person p2(p1);
    cout<<p2.m_age<<' '<<*p2.m_height<<endl; 
    //如果利用编译器的拷贝构造函数会做浅拷贝操作
    //当调用拷贝构造时会逐字节拷贝，将地址完全复制
    //析构时先释放p2的地址，再释放p1的地址，此时堆区内存m_height会重复释放，引发异常。

}

int main(){
    test1();
}