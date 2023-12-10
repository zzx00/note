#include <iostream>

using namespace std;

//继承中的对象模型

class Base
{
private:
    int m_C;
public:
    int m_A;
protected:
    int m_B;
};


class Son : public Base{
public:
    int m_D;
};

void test01(){
    Son s1;
    cout<<sizeof(s1)<<endl;
    //16
    //父类中所有的非静态成员属性都会被子类继承下去
    //父类中私有的成员属性是被编译器隐藏了，因此是访问不到，但是确实被继承下去了

    //利用开发人员命令提示工具查看对象模型
    //跳转盘符，跳到当前硬盘下
    //跳转文件路径 cd具体路径下
    //查看命令 cl /d1 reportSingleClassLayout类名 文件名

}

int main(){
    test01();
}