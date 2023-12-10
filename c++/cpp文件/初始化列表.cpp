#include <iostream>
using namespace std;

class Person
{
private:
    
public:
    int m_a;
    int m_b;
    int m_c;
    // Person(int a,int b,int c){
    //     m_a=a;
    //     m_b=b;
    //     m_c=c;
    // }
    //初始化列表
    Person():m_a(10),m_b(20),m_c(30){}
    Person(int a,int b,int c):m_a(a),m_b(b),m_c(c){}
    ~Person(){}
};

int main(){
    Person p1(30,20,10);
    cout<<p1.m_a<<' '<<p1.m_b<<' '<<p1.m_c<<endl;
}
