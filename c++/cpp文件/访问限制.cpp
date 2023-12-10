#include <iostream>
using namespace std;

class person
{
private:
    //私有权限
    int m_password;     //密码
public:
    //公共权限
    string m_name;      //姓名
    void func(){
        m_name="张三";
        m_car="兰博基尼";
        m_password=123456;
        cout<<m_name<<endl<<m_car<<endl<<m_password<<endl;
    }
protected:
    //保护权限
    string m_car;       //车
};

int main(){
    person p1; 
    p1.m_name="zzzzz";
    //p1.m_car="as";保护权限访问不到
    //p1.m_password=23456;私有权限访问不到
    p1.func();
}