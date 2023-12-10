#include <iostream>

using namespace std;

const double PI=3.1415926;

class circle
{
private://访问权限
    
public:
    double m_r;//属性

    double calculateZC(){//行为
        return 2*PI*m_r;
    }

};


int main(){
    //实例化  通过一个类，创建一个对象的过程
    circle c1;
    c1.m_r=10;
    cout<<"圆周长"<<c1.calculateZC()<<endl;
}