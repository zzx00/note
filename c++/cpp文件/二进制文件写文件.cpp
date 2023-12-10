#include <iostream>
#include <fstream>
using namespace std;

//二进制文件  写文件

class Person{
public:
    char m_Name[64];//姓名
    int m_Age;//年龄
};

void test01(){
    //包含头文件
    //创建流对象
    ofstream ofs;//ofstream ofs("Person.txt",ios::out|ios::binary)
    //打开文件
    ofs.open("Person.txt",ios::out|ios::binary);
    //写文件
    Person p={"张三",18};
    ofs.write((const char*)&p,sizeof(Person));
    //关闭文件
    ofs.close();
}

int main(){
    test01();
}