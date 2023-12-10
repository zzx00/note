# c++核心编程



## 1内存分区模型

c++程序在执行时，将内存大方向分为**4个区域**

+ 代码区：存放函数体的二进制代码，由操作系统进行管理的
+ 全局区：存放全局变量和静态变量以及常量
+ 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
+ 堆区：由程序员分配和释放，若程序员不释放，程序结束后由操作系统回收



意义：不同区域存放的数据，赋予不同的生命周期，给更大的灵活性



### 1.1程序运行前

在程序编译后，生成了exe可执行程序，**未执行该程序前**分为两个区域

**代码区：**

​				存放CPU执行的机器指令

​				代码区是共享的，共享的目的是对于频繁被执行的程序，只需要内存中有一份代码即可

​				代码区是**只读**的，防止程序意外修改它的指令

**全局区：**

​				全局变量和静态变量存放在此

​				全局区还包含了常量区，字符串常量和其他常量也存放在此

​				**常量区包括const修饰的全局变量和字符串常量**

> 在普通变量前加static变成静态变量
>
> 常量有字符串常量和const修饰的变量
>
> const修饰的全局变量在全局区，const修饰的局部变量**不在全局区，和局部变量放在一起**

​				==该区域的数据在程序结束后由操作系统释放==

> 打印全局变量的地址和局部变量的地址隔了好多
>
> 但同是全局变量或全是局部变量的地址相隔不远





### 1.2程序运行后



**栈区：**

+ 由编译器自动分配释放，存放函数的参数值、局部变量等。
+ 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

~~~c++
int *func(){
	int a=10;
    return &a;
}

int main(){
	int *p=func();
    cout<<*p<<endl;
    cout<<*p<<endl;
    //第一行输出10，第二行输出随机地址
    //第一次没有清是因为编译器做了保留，第二次就不再保留了
}
~~~



**堆区：**

​				由程序员分配释放，若程序员不释放，程序结束后由操作系统回收

​				在c++中主要利用new在堆区开辟内存

~~~c++
int *func(){
    int *p=new int(10);
    return p;
}

    int *p=func();
    cout<<*p<<endl;
//不管打印多少遍都是10，只要不销毁
~~~



### 1.3new关键字

c++中利用==new==操作符在堆区开辟数据

堆区开辟的数据，由程序员手动开辟，手动释放，释放使用操作符==delete==

语法：new 数据类型

使用new创建的数组，会返回该数据对应类型的指针

~~~c++
int* func(){
	int *a=new int (10);		//存放一个变量，变量的值为10
    return a;
}
int main(){
	int *p=func();
    cout<<*p<<endl;
    int *a=new[10];//创建数组，返回首地址，有10个元素
    //使用方法和正常数组一样
    delete[] a;//释放数组的时候要加[]
}
~~~



##2引用

### 2.1引用的基本使用



**作用**：给变量起别名

语法：==数据类型 &别名 = 原名==



~~~c++
#include <iostream>

using namespace std;

int main(){
    int a=10;
    int &b=a;
    cout<<a<<endl;
    cout<<b<<endl;
    b=100;
    cout<<a<<endl;
    cout<<b<<endl;
    //值将改变，全变成100
    //a和b操作的是同一块内存
    return 0;
}
~~~



### 2.2引用注意事项

+ 引用必须初始化
+ 引用在初始化后，不可以改变

~~~c++
#include <iostream>

using namespace std;

int main(){
    int a=10;
    int b=20;
    //int &c;
    //不能这样写，引用必须初始化
    int &c=a;
    c=b;
    //这是赋值运算，不是更改引用
    //引用一旦初始化后不可以更改
    return 0;
}
~~~



### 2.3引用做函数参数



作用：函数传参时，可以利用引用使形参修饰实参

优点：可以简化指针修改实参。



~~~c++
#include <iostream>

using namespace std;

//引用传递
void swap1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

//值传递
void swap2(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

//地址传递
void swap3(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int a=10,b=20;
    swap1(a,b);
    cout<<a<<' '<<b<<endl;
    swap2(a,b);
    cout<<a<<' '<<b<<endl;
    swap3(&a,&b);
    cout<<a<<' '<<b<<endl;
    return 0;
}

20 10
20 10
10 20
~~~



### 2.4引用做函数返回值

作用：引用是可以作为函数返回值的



注意：**不要返回局部变量引用**

用法：函数调用作为左值



~~~c++
#include <iostream>

using namespace std;

int& test01(){
    int a=10;   //存放在栈区
    return a;
}

int& test02(){
    static int a=10;   //静态变量，存放在全局区，程序结束后系统释放
    return a;
}

int main(){

    int& ref=test01();
    cout<<ref<<endl;		//第一次输出正确是因为编译器做了保留
    cout<<ref<<endl;		//第二次结果错误，因为内存被释放
    
    int& ref2=test02();
    cout<<ref2<<endl;		
    cout<<ref2<<endl;		//输出不会错误
    
    test02()=1000;			//相当于对a赋值1000
    cout<<ref2<<endl;		//ref2是别名，也能访问到这块内存
    cout<<ref2<<endl;		//函数调用可作为左值
    return 0;
}

10
0
10
10
1000
1000
~~~



### 2.5引用的本质

本质：**引用的本质在c++内部实现是一个指针常量**

![image-20201205162347230](C:\Users\z'z'x\AppData\Roaming\Typora\typora-user-images\image-20201205162347230.png)



## 3函数提高

### 3.1函数默认参数



在c++中，函数的形参列表中的形参是可以有默认值的

语法： 返回值类型  函数名（参数=默认值）{}

~~~c++
#include <iostream>
using namespace std;

int func(int a,int b=10,int c=10){
    return a+b+c;
}

//如果某个位置有了默认参数，那么从这个位置往后，从左到右都必须有默认参数
//int func(int a,int b=10,int c){}这样不行


//如果函数声明有默认参数，那么函数的实现不能有默认参数
// int func(int a=10,int b=10);

// int func(int a=10,int b=10){
//     return a+b;
// }
//不行


int main(){
    cout<<func(20)<<endl;
    return 0;
}
~~~



### 3.2函数占位参数

c++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置。

语法： 返回值类型  函数名  （数据类型）{}

占位参数还可以有默认参数

~~~c++
#include <iostream>
using namespace std;

void func(int a,int){
    cout<<"函数被调用"<<endl;
}

int main(){
    func(20,10);
    return 0;
}
~~~



### 3.3函数重载

#### 3.3.1函数重载概述

作用：函数名可以相同，提高复用性



函数重载满足条件：

+ 同一个作用域下
+ 函数名称相同
+ 函数参数**类型不同**或者**个数不同**或者**顺序不同**



==注意：函数的返回值不可以作为函数重载的条件==



~~~c++
#include <iostream>
using namespace std;

void func(int a){
    cout<<"func1"<<endl;
}

void func(double a){
    cout<<"func2"<<endl;
}

void func(int a,double b){
    cout<<"func3"<<endl;
}

void func(double b,int a){
    cout<<"func4"<<endl;
}
//函数的返回值不可以作为函数重载条件

int main(){
    func(1);
    func(3.14);
    func(1,3.14);
    func(3.14,1);
    return 0;
}
~~~



#### 3.3.2函数重载注意事项

+ 引用作为重载条件
+ 函数重载碰到函数默认参数



~~~c++
#include <iostream>
using namespace std;
//引用作为重载条件
void func(int &a){
    cout<<"func1"<<endl;
}

void func(const int &a){
    cout<<"func5"<<endl;
}


int main(){
    int b=10;//变量意味着可读可写
    func(b);
    const int c=10;
    func(c);
    func(10);//直接输入值就行，定义一个const int类型数据
    return 0;
}

func1
func5
func5
~~~



**函数重载尽量不要加默认参数**

~~~c++
#include <iostream>
using namespace std;


void func2(int a){
    cout<<"func2"<<endl;
}

void func2(int a,int b=10){
    cout<<"func2"<<endl;
}

int main(){
    //func2(10);
    //出错，两个都可以调进去，产生二义性
    return 0;
}
~~~



## 4类和对象



**c++面向对象三大特征：==封装、继承、多态==**



**c++认为==万事万物皆为对象==，对象上有其属性和行为**



例如：

人可以作为对象，人有姓名，年龄，性别···，行为有走，跑，跳···

**具有相同性质的==对象==，可以抽象为==类==**

###4.1封装

#### 4.1.1封装的意义

**封装是c++面向对象三大特征之一**

封装的意义：

+ 将属性和行为作为一个整体，表现生活中的事物
+ 将属性和行为加以权限控制

**封装意义一：**

​		在设计类的时候，属性和行为写在一起，表现事物

语法：class 类名{ 	访问权限:	属性 	/	行为};



示例：设计一个圆类，求圆的周长

~~~c++
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
~~~



示例：写一个学生类，能显示姓名和学号

~~~c++
#include <iostream>

using namespace std;

class student
{
private:
    string s_name;
    int s_age;
public:
    void showname(){
        cout<<s_name<<endl;
    }
    void showage(){
        cout<<s_age<<endl;
    }
    void getname(string name){
        s_name=name;
    }
    void getage(int age){
        s_age=age;
    }
    
};


int main(){
    student stu1;
    stu1.getage(20);
    stu1.getname((string)"aaa");
    stu1.showage();
    stu1.showname();
}
~~~

**类中的属性和行为统一称为==成员==**

属性  成员属性   成员变量

行为  成员函数   成员方法





**封装意义二：**

类在设计时，可以把属性和行为放在不同的权限下，加以控制



访问权限有三种：

+ public 		公共权限       类内可以访问，类外也可以访问
+ protected  保护权限       类内可以访问，类外不能访问，子类继承后可以访问父类保护内容
+ private       私有权限       类内可以访问，类外不能访问，子类继承后不可以访问父类私有内容



示例：

~~~c++
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
~~~



#### 4.1.2struct和class区别

在c++中struct和class唯一的区别就在于**默认的访问权限不同。**

区别：

+ struct默认权限为公共
+ class默认权限为私有

~~~c++
#include <iostream>
using namespace std;

class c1{
    int m_a;//默认为私有
};

struct c2{
    int m_a;//默认为公共
};

int main(){
    c1 c;
    c2 b;
    //c.m_a=1;不能访问，为私有
    b.m_a=1;
}
~~~

#### 4.1.3将成员属性设置为私有

​	优点1：将所有成员设置成私有，可以自己控制读写权限。

​	优点2：对于写权限，我们可以检测数据的有效性

~~~c++
#include <iostream>

using namespace std;

class person
{
private:
    //可读可写
    string _name;

    //可读可写  若写范围为0~150
    int _age;
public:
    void setname(string name){
        _name=name;
    }
    string getname(){
        return _name;
    }
    int getage(){
        return _age;
    }
    void setage(int age){
        if(age>0&&age<150){
            _age=age;
        }else{
            _age=0;
            cout<<"error"<<endl;
            return;
        }
    }
};

int main(){
    person p1;
    p1.setname("aaa");
    cout<<p1.getname()<<endl;
    p1.setage(3000);
    p1.setage(20);
    cout<<p1.getage()<<endl;
}
~~~



### 4.2对象的初始化和清理

 #### 4.2.1构造函数和析构函数

对象的**初始化和清理**也是两个重要的安全问题

​		一个对象或者变量没有初始状态，对其使用后果是未知的。

​		同样使用完一个对象或变量，没有及时清理，也会造成一定的安全问题。



c++利用了**构造函数**和**析构函数**解决上述问题，会自动调用，完成对象的初始化和清理工作。



对象的初始化和清理工作是编译器强制我们进行的事，如果**我们不提供构造函数和析构函数，编译器会提供**

**编译器提供的构造函数和析构函数是空实现。**



+ 构造函数：主要作用是在创建对象时为对象的成员赋值，构造函数由编译器自动调用，无需手动调用。
+ 析构函数：主要作用于对象==**销毁前**==自动调用，执行清理工作。



**构造函数语法**：类名() {}

1. 构造函数没有返回值也不写void
2. 函数名称和类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象的时候会自动调用构造，无需手动调用，并且指==只会调用一次==



**析构函数语法：** ~类名() {}

1. 析构函数，没有返回值也不写void
2. 函数名称与类名相同，在名称前面加上符号~
3. 析构函数不可以有参数，因此不能发生重载
4. 程序在对象销毁前会自动调用析构函数，无需手动调用，而且只会调用一次

~~~c++
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
~~~



####4.2.2构造函数的分类和调用

两种分类方法：

1. 按参数分为：有参构造和无参构造
2. 按类型分为：普通构造和拷贝构造

三种调用方式：

+ 括号法
+ 显示法
+ 隐式转换法

~~~c++
#include <iostream>
using namespace std;

class Person
{
private:
    int age;
public:
    Person();                   //默认构造函数
    Person(int);                //有参构造函数
    Person(const Person &p){    //拷贝构造函数
        //将当前对象属性拷贝到新对象上
        age=p.age;
        cout<<"拷贝构造函数调用"<<endl;
    }
    ~Person();
};

Person::Person(){
    cout<<"默认构造函数调用"<<endl;
}

Person::Person(int a){
    age=a;
    cout<<"有参构造函数调用"<<endl;
}

Person::~Person(){
}

int main(){
    //括号法
    Person P1;          //默认
    Person p2(10);      //有参
    Person p3(p2);      //拷贝
    //调用默认构造函数时不要加()!加了()编译器会认为是一个函数的声明
    //Person p1();不对

    //显示法
    Person p4;
    Person p5=Person(10);
    Person p6=Person(p2);
    //Person(10)匿名对象   特点：当前行结束后系统会回收 
    //不要用拷贝构造函数初始化匿名对象    编译器会认为Person(P3)==Person p3;
    //Person(p3);重定义

    //隐式转换法
    Person p7=10;       //相当于Person p7=Person(10);
    Person p8=p7;
}
~~~



#### 4.2.3拷贝构造函数的调用时机

c++中拷贝构造函数的调用时机通常有三种情况：

+ 使用一个已经创建完毕的对象来初始化一个新对象
+ 值传递的方式给函数参数传值
+ 以值方式返回局部对象

~~~c++
#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    int m_age; 
    Person(){
        cout<<"调用默认构造函数"<<endl;
    }
    Person(int age){
        m_age=age;
        cout<<"调用有参构造函数"<<endl;
    }
    Person(const Person &p){
        m_age=p.m_age;
        cout<<"调用拷贝构造函数"<<endl;
    }
    ~Person(){
        cout<<"调用析构函数"<<endl;
    }
};

void test(Person p){
}

Person test2(){
    Person p1;
    cout<<(int *)&p1<<endl;
    return p1;
}

int main(){
    Person p1=20;
    Person p2(p1);
    cout<<p2.m_age<<endl;
    test(p1);               //调用拷贝构造函数进行值传递，如果不写系统也有拷贝构造函数
    Person p3=test2();      //没有拷贝构造可能用了release模式，相当于局部变量没有销毁，正常应该会调用拷贝构造函数
    cout<<(int *)&p3<<endl;
}
~~~

#### 4.2.4构造函数的调用规则

默认情况下，c++编译器至少给一个类添加3个函数

1. 默认构造函数
2. 默认析构函数
3. 默认拷贝函数，对属性进行拷贝



构造函数调用规则如下：

+ 如果用户定义有参构造函数，c++不再提供默认无参构造，但会提供默认拷贝构造
+ 如果用户定义拷贝构造函数，c++不会再提供其他构造函数

~~~c++
#include <iostream>
using namespace std;

class Person{
private:
    
public:
int m_age;
    Person(){
        cout<<"默认构造函数"<<endl;
    }
    Person(int a){
        m_age=a;
        cout<<"有参构造函数调用"<<endl;
    }
    Person(const Person &p){
        m_age=p.m_age;
        cout<<"调用拷贝构造函数"<<endl;
    }
    ~Person(){
        cout<<"析构函数调用"<<endl;
    }
};

void test(){
    Person p=18;
    Person p2=p;
    cout<<p2.m_age<<endl;
}

int main(){
    test();
}
~~~



#### 4.2.5深拷贝与浅拷贝

浅拷贝：简单的复制拷贝操作

深拷贝：在堆区重新申请空间，进行拷贝操作



~~~c++
//错误代码
#include <iostream>
using namespace std;

class Person
{
private:
    
public:
    int m_age;
    int *m_height;
    Person(){
        cout<<"无参构造函数调用！"<<endl;
    }
    Person(int age,int height){
        m_age=age;
        m_height=new int(height);
        cout<<"有参构造函数调用！"<<endl;
    }
    ~Person(){
        //析构代码，将堆区开辟的数据释放操作
        if(m_height!=NULL){
            delete m_height;
            m_height=NULL;
        }
        cout<<"析构函数调用！"<<endl;
    }
};

void test1(){
    Person p1(18,160);
    cout<<p1.m_age<<' '<<*p1.m_height<<endl;
    Person p2(p1);
    cout<<p2.m_age<<' '<<*p2.m_height<<endl; 
    //如果利用编译器的拷贝构造函数会做浅拷贝操作
    //当调用拷贝构造时会逐字节拷贝，将地址完全复制
    //析构时先释放p2的地址，再释放p1的地址，此时堆区内存m_height会重复释放，引发异常。

}

int main(){
    test1();
}
~~~

~~~c++
//解决代码  浅拷贝的问题要利用深拷贝解决
#include <iostream>
using namespace std;

class Person
{
private:
    
public:
    int m_age;
    int *m_height;
    Person(){
        cout<<"无参构造函数调用！"<<endl;
    }
    Person(int age,int height){
        m_age=age;
        m_height=new int(height);
        cout<<"有参构造函数调用！"<<endl;
    }
    Person(const Person &p){
        cout<<"拷贝构造函数调用！"<<endl;
        m_age=p.m_age;//编译器默认实现

        //深拷贝
        m_height=new int(*p.m_height);
    }
    ~Person(){
        //析构代码，将堆区开辟的数据释放操作
        if(m_height!=NULL){
            delete m_height;
            m_height=NULL;
        }
        cout<<"析构函数调用！"<<endl;
    }
};

void test1(){
    Person p1(18,160);
    cout<<p1.m_age<<' '<<*p1.m_height<<endl;
    Person p2(p1);
    cout<<p2.m_age<<' '<<*p2.m_height<<endl; 
    //如果利用编译器的拷贝构造函数会做浅拷贝操作
    //当调用拷贝构造时会逐字节拷贝，将地址完全复制
    //析构时先释放p2的地址，再释放p1的地址，此时堆区内存m_height会重复释放，引发异常。

}

int main(){
    test1();
}
~~~

==**如果有属性在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题**==



#### 4.2.6初始化列表

作用：c++提供了初始化列表语法，用来初始化属性

语法：构造函数() : 属性1(值1),属性2(值2),属性3(值3)······{}

~~~c++
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
~~~

#### 4.2.7类对象作为类成员

c++类中的成员可以是另一个类的对象，我们称该成员为对象成员。

~~~c++
class A{}
class B{
    A a;
}
~~~



B类中有对象A作为成员，A为对象成员。



问：当创建B对象时，A与B的构造和析构顺序是怎么样的 ？

~~~c++
#include <iostream>
#include <string>
using namespace std;


class Phone
{
private:
    /* data */
public:
    Phone(string name){
        cout<<"Phone构造函数调用"<<endl;
        p_name=name;
    }
    string p_name;
    ~Phone(){cout<<"Phone析构函数调用"<<endl;}
};




class Person
{
private:
    /* data */
public:
    
    Person(string name,string name2):M_name(name),m_phone(name2){
        //隐式转换法：phone m_phone=name2;
        cout<<"Person构造函数调用"<<endl;
    }
    string M_name;
    Phone m_phone;
    ~Person(){cout<<"Person析构函数调用"<<endl;}
};

void test(){
    Person A("张三","iphone 12");
    cout<<A.M_name<<' '<<A.m_phone.p_name<<endl;
}

int main(){
    test();
}

Phone构造函数调用
Person构造函数调用
张三 iphone 12
Person析构函数调用
Phone析构函数调用
~~~

**当其他类对象作为本类成员，构造的时候先构造类对象，再构造本身。**

==**析构顺序与构造函数顺序相反**==





#### 4.2.8静态成员

静态成员就是在成员变量和成员函数前加上static关键字，成为静态成员

静态成员分为：

+ 静态成员变量
  + 所有对象共享一份数据
  + 在编译阶段分配内存
  + 类内声明，类外初始化 
+ 静态成员函数
  + 所有对象共享同一个函数
  + 静态成员函数只能访问静态成员变量

~~~c++
#include <iostream>
using namespace std;

class Person
{
private:
    static int m_b;
public:
    static int m_a;
    //所有对象共享同一份数据
    //编译阶段就分配内存
    //类内声明，类外初始化
};

void test(){
    Person p;
    cout<<p.m_a<<endl;
    //修改，数据共享
    Person p2;
    p2.m_a=200;
    cout<<p2.m_a<<endl;
}

int Person::m_a=100;
int Person::m_b=200;
void test2(){
    //静态成员变量，不属于某个对象上，所有对象共享同一份数据

    //两种访问方式
    //1、通过对象访问
    Person p;
    cout<<p.m_a<<endl;
    //2、通过类名进行访问
    cout<<Person::m_a<<endl;

    //cout<<Person::m_b<<endl;  访问不到私有的
}

int main(){

    //test();
    test2();
}
~~~



### 4.3 C++对象模型和this指针



#### 4.3.1 成员变量和成员函数分开存储

在c++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上

其他的只有一份，不属于类的对象上

```c++
#include <iostream>
using namespace std;

//成员变量和成员函数是分开存储的
class Person
{
private:
    
public:
    //只有非静态成员变量属于类的对象
    int m_A;//非静态成员变量
    static int m_B;//静态成员变量不属于类的对象上，所以类内占用空间不变
    void func(){}   //非静态成员函数，不属于类的对象
    static void func2(){} //静态成员函数也只有一份，不属于类的对象上

    Person(/* args */);
    ~Person();
};

//类内声明类外初始化
int Person::m_B=0;

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01(){
    Person p;
    //空对象占用的内存空间是1个字节
    //c++编译器会为每个空对象也分配一个字节空间，是为了区分空对象所占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout<<sizeof(p)<<endl;
}

void test02(){
    Person p;
    //不是空的就按实际大小占用内存
    cout<<sizeof(p)<<endl;
}

int main(){
    //test01();
    test02();
    return 0;
}
```



#### 4.3.2 this指针概念

通过4.3.1我们知道在c++中成员变量和成员函数是分开存储的

每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

那么问题是：这一块代码是如何区分哪个对象调用自己呢？（多个对象使用这个函数，怎么区分是哪个对象调用的）



c++通过提供特殊的对象指针，this指针，解决上述问题，==**this指针指向被调用的成员函数所属的对象**==（**谁调用指向谁**）



this指针是**隐含**每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可



this指针的用途：

+ 当形参和成员变量同名时，可用this指针来区分
+ 在类的非静态成员函数中返回对象本身，可使用return *this

==**重要**==

```c++
#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int age;
    Person(int age){//成员函数中会认为这三个age是一样的，和成员变量中的age没关系
        this->age=age;//加上this中会把这两个age看成一样的，this->age和成员变量中age一样
        //this指针指向的是被调用的成员函数所使用的对象
    }
    ~Person();
    Person& PersonAddPerson(Person &p){//记得加&，用引用的方式做一个返回
    //如果不加&的话认为调用了拷贝构造函数，出了一个副本
    //p2.PersonAddPerson(p1)成为p2',p2.PersonAddPerson(p1).PersonAddPerson(p1)成为p2''
    //p2.age是20，p2''.age是30，相当于p2'和p2''参与了后面的运算，而不是p2
        this->age+=p.age;
        //this指向的是一个p2的指针，*this指向的就是p2本体
        return *this;
    }
};


Person::~Person()
{
}
//解决名称冲突
void test01(){
    Person p1(18);
    cout<<p1.age<<endl;
    return ;
}


//返回对象本身用*this
void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    //如果想多次调用的话p2.PersonAddPerson(p1).PersonAddPerson(p1);不行，因为返回值是void
    //但如果返回值是p2类型就可以
    cout<<p2.age<<endl;
}

int main(){
    test01();
    test02();
}
```



####4.3.3 空指针访问成员函数

c++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

如果用到this指针，需要加以判断代码的健壮性，**可能会有坑**

```c++
#include <iostream>
using namespace std;

//空指针调用成员函数
class Person
{
private:
public:
    int m_Age;
    void ShowPersonAge(){
        if(this==NULL){//加上这一行可避免代码崩，提高健壮性
            return;
        }
        //报错原因是传入的指针为空。访问空指针里的属性会报错
        cout<<m_Age<<endl;
    }
    void ShowClassName(){
        cout<<"this is Person class!"<<endl;
    }
    Person(/* args */);
    ~Person();
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01(){
    Person *p=NULL;
    //调用第一个没有出错
    p->ShowClassName();
    //报错原因是传入的指针为空。访问空指针里的属性会报错
    p->ShowPersonAge();
}


int main(){
    test01();
}
```



#### 4.3.4 const修饰成员函数



**常函数：**

+ 成员函数后加const后我们称这个函数为**常函数**
+ 常函数内不可以修改成员属性
+ 成员属性声明时加关键字mutable后，在常函数中依然可以修改



**常对象：**

+ 声明对象前加const称该对象为常对象
+ 常对象只能调用常函数

```c++
#include <iostream>
using namespace std;

//常函数
class Person
{
private:
    /* data */
public:
    int m_a;
    //this指针的本质是指针常量，指针的指向是不可以修改的
    //this指针不可以修改指向，但可以修改指向的值
    //相当于Person * const this，如果值也不想改，可以变成const Person * const this
    //在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void ShowPerson() const {
        //m_a=100;   后面有const就不能修改成员变量
        m_b=100;
        cout<<m_b<<endl;
        m_b=200;
        cout<<m_b<<endl;
    }
    Person(/* args */);
    ~Person();
    mutable int m_b;//特殊变量，即使在常函数中也能被修改加关键字mutable
    void func(){}
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test02(){
    const Person p;//在对象前加const变为常对象
    //不允许修改指针指向的值
    
    //常对象只能调用常函数
    p.ShowPerson();//只能调用常函数
    //p.func();会报错，不允许修改对象的值，不能调用普通的成员函数
}

int main(){
    Person p;
    p.ShowPerson();
}
```



### 友元

生活中你家有客厅（public），有你的卧室（Private）

客厅里所有客人都可以进去，但是你的卧室是私有的，也就是只有你能进去

但是你也可以允许你的好闺蜜进去。



在程序里，有些私有属性，也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术



友元的目的就是让一个函数或者类，访问另一个类中的私有元素



友元的关键字为==friend==



友元的三种实现

+ 全局函数做友元
+ 类做友元
+ 类中成员函数做友元



####4.4.1 全局函数做友元

```c++
#include <iostream>
#include <string>
using namespace std;


//建筑物类
class Building
{
    //guimi函数是一个友元，可以访问类中私有成员
    friend void guimi(Building *building);
private:
    string m_bedroom;//卧室
public:
    Building();
    ~Building();
    string m_SittingRoom;// 客厅

};

Building::Building()
{
    m_SittingRoom="客厅";
    m_bedroom="卧室";
}

Building::~Building()
{
}


//全局函数，既能访问公共成员也能访问私有成员
void guimi(Building *building){
    cout<<"全局函数正在访问"<<building->m_SittingRoom<<endl;

    cout<<"全局函数正在访问"<<building->m_bedroom<<endl;
    return;
}


void test01(){
    Building building;
    guimi(&building);
}

int main(){
    test01();
}
```



#### 4.4.2 类做友元

```c++
#include <iostream>
#include <string>
using namespace std;


//类做友元
class Building;
class GuiMi
{
private:
public:
    void visit();//参观函数，访问Building中的属性
    GuiMi();
    ~GuiMi();
    Building *building;
};

class Building
{
private:
    string m_bedroom;//卧室
public:
    //让GuiMi类作为友元，可以访问本类中的私有成员
    friend class GuiMi;
    Building();
    ~Building();
    string m_sittingroom;//客厅
};

GuiMi::GuiMi()
{
    building=new Building;
}

GuiMi::~GuiMi()
{
}

void GuiMi::visit(){
    cout<<"GuiMi类正在访问"<<building->m_sittingroom<<endl;
    cout<<"GuiMi类正在访问"<<building->m_bedroom<<endl;
}



Building::Building()
{
    m_sittingroom="客厅";
    m_bedroom="卧室";
}

Building::~Building()
{
}


void test01(){
    GuiMi gg;
    gg.visit();
}


int main(){
    test01();
}
```



#### 4.4.3 成员函数做友元

```c++
#include <iostream>
#include <string>
using namespace std;

class Building;
class GuiMi
{
private:
public:
    GuiMi();
    ~GuiMi();
    Building *building;
    void visit();//让visit可以访问Building中私有成员
    void visit2();//让visit2不可以访问Building中私有成员
};


class Building
{
    friend void GuiMi::visit();//告诉编译器这个GuiMi类下的visit函数作为本类的友元，可以访问私有成员
private:
    string m_BedRoom;//卧室
public:
    Building();
    ~Building();
    string m_SittingRoom;//客厅
};

Building::Building()
{
    m_SittingRoom="客厅";
    m_BedRoom="卧室";
}

Building::~Building()
{
}

GuiMi::GuiMi()
{
    building=new Building;
}

GuiMi::~GuiMi()
{
}

void GuiMi::visit(){
    cout<<"visit函数正在访问"<<building->m_SittingRoom<<endl;
    cout<<"visit函数正在访问"<<building->m_BedRoom<<endl;
}

void GuiMi::visit2(){
    cout<<"visit2函数正在访问"<<building->m_SittingRoom<<endl;
    //cout<<"visit2函数正在访问"<<building->m_BedRoom<<endl;
}

void test01(){
    GuiMi gg;
    gg.visit();
    gg.visit2();
}

int main(){
    test01();
}
```



### 运算符重载

运算符重载概念：对已有运算符进行重新进行定义，赋予另一种功能，以适应不同的数据类型



对于内置的数据类型，编译器知道如何进行运算

#### 4.5.1 加号运算符重载

作用：实现两个自定义数据类型相加的运算

```c++
#include <iostream>
using namespace std;

//加号运算符重载
//1、成员函数重载+号

class Person
{
private:
    
public:
    Person();
    ~Person();
    int m_A;
    int m_B;
    Person operator+(Person &p){
        Person temp;
        temp.m_A=this->m_A+p.m_A;
        temp.m_B=this->m_B+p.m_B;
        return temp;
    }
};

Person::Person()
{
}

Person::~Person()
{
}


//函数重载版本
Person operator+(Person &p,int num){
    Person temp;
    temp.m_A=p.m_A+num;
    temp.m_B=p.m_B+num;
    return temp;
}

void test01(){
    Person p1;
    p1.m_A=10;
    p1.m_B=10;
    Person p2;
    p2.m_A=10;
    p2.m_B=10;
    //成员函数重载的本质调用Person p3=p1.operator+(p2);简化为下面类型
    //全局函数重载的本质调用Person p3=operator+(p1,p2);简化为下面类型
    Person p3=p1+p2;
    //运算符重载也可以发生函数重载
    Person p4=p1+10;//Person类型+int类型
    cout<<"p3的m_A值为"<<p3.m_A<<endl;
    cout<<"p3的m_B值为"<<p3.m_B<<endl;
    cout<<"p4的m_A值为"<<p4.m_A<<endl;
    cout<<"p4的m_B值为"<<p4.m_B<<endl;
}


//2、全局函数重载+号
Person operator+(Person &p1,Person &p2){
    Person temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}


int main(){
    test01();
}
```

==**总结1：对于内置的数据类型的表达式的运算符是不可能改变的**==

==**总结2：不要滥用运算符重载**==



#### 4.5.2 左移运算符重载

作用：输出自定义数据类型



```c++
#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream &cout,Person p);
private:
    int m_A;
    int m_B;
public:
    Person(int a,int b);
    ~Person();
    
    //不会利用成员函数重载<<运算符，因为无法实现cout在左侧
    //void operator<<(cout);

};

Person::Person(int a,int b)
{
    m_A=a;
    m_B=b;
}

Person::~Person()
{
}

//只能用全局函数重载左移运算符
//函数里面cout可以改成其他名字，因为引用相当于给cout起了别名，实质还是cout
ostream& operator<<(ostream &cout,Person p){//本质 operator (cout,p)   简化为cout<<p
//cout是输出流对象
    cout<<"m_A是："<<p.m_A<<endl<<"m_B是："<<p.m_B<<endl;
    return cout;
}

void test01(){
    Person p(10,10);
    //cout<<p;//后面不能往后加endl了，因为这是调用了一个函数，函数类型是void，如果返回类型仍是cout就能继续加endl了
    cout<<p<<endl;//换成ostream&类型就能继续用了，运用了链式编程思想
}

int main(){
    test01();
}
```

==**总结：左移运算符配合友元可以实现输出自定义数据类型**==



#### 4.5.3 递增运算符重载

作用：通过重载递增运算符，实现自己的整形数据

```c++
#include <iostream>
using namespace std;

//重载递增运算符

//自定义整型
class MyInteger
{
    friend ostream& operator<<(ostream &cout,MyInteger m);
private:
    int m_num;
public:
    MyInteger(){
        m_num=0;
    }
    ~MyInteger();
    //重载前置++运算符
    MyInteger& operator++(){//使用引用返回的是自身，不是拷贝构造函数创造的新对象
    //返回引用是为了一直对一个数据进行操作
    //先进行++运算，再将自身返回
        m_num++;
        return *this;
    }

//重载后置++运算符
MyInteger operator++(int){   //int代表占位参数，可以用于区分前置和后置递增
//先记录当时的结果
    MyInteger temp=*this;
//然后进行递增
    this->m_num++;
//最后返回原来的结果
    return temp;//我们返回的是局部对象的值，所以返回类型不能是引用，要不然后面就是非法操作了
}    
};


ostream& operator<<(ostream &cout,MyInteger m){
    cout<<m.m_num<<endl;
    return cout;
}


MyInteger::~MyInteger()
{
}

void test01(){
    MyInteger m;
    cout<<++m;
    cout<<m;
    //注意这里不能两个连着写，不然会错，分开输出的对的
}

void test02(){
    MyInteger m;
    cout<<m++;
    cout<<m;
    //后置递增不能连续写，比如(m++)++
}

//前置递增返回引用，后置递增返回值
int main(){
    test01();
    test02();
}
```



#### 4.5.4 赋值运算符重载



c++编译器至少给一个类添加4个函数

1. 默认的构造函数（无参，函数体为空）
2. 默认析构函数（无参，函数体为空）
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符operator=，对属性进行拷贝



如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

编译器默认提供的赋值运算是浅拷贝，如果有属性创建在堆区会出现深浅拷贝问题

示例：

```c++
#include <iostream>
using namespace std;

//赋值运算符重载
class Person
{
private:
    /* data */
public:
    Person(int age);
    ~Person();
    int *m_Age;
    Person& operator=(Person &p){//要使用引用
        //编译器提供浅拷贝  m.Age=p.m_Age
        //应该先判断是否有属性在堆区，如果有，先释放干净，然后再深拷贝
        if(m_Age!=NULL){
            delete m_Age;
            m_Age=NULL;
        }
        m_Age=new int(*p.m_Age);//深拷贝
        return *this;
    }
};

Person::Person(int age)
{
    m_Age=new int(age);
}

Person::~Person()
{
    if(m_Age!=NULL){
        delete m_Age;
        m_Age=NULL;
    }
}

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3=p2=p1;
    //直接赋值会出现堆区空间被重复释放的问题，解决方案，利用深拷贝解决浅拷贝的问题
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    cout<<"p3的年龄为："<<*p3.m_Age<<endl;
}


int main(){
    test01();
    // int a=10;
    // int b=20;
    // int c=30;
    // a=b=c;

}
```



#### 4.5.5 关系运算符重载

作用：重载关系运算符，可以让两个自定义数据类型对象进行比较



示例：

```c++
#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    Person(string name,int age);
    ~Person();
    string m_Name;
    int m_Age;
    //重载关系运算符==
    bool operator==(Person &p){//!=重载也一样
        if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age){
            return true;
        }else{
            return false;
        }
    }
    bool operator!=(Person &p){
        if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age){
            return false;
        }else{
            return true;
        }
    }
};

Person::Person(string name,int age)
{
    m_Name=name;
    m_Age=age;
}

Person::~Person()
{
}

void test01(){
    Person p1("Bella",18);
    Person p2("Diana",18);
    if(p1!=p2){
        cout<<"p1和p2是不相等的！"<<endl;
    }else{
        cout<<"p1和p2是相等的！"<<endl;
    }
}

int main(){
    test01();
}
```



 #### 4.5.6 函数调用运算符重载

+ 函数调用运算符()也可以
+ 由于重载后的使用方法非常像函数的调用，因此称为仿函数
+ 仿函数没有固定写法，非常灵活

示例：

```c++
#include <iostream>
#include <string>
using namespace std;

//函数调用运算符重载

//打印输出类
class MyPrint
{
private:
    
public:
    MyPrint();
    ~MyPrint();
    //重载函数调用运算符
    void operator()(string test){
        cout<<test<<endl;
    }
};

MyPrint::MyPrint()
{
}

MyPrint::~MyPrint()
{
}

void myprint02(string test){
    cout<<test<<endl;
}

void test01(){
    MyPrint myprint;
    myprint("hello world");//重载()之后使用的，由于使用起来非常类似于函数调用，因此称为仿函数
    myprint02("hello world!");//函数调用
}


//仿函数非常灵活，没有固定的写法
//加法类
class MyAdd
{
private:
    /* data */
public:
    MyAdd();
    ~MyAdd();
    int operator()(int a,int b){
        return a+b;
    }
};

MyAdd::MyAdd()
{
}

MyAdd::~MyAdd()
{
}

void test02(){
    MyAdd myadd;
    int ret=myadd(100,100);
    cout<<"ret="<<ret<<endl;

    //匿名函数对象
    cout<<MyAdd()(100,100)<<endl;//创建一个匿名对象，当前运行完就被释放
}

int main(){
    test01();
    test02();
}
```



### 4.6 继承

**继承是面向对象三大特性之一**

有些类与类之间存在特殊的关系，比如动物里有猫和狗，其中猫狗又有各种种类

我们发现，定义这些类时，下级别的成员除了含有上一级的共性，还有自己的特性

这个时候我们就可以考虑利用继承的技术，减少重复代码



#### 4.6.1 继承的基本语法

例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同

接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处



```c++
#include <iostream>

using namespace std;

//普通实现

// //java界面
// class Java
// {
// private:
    
// public:
//     void header(){
//         cout<<"首页、公开课、登录、注册...（公共头部）"<<endl;
//     }
//     void footer(){
//         cout<<"帮助中心、交流合作、站内地图...（公共底部）"<<endl;
//     }
//     void left(){
//         cout<<"Java、python、c++...（公共分类列表）"<<endl;
//     }
//     void content(){
//         cout<<"Java学科视频"<<endl;
//     }
// };





// //python
// class Python
// {
// private:
    
// public:
//     void header(){
//         cout<<"首页、公开课、登录、注册...（公共头部）"<<endl;
//     }
//     void footer(){
//         cout<<"帮助中心、交流合作、站内地图...（公共底部）"<<endl;
//     }
//     void left(){
//         cout<<"Java、python、c++...（公共分类列表）"<<endl;
//     }
//     void content(){
//         cout<<"Python学科视频"<<endl;
//     }
// };


// class CPP
// {
// private:
    
// public:
//     void header(){
//         cout<<"首页、公开课、登录、注册...（公共头部）"<<endl;
//     }
//     void footer(){
//         cout<<"帮助中心、交流合作、站内地图...（公共底部）"<<endl;
//     }
//     void left(){
//         cout<<"Java、python、c++...（公共分类列表）"<<endl;
//     }
//     void content(){
//         cout<<"C++学科视频"<<endl;
//     }
// };


//继承实现界面
class BasePage
{
private:

public:
    void header(){
        cout<<"首页、公开课、登录、注册...（公共头部）"<<endl;
    }
    void footer(){
        cout<<"帮助中心、交流合作、站内地图...（公共底部）"<<endl;
    }
    void left(){
        cout<<"Java、python、c++...（公共分类列表）"<<endl;
    }

};

class Java :public BasePage
{
private:

public:
    void content(){
        cout<<"Java学科视频"<<endl;
    }
};

class Python :public BasePage
{
private:

public:
    void content(){
        cout<<"Python学科视频"<<endl;
    }
};

class CPP :public BasePage
{
private:

public:
    void content(){
        cout<<"c++学科视频"<<endl;
    }
};

void test01(){
    cout<<"Java页面如下："<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout<<"-------------------------------"<<endl;
    cout<<"Python页面如下："<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout<<"-------------------------------"<<endl;
    cout<<"C++页面如下："<<endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

int main(){
    test01();
}
```

==**优点：减少重复的代码**==

==**语法：class 子类 : 继承方式   父类**==

子类也成为**派生类**

父类也成为**基类**



**派生类中的成员，包含两大部分：**

一类是从基类继承过来的，一类是自己增加的成员

从基类继承过来的表现其共性，而新增的成员体现了其个性



#### 4.6.2 继承方式

继承的语法：class 子类  ： 继承方式   父类

**继承方式一共有三种：**

+ 公共继承
+ 保护继承
+ 私有继承

基类中私有成员子类不管用哪种继承方式都不可以访问

```c++

class A{
public:
    int a;
protected:
    int b;
private:
    int c;
}

//公共继承跟父类没有区别
class B : public A{
public:
    int a;
protected:
    int b;
//c不可访问
}

//除了访问不到，其他全变成了保护类型
class B : protected A{
protected:
    int a,b;
//c不可访问
}

//除了访问不到，其他全变成了私有类型
class B : private A{
private:
    int a,b;
//c不可访问
}
```



```c++
#include <iostream>

using namespace std;

class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
}

class Son1 : public Base1{
public:

    void func(){
        m_A=10;//父类中的公共权限成员在子类中仍是公共权限
        m_B=10;//父类中的公共权限成员在子类中仍是保护权限
        //m_C=10;父类中的私有权限成员，子类访问不到
    }
}

void test01(){
    Son1 s1;
    s1.m_A=100;
    //s1.m_B=100;保护权限类内可以访问，类外访问不了
}

//保护继承
class Base2{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
}

class Son2:protected Base2{
public:
    void func(){
        m_A=100;//公共权限变为了保护权限
        m_B=100;
        //m_C=100;子类访问不到
    }
}

void test02(){
    Son2 s2;
    //s2.m_A=100;保护权限，类外访问不到
    
}

class Base3{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
}

class Son3:private Base3{
public:
    void func(){
        m_A=100;
        m_B=100;
        //m_C=100;
    }
}

void test03(){
    Son3 s3;
    //s3.m_A=100;//到Son3中变为私有成员
}

int main(){
    test02();
}
```



#### 4.6.3 继承中的对象模型

问题：从父类继承过来的成员，哪些属于子类对象中？

示例：

```c++
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
```

**结论：父类中私有的成员属性是被编译器隐藏了，因此是访问不到，但是确实被继承下去了**



#### 4.6.4 继承中构造和析构顺序

子类继承父类后，当创建子类对象，也会调用父类的构造函数



问题：父类和子类的构造和析构顺序是谁先谁后呢？

```c++
#include <iostream>
using namespace std;

//继承中的构造和析构顺序
class Base{
public:
    Base(){
        cout<<"Base构造函数！"<<endl;
    }
    ~Base(){
        cout<<"Base析构函数!"<<endl;
    }
};

class Son:public Base{
public:
    Son(){
        cout<<"Son构造函数！"<<endl;
    }
    ~Son(){
        cout<<"Son析构函数!"<<endl;
    }
};

void test01(){
    //Base b;
    Son s1;
}

int main(){
    test01();
}
```

==**继承中的构造和析构顺序如下：先构造父类，再构造子类，析构的顺序与构造的顺序相反**==



#### 4.6.5 继承同名成员处理方式

问题：当子类和父类出现同名的成员，如何通过子类对象，访问到子类或者父类中的同名数据呢？

+ 访问子类同名成员，直接访问即可
+ 访问父类同名成员，需要加作用域

```c++
#include <iostream>

using namespace std;

//继承中同名成员处理方式
class Base{
public:
    Base(){
        m_A=100;
    }
    void func(){
        cout<<"Base作用域下func函数调用"<<endl;
    }
    void func(int a){
        cout<<"Base作用域下func(int a)函数调用"<<endl;
    }
    int m_A;
};

class Son:public Base{
public:
    Son(){
        m_A=200;
    }
    void func(){
        cout<<"Son作用域下func函数调用"<<endl;
    }
    int m_A;
};

void test01(){
    Son s1;
    cout<<"m_A="<<s1.m_A<<endl;//如果直接输出默认为子类的数据
    cout<<"Base中m_A="<<s1.Base::m_A<<endl;//使用这样的方式就能访问到父类中数据，需要加作用域
}

//同名成员函数处理
void test02(){
    Son s2;
    s2.func();//直接调用调用的是子类的函数
    s2.Base::func();
    //如果子类中出现与父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
    //如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    s2.Base::func(100);
}

int main(){
    test01();
    test02();
}
```

**总结：**

1. 子类对象可以直接访问到子类中同名成员
2. 子类对象加作用域可以访问到父类同名成员
3. 当子类和父类拥有同名成员函数时，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名成员函数



#### 4.6.6 继承同名静态成员处理方式

问题：继承中同名的静态成员在子类对象上如何进行访问



静态成员和非静态成员出现同名，处理方式一致



+ 访问子类同名成员，直接访问
+ 访问父类同名成员，加作用域

```c++
#include <iostream>

using namespace std;

//继承中的同名静态成员处理方式
class Base{
public:
    static int m_A;
    static void func(){
        cout<<"Base-static func()"<<endl;
    }
    static void func(int a){
        cout<<"Base-static func(int a)"<<endl;
    }
};

int Base::m_A=100;

class Son:public Base{
public:
    static int m_A;
    static void func(){
        cout<<"Son-static func()"<<endl;
    }
};

int Son::m_A=200;

//同名静态成员属性
void test01(){
    //1.通过对象访问
    cout<<"通过对象访问"<<endl;
    Son s1;
    cout<<"Son 下s1.m_A="<<s1.m_A<<endl;
    cout<<"Base 下s1.m_A="<<s1.Base::m_A<<endl;
    //2.通过类名访问
    cout<<"通过类名访问"<<endl;
    cout<<"Son 下s1.m_A="<<Son::m_A<<endl;
    cout<<"Base 下s1.m_A="<<Base::m_A<<endl;
    //第一个::表示通过类名方式访问，第二个::表示访问父类作用域下
    cout<<"Base 下s1.m_A="<<Son::Base::m_A<<endl;
}


//同名静态成员函数
void test02(){
    Son s2;
    //通过对象访问
    s2.func();
    s2.Base::func();
    s2.Base::func(100);
    //通过类名访问
    Son::func();
    Son::Base::func();
    //当子类和父类拥有同名静态成员函数时，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名成员函数
    Son::Base::func(100);
}

int main(){
    test01();
    test02();
}
```

**总结：**

同名静态成员处理方式和非静态处理方式一样，只不过有两种访问方式（通过对象 和 通过类名）



#### 4.6.7 多继承语法

c++中==允许一个类继承多个类==



==**语法：class 子类 : 继承方式 父类1 ,  继承方式  父类2...**==



多继承可能会引发父类中有同名成员出现，需要加作用域区分



**c++实际开发中不建议使用**

```c++
#include <iostream>
using namespace std;

class Base1{
public:
    int m_A;
    Base1(){
        m_A=100;
    }
};

class Base2{
public:
    int m_A;
    Base2(){
        m_A=200;
    }
};

//子类需要继承Base1和Base2
//语法：class 子类 : 继承方式 父类1 ,  继承方式  父类2...
class Son:public Base1,public Base2{
public:
    int m_C;
    int m_D;
    Son(){
        m_C=300;
        m_D=400;
    }
};

void test01(){
    Son s;
    cout<<"sizeof(Son)="<<sizeof(s)<<endl;
    //cout<<s.m_A<<endl;出现二义性
    //当父类中出现同名成员，需要加作用域
    cout<<"Base1中m_A="<<s.Base1::m_A<<endl;
    cout<<"Base2中m_A="<<s.Base2::m_A<<endl;
}

int main(){
    test01();
}
```

**总结：**

多继承中如果父类中出现了同名情况，子类使用时候要加作用域



#### 4.6.8 菱形继承

**菱形继承概念：**

两个派生类继承同一个基类

又有某个类同时继承这两个派生类

这种继承被称为菱形继承，或者钻石继承



经典案例：羊和驼都继承动物的属性，羊驼又继承羊和驼的属性

菱形继承问题：

1. 羊继承了动物的数据，驼同样继承了动物的数据，当羊驼使用数据时，会产生二义性
2. 羊驼继承自动物的数据继承了两份，其实我们应该清楚，这个数据我们只需要一份就行



```c++
#include <iostream>
using namespace std;


class Animal{
public:
    int m_Age;
};
//利用虚继承可以解决菱形继承问题

//继承之前，加上关键字virtual变为虚继承
//Animal类称为虚基类
class Sheep:virtual public Animal{};



class Camel:virtual public Animal{};

class YangTuo:public Sheep,public Camel{};

void test01(){
    YangTuo yt;
    //yt.m_Age=18;会报错，不明确
    yt.Sheep::m_Age=18;
    yt.Camel::m_Age=28;
    //当出现菱形继承的时候，两个父类拥有相同数据需要加作用域
    cout<<"yt.Sheep::m_Age="<<yt.Sheep::m_Age<<endl;
    cout<<"yt.Camel::m_Age="<<yt.Camel::m_Age<<endl;
    //菱形继承导致数据有两份，资源浪费
    //使用虚继承后可以用下面这种方式访问
    cout<<"yt.m_Age"<<yt.m_Age<<endl;

}

int main(){
    test01();
}
```

使用虚基类后，类中会有一个**虚基类指针(vbptr)**，v表示virtual，b表示base，ptr是pointer

vbptr会指向这个类的**vbtable（虚基类表）**，表中记录了偏移量，**类的起始地址加上偏移量就能找到唯一数据，所以数据只有一份**

所以继承不是继承数据，而是继承指针



**总结**

+ 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
+ 利用虚继承可以解决菱形继承问题



### 4.7 多态

#### 4.7.1 多态的基本概念



**多态是c++面向对象三大特点之一**（封装、继承、多态）

多态分为两类：

+ 静态多态：函数重载和运算符重载，属于静态多态，复用函数名
+ 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态的区别：

+ 静态多态的函数地址早绑定 - 编译阶段确定函数地址
+ 动态多态的函数地址晚绑定 - 运行阶段确定函数地址



```c++
#include <iostream>
using namespace std;

//多态

//动态多态满足条件：1、有继承关系 2、子类要重写父类的虚函数，子类可写virtual也可不写
//重写：函数返回值类型、函数名、参数列表完全相同

//动态多态使用：父类的指针或者引用 执行子类对象
class Animal{
public:
//虚函数
    virtual void speak(){
        cout<<"动物在说话"<<endl;
    }
};

class Cat:public Animal{
public:
    void speak(){
        cout<<"小猫在说话"<<endl;
    }
};

//执行说话的函数
//地址早绑定，在编译阶段就确定了函数的地址
//如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段绑定，地址晚绑定
void doSpeak(Animal &ani){//Animal &ani=cat;  父子之间可以直接进行类型转换
    ani.speak();//根据传入对象不同确定说话的人不同，地址晚绑定
}

void test01(){
    Cat cat;
    doSpeak(cat);//父类引用指向子类对象
}

int main(){
    test01();
}
```

**总结：**

+ 有继承关系
+ 子类重写父类中的虚函数

多态使用条件

+ 父类指针或引用指向子类对象

重写：函数返回值类型，函数名，参数列表完全一致



==**剖析**==

**当加了virtual后，Animal类内部会有一个虚函数（表）指针vfptr（v-virtual，f-function，ptr-pointer），指向虚函数表vftable，表内记录了虚函数的地址&Animal::speak**

**如果没有发生重写，Cat类将Animal中所有东西继承下来。**

**如果子类重写了父类的虚函数，子类中虚函数表内部会替换成子类的虚函数地址&Cat::speak**

**当父类的指针或者引用指向子类对象时，发生多态**

如果不明白就去听多态的原理剖析





#### 4.7.2 多态案例一、计算器类







#### 4.7.3 纯虚函数和抽象类

在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类中重写的内容



因此可以将虚函数改为**纯虚函数**



纯虚函数语法：**virtual  返回值类型  函数名  (参数列表) =  0 ;**

当类中有了纯虚函数，这个类也被称为==抽象类==



**抽象类特点：**

+ 无法实例化对象
+ 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

```c++
#include <iostream>
using namespace std;

class Base{
public:
//纯虚函数
//只要有一个纯虚函数，这个类被称为抽象类，无法实例化对象,抽象类的子类必须重写父类中的虚函数，不然也属于抽象类
    virtual void func()=0;
};

class Son:public Base{
public:
    void func(){
        cout<<"func函数调用"<<endl;
    }
};

void test01(){
    //多态  父类的指针或引用指向子类对象
    Base *base=new Son;
    base->func();
}

int main(){
    test01();
}
```



#### 4.7.4 多态案例二、制作饮品







#### 4.7.5 虚析构和纯虚析构

多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码



解决方法：将父类中的析构函数改为**虚析构**或者**纯虚析构**



虚析构和纯虚析构共性：

+ 可以解决父类指针释放子类对象
+ ==都需要有具体的函数实现==

虚析构和纯虚析构区别：

+ ==如果是纯虚析构，该类属于抽象类，无法实例化对象==



```c++
#include <iostream>
#include <string>
using namespace std;

//虚析构和纯虚析构
class Animal{
public:
//纯虚函数
    Animal(){
        cout<<"animal构造函数调用"<<endl;
    }
//    virtual ~Animal(){
// 利用虚析构可以解决父类指针释放子类对象不干净的问题
//        cout<<"animal析构函数调用"<<endl;
//    }
    //纯虚析构 也能解决释放的问题，但是需要声明也需要实现
    //有了纯虚析构之后，这个类也属于抽象类，不能实例化对象
    virtual ~Animal()=0;
    virtual void speak()=0;
};

Animal:: ~Animal(){
    cout<<"animal纯析构函数调用"<<endl;
}

class Cat:public Animal{
public:
    Cat(string name){
        cout<<"cat构造函数调用"<<endl;
        m_Name = new string(name);
    }
    void speak(){
        cout<<*m_Name<<"小猫在说话"<<endl;
    }
    ~Cat(){
        if(m_Name!=NULL){
            cout<<"cat析构函数调用"<<endl;
            delete m_Name;
            m_Name=NULL;
        }
    }
    string *m_Name;
};

void test01(){
    Animal * animal=new Cat("Tom");
    animal->speak();
    //父类指针在析构的时候哦不会调用子类中析构函数，导致子类如果有堆区数据，会出现内存泄漏
    delete animal;
}

int main(){
    test01();
}
```

虚析构语法：

virtual  ~类名(){}



纯虚析构语法：**需要有具体实现**

virtual ~类名()=0;

类名::~类名(){}



**总结：**

1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
3. 拥有纯虚析构函数的类也属于抽象类



#### 4.7.6 多态案例三、电脑组装





## 5文件操作

程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过**文件可以将数据持久化**

c++中对文件操作需要包含头文件==**<fstream>**==



文件类型分为两种：

1. **文本文件**  -  文件以文本的**ASCII**码形式存储在计算机中
2. **二进制文件**   -   文件以文本的**二进制**形式存储在计算机中，用户一般不能直接读懂他们



操作文件的三大类：

1. ofstream：写操作
2. ifstream：读操作
3. fstream：读写操作



### 5.1 文本文件

#### 5.1.1 写文件

写文件步骤如下：

1. 包含头文件

   ```c++
   #include <iostream>
   ```

2. 创建流对象

   ```c++
   ofstream ofs;
   ```

3. 打开文件

   ```c++
   ofs.open("文件路径",打开方式);
   ```

4. 写数据

   ```c++
   ofs<<"写入的数据";
   ```

5. 关闭文件

   ```c++
   ofs.close();
   ```



文件打开方式：

|  打开方式   |             解释             |
| :---------: | :--------------------------: |
|   ios::in   |      为读文件而打开文件      |
|  ios::out   |      为写文件而打开文件      |
|  ios::ate   |       初始位置：文件尾       |
|  ios::app   |        追加方式写文件        |
| ios::trunc  | 如果文件存在，先删除，再创建 |
| ios::binary |          二进制方式          |

**注意：**文件打开方式可以配合使用，利用|操作符

例如：用二进制方式写文件 ios::binary|ios::out

```c++
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
```

**总结：**

+ 文件操作必须包含头文件fstream
+ 读文件可以用fstream类或ofstream
+ 打开文件时需要指定操作文件的路径，以及打开方式
+ 利用<<可以向文件中写数据
+ 操作完毕，要关闭文件



#### 5.1.2 读文件

读文件与写文件步骤相似，但是读取方式相对较多



读文件步骤如下：

1. 包含头文件

   ```c++
   #include <fstream>
   ```

2. 创建流对象

   ```c++
   ifstream ifs;
   ```

3. 打开文件并判断文件是否打开成功

   ```c++
   ifs.open("文件路径",打开方式);
   ```

4. 读数据

   四种方式读取

5. 关闭文件

   ```c++
   ifs.close();
   ```

   示例：

   ```c++
   #include <iostream>
   #include <fstream>
   #include <string>
   using namespace std;
   
   //文本文件 读文件
   void test01(){
       //1、包含头文件
       //2、创建流对象
       ifstream ifs;
       //3、打开文件，并且判断是否打开成功
       ifs.open("test.txt",ios::in);
       if(!ifs.is_open()){
           cout<<"文件打开失败"<<endl;
           return;
       }
       //4、读数据
       //第一种
       // char buf[1024]={0};
       // while(ifs>>buf){
       //     cout<<buf<<endl;
       // }
   
       //第二种
       // char buf[1024]={0};
       // while(ifs.getline(buf,sizeof(buf))){
       //     cout<<buf<<endl;
       // }
   
   
       //第三种
       // string buf;
       // while (getline(ifs,buf)){
       //     cout<<buf<<endl;
       // }
       
   
       //第四种 不推荐这种
       char c;
       while((c=ifs.get())!=EOF){//end of file
           cout<<c;
       }
           
   
       //5、关闭文件
       ifs.close();
   }
   
   
   int main(){
       test01();
   }
   ```

   总结：

   + 读文件可以利用ifstream，或者fstream类
   + 利用is_open函数可以判断文件是否打开成功
   + close关闭文件

### 5.2 二进制文件

以二进制的方式对文件进行读写操作

打开方式要指定为==ios::binary==



#### 5.2.1 写文件

二进制方式写文件主要利用流对象调用成员函数write

函数原型：ostream& write(const char* buffer,int len);

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数。

```c++
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
```

总结：

+ 文件输出流对象  可以通过write函数，以二进制方式写数据



#### 5.2.2 读文件

二进制方式读文件主要利用流对象调用成员函数read

函数原型：istream& read(char *buffer,int len);

参数解释：字符指针buffer指向内存中一段存储空间。len是独写的字节数



```c++
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
```

+ 文件输入流对象可以通过read函数，，以二进制方式读取