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