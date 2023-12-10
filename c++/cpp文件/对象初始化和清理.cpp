#include <iostream>
using namespace std;

//构造函数   进行初始化操作
//析构函数   进行清理的操作
class Person
{
private:
    /* data */
public:
    Person(){
        cout<<1<<endl;
    }      
    ~Person(){
        cout<<2<<endl;
    }
};

int main(){
    Person p;       //栈上的数据
}