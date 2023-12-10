#include <iostream>
#include <iomanip>
using namespace std;


void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

struct student
{
    int age;
    string name;
    int score;
};

struct teacher
{
    int id;
    string name;
    int age;
    student stu[100];
};

int *func(){
    int *p=new int(10);
    return p;
}

int main(){
    // int a;
    // long long b;
    // long c;
    // short d;
    // cout<<sizeof(a)<<endl;
    // cout<<sizeof(b)<<endl;
    // cout<<sizeof(c)<<endl;
    // cout<<sizeof(d)<<endl;
    // float a1=3.1415926f;
    // //加f不用从double转化为float
    // double a2=3.1415926;
    // cout<<fixed<<setprecision(6)<<a1<<endl<<a2<<endl;
    // char ch[20];
    // cin>>ch;
    // cout<<ch<<endl;

    // int *p;
    // int a=10;
    // p=&a;
    // cout<<p<<endl;
    // cout<<&a<<endl;
    // cout<<*p<<endl;
    // cout<<a<<endl;
    // int a=10;
    // int *p=&a;
    // cout<<sizeof(p)<<endl;
    // cout<<sizeof(char *)<<endl;
    // cout<<sizeof(double *)<<endl;
    // cout<<sizeof(float *)<<endl;
    // return 0;
    // int *p=NULL;
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // int a=10;
    // int b=10;
    // const int *p=&a;
    // //指针指向可以修改，指针指向的值不能修改
    // p=&b;   //正确  

    // int * const p=&a;
    // //指针的指向不可以改，指针指向的值可以改
    // *p=20;

    // swap(a,b);
    // swap(&a,&b);
    // int *p=func();
    // cout<<*p<<endl;
}