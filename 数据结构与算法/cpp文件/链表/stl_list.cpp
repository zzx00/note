#include <iostream>
#include <list>
using namespace std;

int main(){
    //声明一个int型链表
    list<int> cList;
    //在list后插入一个元素        
    cList.push_back(5);  
    //在list前插入一个元素   
    cList.push_front(6);    
    cList.push_front(5);
    cList.push_front(4);
    cList.push_front(5);
    cList.push_front(5);
    cList.push_front(8);
    if(cList.empty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"not empty"<<endl;
    }

    //声明一个迭代器
    list<int>::iterator iter;
    //输出链表中的值
    for(iter=cList.begin();iter!=cList.end();iter++){
        cout<<*iter<<' ';
    }
    cout<<endl;
    //使用sort排序
    cList.sort();
    for(iter=cList.begin();iter!=cList.end();iter++){
        cout<<*iter<<' ';
    }
    cout<<endl;
    //删除第一个元素
    cList.pop_front();

    //删除最后一个元素
    cList.pop_back();

    //删除指定对象
    cList.remove(5);
    for(iter=cList.begin();iter!=cList.end();iter++){
        cout<<*iter<<' ';
    }

    return 0;
}
/*
assign() //给list赋值
back() //返回最后一个元素
begin() //返回指向第一个元素的迭代器
clear() //删除所有元素
empty() //如果list是空的则返回true
end() //返回末尾的迭代器
erase() //删除一个元素
front() //返回第一个元素
get_allocator() //返回list的配置器
insert() //插入一个元素到list中
max_size() //返回list能容纳的最大元素数量
merge() //合并两个list
pop_back() //删除最后一个元素
pop_front() //删除第一个元素
push_back() //在list的末尾添加一个元素
push_front() //在list的头部添加一个元素
rbegin() //返回指向第一个元素的逆向迭代器
remove_if() //按指定条件删除元素
remove() //从list删除元素
rend() //指向list末尾的逆向迭代器
resize() //改变list的大小
reverse() //把list的元素倒转
size() //返回list中的元素个数
sort() //给list排序
splice() //合并两个list
swap() //交换两个list
unique() //删除list中重复的元素
*/