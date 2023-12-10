#include <iostream>
#include <fstream>
using namespace std;

//二进制文件读文件

class Person{
public:
    char m_Name[64];//姓名
    int m_Age;//年龄
};

void test01(){
    ifstream ifs;
    ifs.open("Person.txt",ios::in|ios::binary);
    if(!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    Person p;
    ifs.read((char *)&p,sizeof(p));
    cout<<"姓名："<<p.m_Name<<endl<<"性别："<<p.m_Age<<endl;
    ifs.close();
}

int main(){
    test01();
}