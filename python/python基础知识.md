# Python基础知识

## 1. 认识Python

### 1.1 Python概述

#### 1.1.1 基本概念

+ Python是一门**解释型、面向对象**的高级程序语言
+ Python是开源免费的、支持交互式、可跨平台移植的脚本语言



+ 1991年，第一个Python编译器（同时也是解释器）诞生，它是由C语言实现的，并能够调用c库



#### 1.1.2 特点

Python具有以下特点：

1. 开源，易于维护
2. 可移植（win、Linux、mac）
3. 易于使用、简单
4. 广泛的标准库
5. 可扩展，可嵌入



1. 运行速度慢（解释型语言）
2. 代码不能加密（解释型语言发布就是发布源代码，而c语言只需要把编译后的机器码发布出去）



#### 1.1.3 典型应用

科学计算：Numpy、SciPy、Matplotlib等

服务器软件：网络爬虫等

Web开发：Django、TurboGears、web2py等框架

自动化脚本

桌面软件：PyQt、PySide、wxPython、PyGTK等

游戏：很多游戏使用c++编写图形显示等高性能模块，使用Python或者Lua编写游戏的逻辑、服务器



应用方向：数据分析、人工智能、科学计算、网络爬虫、常规软件开发、WEB开发



#### 1.1.4 一些跟命令提示符相关的

import this会出来一首诗

退出：exit()或者ctrl+z，当屏幕出现^Z时回车（用在程序出现死循环）

直接执行python程序时在命令提示符中直接python +文件名即可(python hello.py)



#### 1.1.5 变量及类型

+ 变量可以是任意的数据类型，在程序中用一个变量名表示
+ 变量名必须是**大小写字母、数字和下划线的组合，且不能以数字开头
+ 赋值（比如a="ABC"）时，python解释器干了两件事：

1. 在内存中创建一个“ABC”的字符串
2. 在内存中创建一个名为a的变量，并把它指向’ABC‘



#### 1.1.6 标识符和关键字

+ 什么是关键字

> python一些具有特殊功能的标识符 ，这就是所谓的关键字
>
> 关键字，是python已经使用了的，所有不允许开发者自己定义和关键字相同的名字的标识符

+ 查看关键字

```python
import keyword
keyword.kwlist
```

['False', 'None', 'True', 'and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'raise', 'return', 'try', 'while', 'with', 'yield']



#### 1.1.7 输出

##### 1.1.7.1 普通输出

+ python中的普通输出

```python
#打印提示
print('hello world')
```

##### 1.1.7.2 格式化输出

格式化操作的目的：例如需要输出多个相似的东西

使用字符串格式化

```python
age=10
print("我今年%d岁了"%age)
```

使用%这样的符号

常用符号：

| 格式符号 |            转换             |
| :------: | :-------------------------: |
|    %c    |            字符             |
|  **%s**  | 通过str()字符串转换来格式化 |
|    %i    |      有符号十进制整数       |
|  **%d**  |      有符号十进制整数       |
|    %u    |      无符号十进制整数       |
|    %o    |         八进制整数          |
|    %x    |  十六进制整数（小写字母）   |
|    %X    |  十六进制整数（大写字母）   |
|    %e    |      索引符号（小写e）      |
|    %E    |      索引符号（大写e）      |
|    %f    |          浮点实数           |
|    %g    |        %f和%e的简写         |

##### 1.7.3 换行输出

在输出的时候，如果有\n，那么\n后的内容会在下一行显示



#### 1.1.8 输入

```python
password=input("请输入密码：")
print("您的密码是：",password)
print(type(password))
#不管输入数字还是字符，都会当作字符串类型
```



```python
a=10
print(type(a))
#输出变量的类型
```

 ```python
a=int("123")
b=a+100
print(b)
print(type(a))
#强制类型转换
c=int(input("请输入："))
print("输入了一个数字：%d"%c)
 ```

+ input()的小括号中放入的是提示信息，用来在获取数据之前给用户一个简单提示
+ input()在从键盘获取了数据以后，会存放到等号左边的变量中
+ input()函数接受的输入必须是表达式



#### 1.1.9 运算符和表达式

**：幂 返回x的y次幂

//：取整除，向下取接近除数的整数



比较运算符

和c++一样



赋值运算符

和c++一样



位运算



逻辑运算



## 2.判断语句和循环语句

### 2.1 条件判断语句

+ python指定任何**非零和非空值为True**，**0或者None为False**
+ if语句用于控制程序的执行

```python
d=int(input("请输入数字"))
if (d>0)&(d<1):
    print("1")
elif (d>1)&(d<5):
    print("2")
else:
    print("3")
```

+ 当判断条件成立时，执行后面的语句，而执行内容可以多行，以==**缩进**==来区分同一范围
+ else为可选语句，当需要在条件不成立时执行内容则可执行相关语句

```python
if True:
    print("True")
else:
    print("False")
#可以直接用True
```

**tab可以向前一个缩进，shift+tab可以向后一个缩进**



### 2.2 导入库

可以使用import或者from...import来导入相关模块

将整个模块导入：import somemodule

导入某个函数：from somemodule import somefunction

从某个模块中导入多个函数，格式为：from somemodule import firstfunc,secondfunc,thirdfunc

将某个模块中全部函数导入，格式为：from somemodule import \\*



生成随机数：

```python
#引入库
import random
x=random.randint(0,100)#0到100之间的整数，随机数
print(x)
```



### 2.3 循环语句

#### 2.3.1 for循环

+ python中的循环有两种，一种是for...in循环，可以依次把list或tuple中元素迭代出来



```python
#从0下标开始到4
for i in range(5):
    print(i)

#从0开始到12结束，每次加3，是不包含12的
for i in range(0,12,3):
    print(i)

for i in range(-10,-100,-20):
    print(i)

#也可以对字符串，逐个遍历里面的内容
name="chengdu"
for i in name:
    print(i)
    
a=["aa","bb","cc"]
for i in range(len(a)):
    print(i,a[i])
for i in a:
    print(i)
```



#### 2.3.2 while循环

```python
i=0
while i<5:
    print("当前是第%d次执行循环"%(i+1))
    print("i=%d"%i)
    i+=1

```

```python
i=1
sum=0
while i<=100:
    sum+=i
    i+=1
print(sum)
```

while和else可以混合用

```python
count=0
while count<5:
    print(count,"小于5")
    count+=1
else:
    print(count,"大于或等于5")
```

#### 2.3.3 break,continue和pass

+ break语句可以跳出for和while循环体
+ continue语句跳过当前循环，直接进入下一轮循环
+ pass是空语句，一般用作占位语句，不做任何事情

```python
i=0
while i<10:
    i+=1
    print("-"*30)
    if i==5:
        break
    print(i)

```

```python
i=0
while i<10:
    i+=1
    print("-"*30)
    if i==5:
        continue
    print(i)

```



## 3. 字符串、列表、元组、字典

### 3.1 字符串

+ python中的字符串可以使用**单引号、双引号和三引号**（三个单引号或单个双引号）括起来，使用反斜杠\\来转义特殊字符
+ python3源码文件默认以UTF-8编码，所有字符串都是Unicode字符串
+ 支持字符串拼接、截取等多种运算

```python
my_str="I'm a student"
print(my_str)
my_str_2='I\'m a student'#使用转义字符
print(my_str_2)
my_str_3="Jason said \"I love you\""
print(my_str_3)

str="chengdu"
print(str)
print(str[0])
print(str[0:6])
#[起始位置:结束位置:步进值]
print(str[0:7:2])

print(str[:5])#从第0个到第5个之前的
print(str[6:])#从第6个到最后一个，不包含起始位置那一个

print(str+",你好")#字符串连接使用加号
print(str*3)
print("hello\nchengdu")#使用转义字符
print(r"hello\nchengdu")#直接进行输出，不进行转义，直接输出原始字符
```

#### 3.1.2 字符串常见操作

| 序号 | 方法及描述                                                   |
| ---- | ------------------------------------------------------------ |
| 1    | capitalize()将字符串中的第一个字符转换为大写                 |
| 2    | center(width,fillchar)返回一个指定宽度width居中的字符串，fillchar为填充的字符，默认为空格 |
| 3    | count(str,beg=0,end=len(string))返回str在string里面出现的次数，如果beg或者end指定则返回指定范围内str的出现次数 |
|      | ...网上搜，40余种                                            |

常用：

bytes.decode(encoding="utf-8",errors="strict")

encode(encoding="UTF-8",errors='strict')

isalnum()

isalpha()

isdigit()

isnumeric()

join(seq)

len(string)返回字符串长度

lstrip()

rstrip()

split()

### 3.2 列表

列表：

+ 列表可以完成大多数集合类的数据结构实现。列表中元素的类型可以不相同，它支持数字，字符串甚至可以包含列表（所谓嵌套）
+ 列表是写在方括号[]之间、用逗号分隔开的元素列表
+ 列表索引值以0为开始值，-1为从末尾的开始位置
+ 列表可以使用+操作符来进行拼接，使用*表示重复

```python
namelist=["小张","小王","小李"]
print(namelist[0])

testlist=["测试",1]
print(testlist[0])
print(testlist[1])
print(type(testlist[0]))
print(type(testlist[1]))
#列表中可以存储混合类型，可以保留原有的类型

namelist=["小张","小王","小李"]
for name in namelist:
    print(name)
```

#### 3.2.2 常用方法

| 操作名称                 | 操作方法                                                     | 举例                        |
| ------------------------ | ------------------------------------------------------------ | --------------------------- |
| 访问列表中的元素         | 通过下标直接访问                                             | print(list[0])              |
| 列表的切片               | 使用[: :]                                                    | list[2:5:2]                 |
| 遍历列表                 | 通过for循环                                                  | for i in list:print(i)      |
| 【增】新增数据到列表尾部 | 使用append                                                   | list.append(5)              |
| 【增】列表的追加         | 使用extend方法                                               | list.extend(list2)          |
| 【增】列表数据插入       | 使用insert方法                                               | list.insert(1,3)            |
| 【删】列表的删除         | del：我们通过索引删除指定位置的元素。  remove：移除列表中指定值的第一个匹配值，如果没找到，会抛异常 | del list[0]  list.remove(1) |
| 【删】弹出列表尾部元素   | 使用pop                                                      | list.pop()                  |
| 【改】更新列表中的数据   | 通过下标原地修改                                             | list[10]=8                  |
| 【查】列表成员关系       | in  、not in                                                 | 2 in list                   |
| 列表的加法操作           | +                                                            | list3=list1+list2           |
| 【排】列表的排序         | sort方法                                                     | list.sort()                 |
| 【排】列表的反转         | reverse                                                      | list.reverse()              |

```python
#增
print("-------增加前名单列表的数据----------")
for name in namelist:
    print(name)

nametemp=input("请输入添加学生的姓名：")
namelist.append(nametemp)

print("-------增加后名单列表的数据----------")
for name in namelist:
    print(name)

    
    
a=[1,2]
b=[3,4]
a.append(b)
#会把b当成一个整体追加到a后面
print(a)
#输出：[1, 2, [3, 4]]

a.extend(b)
#把b里面的每个元素逐一添加到列表当中
print(a)

a=[0,1,2]
a.insert(1,3)
#第一个变量表示下标，第二个表示元素（对象）
print(a)
#指定下标位置插入元素
```

```python
#删
moviename=["加勒比","加勒比","你的名字","天气之子","声之形","声之形"]
print("---------删除前电影列表的数据----------")
for name in moviename:
    print(name)


#在指定下标和指定位置删除
del moviename[2]

#弹出末尾最后一个元素
moviename.pop()

#删除指定内容，若数据重复删除找到的第一个
moviename.remove("加勒比")

print("---------删除后电影列表的数据----------")
for name in moviename:
    print(name)
    
    
#查
namelist=["小张","小王","小李"]
findname=input("请输入你要查找的学生：")
if findname in namelist:
    print("在学员名单中找到了当前学员")
else:
    print("在名单中没有找到当前学员")

a=["a","b","c","d","e"]
print(a.index("a",0,4))
#第一个是你要查找的对象，第二个是首地址，第三个是末尾地址
#可以查找指定下标范围的元素，并返回对应数据的下标
#区间都是左闭右开
#找不到会报错
print(a.count("c"))
#统计某个元素出现次数
```

```python
a=[1,4,2,3]
print(a)
a.reverse()
print(a)
#将列表所有元素反转，直接修改本身
a.sort()#升序
a.sort(reverse=True)#降序
print(a)
```

```python
#schoolName=[[],[],[]]
#有三个元素的空列表，每个元素都是空列表
schoolName=[["北京大学","清华大学"],["南开大学","天津大学"],["南京大学","东南大学","南理工"]]
#嵌套中的元素数量可以不一样
print(schoolName[0][0])
```

例子：

```python
import random
office=[[],[],[]]
names=["A","B","C","D","E","F","G","H"]
for name in names:
    index=random.randint(0,2)
    office[index].append(name)
i=1
for off in office:
    print("办公室%d的人数为：%d"%(i,len(off)))
    i+=1
    for name in off:
        print("%s"%name,end='\t')
    print('\n')
    print('-'*30)
```

### 3.3 元组

**tuple元组**

+ tuple与list类似，不同之处在于tuple的元素不能修改。tuple写在小括号里，元素之间用逗号隔开
+ 元组的元素不可变，但可以包含可变对象，如list
+ ==**定义只有一个元素的tuple，必须加逗号**==

```python
tup1=()#创建一个空元组
print(type(tup1))
tup2=(50,)#只有一个要加逗号，如果不加就是括号里面元素的类型
print(type(tup2))
tup3=(50,60,70)
print(type(tup3))
```

```python
tup1=("abc","def",2022)
print(tup1[0])
print(tup1[-1])#访问最后一个元素
print(tup1[0:2])#左闭右开进行切片
```

```python
#增
tup1=(12,34,56)
#tup1[0]=100不允许修改
tup2=("abc","def")
tup=tup1+tup2
print(tup)#直接连接了

del tup1#直接删除变量，之后再调用会报错，不允许删除某一特定值
```

| 操作名称         | 操作方法 | 举例           |
| ---------------- | -------- | -------------- |
| 元组成员关系     | in       | 2 in list1     |
| 得到重复元素数量 | count    | tuple1.count() |

| 操作名称               | 操作方法 | 举例 |
| ---------------------- | -------- | ---- |
| 获取元组长度           | len()    |      |
| 获取元组元素最大值     | max()    |      |
| 获取元组元素最小值     | min()    |      |
| 其它类型对象转换成元组 | tuple()  |      |

### 3.4 字典

**python的核心数据类型**

+ 字典是无序的对象集合，使用键-值（key-value）存储，具有极快的查找速度
+ 键（key）必须使用不可变类型
+ 同一个字典中，键必须唯一‘

```python
d={'bob':75,'tom':80,'bella':100}
print(d['bella'])
#访问了不存在的键
#print(d['gender'])直接访问会报错
#print(d.get('gender'))#使用get如果没找到不会报错，默认会显示None
print(d.get("gender","没找到"))#没找到可以设定默认值
print(d.get('bella',"没找到"))#引号不同会导致错误
```

```python
from turtle import clear


info={"name":"bella","age":18}
#增
newId=input("请输入新的id：")
info["id"]=newId
print(info)
#删
del info["id"]#删的是整个键值对
print(info)

info.clear()#清空
print(info)


print(info.keys())#得到所有的键(列表形式)
print(info.values())#得到所有的值
print(info.items())#得到所有的项，每个键值对是一个元组

#遍历所有的值
for key in info.keys():
    print(key)

for key,value in info.items():
    print(key)
    print(value)
    
mylist=["a","b","c","d"]
#enumerate变成枚举类型
for i,x in enumerate(mylist):
    print(i,x)
```

常用操作：

| 操作名称               | 操作方法 |
| ---------------------- | -------- |
| 获取字典长度           | len()    |
| 获取最大的key          | max()    |
| 获取最小的key          | min()    |
| 其他类型对象转换成字典 | dict()   |

### 3.5 集合

**set集合**

+ set和dict类似，也是一组key的集合，但不存储value。由于key不能重复，所以在set中没有重复的key
+ set是无序的，重复元素在set中被自动过滤

```py
s=set([1,2,3,1,6,2])
print(s)
```

**常用操作**

| 操作名称         | 操作方法    | 举例                   |
| ---------------- | ----------- | ---------------------- |
| 遍历集合         | 通过for循环 | for i in set1:print(i) |
| 更新集合         | update方法  | set1.update(set2)      |
| 向集合添加新元素 | add方法     | set1.add(5)            |
| 移除集合中的元素 | remove方法  | set1.remove(5)         |
| 弹出元素         | pop方法     | val=set1.pop()         |
| 清除元素         | clear方法   | set1.clear()           |
| 删除集合         | del         | del set1               |

获取集合长度  len()

获取最大的元素 max()

获取最小的元素 min()

其他类型对象转换成集合 set()



### 3.6 小结

|        | 是否有序 | 是否可变类型         |
| ------ | -------- | -------------------- |
| 列表[] | 有序     | 可变类型             |
| 元组() | 有序     | 不可变类型           |
| 字典{} | 无序     | key不可变，value可变 |
| 集合{} | 无序     | 可变类型（不重复）   |



## 4 函数

### 4.1 函数的定义和调用

定义函数的格式如下：

```python
def 函数名():
    代码
```

```python
def printinfo():
    print("-"*30)
    print("Bella")


printinfo()


#带参数的函数
def add2Num(a,b):
    c=a+b
    print(c)

add2Num(3,4)

#带返回值的函数
def add2Num_2(a,b):
    return a+b

print(add2Num_2(4,5)) 


#返回多个值的函数
def divid(a,b):
    shang=a//b
    yushu=a%b
    return shang,yushu#多个返回值用逗号分隔

sh,yu=divid(5,2)#需要使用多个值来保存返回内容
print(sh)
print(yu)
```

```python
def printoneline():
    print('-'*30)

#根据用户输入打印相应的条数
def printNumberLine(num):
    i=0
    while i<num:
        printoneline();
        i+=1

printNumberLine(3)
```

**局部变量和全局变量**

略

**当全局变量和局部变量名字相同时，优先使用局部变量，如果没有全局变量默认使用全局变量**

**如果想在函数中修改全局变量，可以直接加global前缀，表示全局变量**



## 5 文件操作

### 5.1 文件打开与关闭

#### 5.1.1 打开文件

在python中，使用open函数，可以打开一个已经存在的文件或者创建一个新的文件

open(文件名，访问模式)



示例：

```python
f=open('sparse_matrix.txt','r')#如果不写格式默认为读模式
```

访问模式

等等，略

```python
f=open("test.txt",'r')#打开文件 w模式，写模式，文件不存在就新建
#f.write("hello,world")#将字符串写入文件中
content=f.read(5)
print(content)
content=f.read(5)#会接着往后读5个字符，刚打开的时候定位在开头
print(content)

f.close()#关闭文件
#read方法，读取指定的字符数，开始时定位在文件头部，每执行一次向后移动指定字符

f=open("test.txt",'r')
content=f.readlines()#读完整个文档，帮你存储成一个列表
print(content)

f=open("test.txt",'r')
content=f.readline()
print(content)
f.close()
```



### 5.2 文件的相关操作

有时候，需要对文件进行重命名、删除等一些操作，python中的os模块中都有这些功能

#### 5.2 1 文件重命名

os模块中rename()可以完成对文件的重命名操作

rename(需要修改的文件名，新的文件名)

```python
import os
os.rename("test.txt","python_test.txt")
```

#### 5.2.2 删除文件

os模块中remove()可以完成对文件的删除操作

remove(待删除的文件名)

#### 5.2.3 创建文件夹

```python
import os
os.mkdir("")
```

#### 5.2.4 获取当前目录

```python
import os
os.getcwd()
```

#### 5.2.5 改变默认目录

```python
import os
os.chdir("../")
```

#### 5.2.6 获取目录列表

```python
import os
os.listdir("./")
```

#### 5.2.7 删除文件夹

import os

os.rmdir("")



## 6 错误与异常

```python
#异常捕获
#发生异常
try:
    print("--------test-------1--------")
    f=open("123.txt",'r')
    print("test2")#这句代码不会被执行
except IOError:#文件没找到属于输入输出异常
    pass#捕获异常后执行的代码



try:
    print(num)
#except IOError:#不是io异常的问题，捕获的异常要和产生的异常相匹配
except NameError:
    print("产生错误了")
#异常类型想要被捕获，需要一致


try:
    print("test1")
    f=open("123.txt",'r')
    print("test2")
    print(num)
except (IOError,NameError):
    print("产生错误了")
#捕获多个异常
#将可能产生的多个异常类型，都放到下面的小括号中
```

```python
#获取错误描述
try:
    print("test1")
    f=open("123.txt",'r')
    print("test2")
    print(num)
except (IOError,NameError) as result:
    print("产生错误了")
    print(result)
#捕获多个异常



try:
    print("test1")
    f=open("123.txt",'r')
    print("test2")
    print(num)
except Exception as result:#Exception可以承接任何异常，这是所有异常的父类
    print("产生错误了")
    print(result)
```



try和finally的嵌套

```python
import time
try:
    f=open("123.txt",'r')
    try:
        while True:
            content=f.readline()
            if len(content)==0:
                break
            time.sleep(2)
            print(content)
    finally:
        f.close()
        print("文件关闭")

except Exception as result:
    print("发生异常")
```





















