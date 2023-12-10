# c++提高编程

+ 本阶段主要针对c++==泛型编程==和==STL==技术做详细讲解，探讨c++更深层的使用



## 1 模板

### 1.1 模板的概念

模板就是建立通用的模具，大大提高复用率



模板的特点：

1. 模板只是一个框架，不可以直接使用
2. 模板的通用并不是万能的



### 1.2 函数模板

+ c++另一种编程思想叫做==泛型编程==，主要利用的技术就是模板
+ c++提供两种模板机制：函数模板和类模板



#### 1.2.1 函数模板语法

函数模板作用：

建立一个通用函数，其函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来代表。



语法：

```c++
template<typename T>
函数定义或声明
```

解释：
template ---声明创建模板

typename--- 表明其后面的符号是一种数据类型，可以用class代替

T  -- 通用的数据类型，名称可以替换，通常为大写字母

```c++
#include <iostream>
using namespace std;

//函数模板

//两个整型交换
void SwapInt(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

//交换两个浮点型
void SwapDouble(double &a,double &b){
    double temp=a;
    a=b;
    b=temp;
}

template <typename T>//声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T是一个通用数据类型
void mySwap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

void test01(){
    int a=10;
    int b=20;
    // SwapInt(a,b);
    //利用函数模板进行交换
    //两种方式使用函数模板
    //1、自动类型推导
    mySwap(a,b);
    //2、显式指定类型
    mySwap<int>(a,b);
    cout<<a<<' '<<b<<endl;
}

int main(){
    test01(); 
}
```

将类型参数化

总结：

1. 函数模板使用关键字template
2. 使用函数模板有两种方法：自动类型推导、显示指定类型
3. 模板的目的是为了提高复用性，将类型参数化



#### 1.2.2 函数模板注意事项

注意事项：

+ 自动类型推导必须推导出一致的数据类型T才可以使用
+ 模板必须要确定出T的数据类型，才可以使用



示例：

```c++
#include <iostream>
using namespace std;

//函数模板注意事项
template<typename T>//typename可替换从class
void mySwap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

//1、自动类型推导必须推导出一致的数据类型T才可以使用
void test01(){
    int a=10;
    int b=20;
    char c='c';
    mySwap(a,b);
    //mySwap(a,c);推导不出一致的T
    cout<<a<<' '<<b<<endl;
}

//2、模板必须要确定出T的数据类型，才可以使用
template<typename T>//无法自动类型推导
void func(){
    cout<<"func函数调用"<<endl;
}


void test02(){
    func<int>();
}

int main(){
    test01();
    test02();
}
```

总结：

使用模板时必须确定出通用数据类型T，并且能够推导出一致的数据类型



#### 1.2.3 函数模板案例

案例描述：

利用函数模板封装一个排序的函数，可以对不同类型的数组进行排序

排序规则从大到小，排序算法为选择排序

分别利用char数组和int数组进行测试

```c++
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


template<typename T>
void mySort(T arr[],int len){
    for(int i=0;i<len;i++){
        int max=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]>arr[max]){
                max=j;
            }
        }
        if(max!=i){
            swap(arr[max],arr[i]);
        }
    }
}

template<typename T>
void myPrint(T a[],int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

void test01(){
    char ch[]="asdgnfdsef";
    int a[15]={5,2,6,4,12,67,76453,54,75,7452,4,1,0,1,0};
    mySort(ch,strlen(ch));
    myPrint(ch,strlen(ch));
    mySort(a,15);
    myPrint(a,15);
}

int main(){
    test01();
}
```

#### 1.2.4 普通函数与函数模板区别

**普通函数与函数模板区别：**

+ 普通函数调用时可以发生自动类型转换（隐式类型转换）
+ 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
+ 如果利用显示指定类型的方式，可以发生隐式类型转换



#### 1.2.5 普通函数与函数模板调用规则

调用规则如下：

1. 如果函数模板和普通函数都可以实现，优先普通函数
2. 可以通过空模板参数列表来强调调用函数模板
3. 函数模板也可以发生重载
4. 如果函数模板可以产生更好的匹配，优先函数模板

```c++
#include <iostream>
using namespace std;

//普通函数与函数模板调用规则
void myPrint(int a,int b){
    cout<<"PuTong"<<endl;
}

template<typename T>
void myPrint(T a,T b){
    cout<<"MuBan"<<endl;
}

template<typename T>
void myPrint(T a,T b,T c){
    cout<<"ChongZaiMuBan"<<endl;
}

void test01(){
    int a=10;
    int b=20;
    myPrint(a,b);

    //通过空模板的参数列表，强制调用函数模板
    myPrint<>(a,b,100);

    //如果函数模板产生更好的匹配，优先函数模板
    char c1='a';
    char c2='c';
    myPrint(c1,c2);
}

int main(){
    test01();
}
```

总结：

如果提供了函数模板，就不要提供普通函数，否则容易产生二义性



#### 1.2.6 模板的局限性

局限性：

+ 模板的通用性并不是万能的

```c++
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    int age;
    string name;
    Person(int a,string b){
        age=a;
        name=b;
    }
};

//对比两个数据是否相等函数
template<typename T>
bool cmp(T &a,T &b){
    if(a==b){
        return true;
    }
    return false;
}

//利用具体化Person的版本实现代码，具体化会优先调用
template<> bool cmp(Person &a,Person &b){
    if(a.age==b.age&&a.name==b.name){
        return true;
    }
    return false;
}

void test01(){
    int a=10,b=20;
    cout<<cmp(a,b)<<endl;
}

void test02(){
    Person p1(10,"Tom");
    Person p2(10,"Tom");
    cout<<cmp(p1,p2)<<endl;
}

int main(){
    test01();
    test02();
}
```

总结：

+ 利用具体化的模板，可以解决自定义类型的通用化
+ 学习模板并不是为了写模板，而是在STL能够运用系统给的模板



### 1.3 类模板

#### 1.3.1 类模板语法

类模板作用：

+ 建立一个通用类，类中的成员数据类型可以不具体指定，用一个虚拟的类型来代表



语法：

```c++
template<typename T>
类
```

解释：

template--声明创建模板

typename--表明其后面的符号是一种数据类型，可以用class代替

T -- 通用数据类型，名称可以替换，通常为大写字母

```c++
#include <iostream>
#include <string>
using namespace std;

//类模板
//template<class NameType,class AgeType>
template<class NameType,class AgeType=int>
class Person{
public:
    Person(NameType name,AgeType age){
        m_name=name;
        m_age=age;
    }
    NameType m_name;
    AgeType m_age;
    void showPerson(){
        cout<<m_name<<' '<<m_age<<endl;
    }

};
//1、类模板没有自动类型推导的使用方式
void test01(){
    //Person p("孙悟空",18);错误，无法自动类型推导，只能显式指定类型
    Person<string,int>p("Monkey",1000);
    p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
void test02(){
    Person<string>p("pig",999);
    p.showPerson();
}
int main(){
    test01();
    test02();
}
```

总结：

+ 类模板使用只能用指定类型方式
+ 类模板中的模板参数列表可以有默认参数



#### 1.3.3 类模板中的成员函数创建时机

类模板中成员函数和普通类中的成员函数创建时机有区别：

+ 普通类中的成员函数一开始就可以创建
+ 类模板中的成员函数在调用时才创建



总结：

+ 类模板中的成员函数并不是一开始就创建的，在调用时才去创建



#### 1.3.4 类模板对象做函数参数

学习目标：

+ 类模板实例化出的对象，向函数传参的方式



一共有三种传入方式：

1. 指定传入的类型  --直接显示对象的数据类型
2. 参数模板化         --将对象中的参数变为模板进行传递
3. 整个类模板化      --将这个对象类型 模板化传递

示例：

```c++
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
//类模板对象做函数参数
template<class T1,class T2>
class Person{
public:
    T1 m_Name;
    T2 m_Age;
    Person(T1 name,T2 age){
        m_Name=name;
        m_Age=age;
    }
    void showPerson(){
        cout<<m_Name<<' '<<m_Age<<endl;
    }
};


//1、指定传入参数
void printPerson(Person<string,int>&p){
    p.showPerson();
}

void test01(){
    Person<string,int>p("Monkey",100);
    printPerson(p);
}

template<typename T1,typename T2>
void printPerson2(Person<T1,T2>&p){
    p.showPerson();
    cout<<typeid(T1).name()<<endl;
    cout<<typeid(T2).name()<<endl;
}

//参数模板化
void test02(){
    Person<string,int>p("Pig",1000);
    printPerson2(p);
}

//将整个类模板化
template<class T>
void printPerson3(T &p){
    p.showPerson();
    cout<<typeid(T).name()<<endl;
}

void test03(){
    Person<string,int>p("abc",14);
    printPerson3(p);
}

int main(){
    test01();
    test02();
    test03();
}
```

总结：

+ 通过类模板创建的对象，有三种方式向函数中进行传参
+ 使用比较广泛的是第一种，指定传入的类型



#### 1.3.5 类模板与继承

当类模板碰到继承时，要注意以下几点：

+ 当子类继承的父类是一个类模板时，子类在声明时要指出父类中T的类型
+ 如果不指定，编译器无法给子类分配内存
+ 如果想灵活指出父类中的T的类型，子类也需要变为类模板

```c++
#include <iostream>
#include <typeinfo>
using namespace std;

template<class T>
class Base{
public:
    T m;
};

//class Son:public Base{//错误，必须要知道父类中的T的类型，才能继承给子类
class Son:public Base<int>{

};


//如果想灵活指定父类中T的类型，子类也需要变类模板
template<class T1,class T2>
class Son2:public Base<T2>{
public:
    T1 obj;
    Son2(){
        cout<<typeid(T1).name()<<endl<<typeid(T2).name()<<endl;
    }
};

void test02(){
    Son2<int,char>S2;
}

void test01(){
    Son s1;
}

int main(){
    test01();
    test02();
}
```

总结：如果父类是类模板，子类需要制定出父类中T的数据类型



#### 1.3.6 类模板成员函数的类外实现

学习目标：能够掌握类模板中成员函数类外实现



```c++
#include <iostream>
#include <string>
using namespace std;

template<class T1,class T2>
class Person{
public:
    T1 m_Name;
    T2 m_Age;
    Person(T1 name,T2 age);
    void showPerson();

};

//构造函数类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age){
    m_Name=name;
    m_Age=age;
}

//成员函数类外实现
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout<<m_Name<<' '<<m_Age<<endl;
}

void test01(){
    Person<string,int>p("Bella",18);
    p.showPerson();
}

int main(){
    test01();
}
```



#### 1.3.7 类模板分文件编写

问题：

+ 类模板中成员函数创建时机是在调用阶段，导致分文件编写链接不到

解决：

+ 解决方式1：直接包含.cpp文件
+ 解决方式2：将声明和实现写到同一个文件中，并改后缀名为.hpp，hpp是约定的名称，并不是强制



总结：主流的解决方法是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp





#### 1.3.8 类模板与友元

学习目标：

+ 掌握类模板配合友元函数的类内和类外实现

全局函数类内实现--直接在类内声明友元即可

全局函数类外实现--需要提前让编译器知道全局函数的存在



```c++
#include <iostream>
#include <string>

using namespace std;

template<class T1,class T2>
class Person;

template<class T1,class T2>
void printPerson(Person<T1,T2> p){
    cout<<p.m_Name<<' '<<p.m_Age<<endl;
}


template<class T1,class T2>
class Person{
    //全局函数类内实现
    // friend void printPerson(Person<T1,T2> p){
    //     cout<<p.m_Name<<' '<<p.m_Age<<endl;
    // }
    //全局函数类外实现
    //加空模板参数列表
    //如果全局函数类外实现，需要让编译器提前知道这个函数存在
    friend void printPerson<>(Person<T1,T2> p);
public:
    Person(T1 name,T2 age){
        this->m_Name=name;
        this->m_Age=age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};

//通过全局函数打印Person的信息
void test01(){
    Person<string,int>p("Bella",18);
    printPerson(p);
    
}

// template<class T1,class T2>
// void printPerson(Person<T1,T2> p){
//     cout<<p.m_Name<<' '<<p.m_Age<<endl;
// }

int main(){
    test01();
}
```

比较绕

总结：

+ 建议全局函数做类内实现，用法简单，而且编译器可以直接识别