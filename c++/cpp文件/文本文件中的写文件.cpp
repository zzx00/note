#include <iostream>
#include <fstream>      //头文件
using namespace std;

//文本文件 写文件
void test01(){
    //1.包含头文件
    //2.创建流对象
    ofstream ofs;
    //3.指定打开方式
    ofs.open("test.txt",ios::out);
    //4.写内容
    ofs<<"姓名：张三"<<endl;//endl也好使
    ofs<<"性别：女"<<endl;
    ofs<<"年龄：18"<<endl;
    //5.关闭文件
    ofs.close();
}

int main(){
    test01();
}