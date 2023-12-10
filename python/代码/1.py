
'''
#从0下标开始到4
for i in range(5):
    print(i)

#从0开始到12结束，每次加3，是不包含12的
for i in range(0,12,3):
    print(i)

for i in range(-10,-100,-20):
    print(i)



name="chengdu"
for i in name:
    print(i)


a=["aa","bb","cc"]
for i in range(len(a)):
    print(i,a[i])
for i in a:
    print(i)


i=0
while i<5:
    print("当前是第%d次执行循环"%(i+1))
    print("i=%d"%i)
    i+=1

i=1
sum=0
while i<=100:
    sum+=i
    i+=1
print(sum)


count=0
while count<5:
    print(count,"小于5")
    count+=1
else:
    print(count,"大于或等于5")



i=0
while i<10:
    i+=1
    print("-"*30)
    if i==5:
        break
    print(i)

i=0
while i<10:
    i+=1
    print("-"*30)
    if i==5:
        continue
    print(i)



word='字符串'
sentence="这是一个句子"
paragraph="""
这是一个段落
可以换行编写
多行编写
"""
print(word)
print(sentence)
print(paragraph)



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


testlist=["测试",1]
print(testlist[0])
print(testlist[1])
print(type(testlist[0]))
print(type(testlist[1]))
#列表中可以存储混合类型，可以保留原有的类型


# namelist=["小张","小王","小李"]

# # for name in namelist:
# #     print(name)

# #增
# print("-------增加前名单列表的数据----------")
# for name in namelist:
#     print(name)

# nametemp=input("请输入添加学生的姓名：")
# namelist.append(nametemp)

# print("-------增加后名单列表的数据----------")
# for name in namelist:
#     print(name)

# a=[1,2]
# b=[3,4]
# a.append(b)
# #会把b当成一个整体追加到a后面
# print(a)

# a.extend(b)
# #把b里面的每个元素逐一添加到列表当中
# print(a)

# a=[0,1,2]
# a.insert(1,3)
# #第一个变量表示下标，第二个表示元素（对象）
# print(a)
# #指定下标位置插入元素

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

print(a.count("c"))

a=[1,4,2,3]
print(a)
a.reverse()
print(a)
#将列表所有元素反转，直接修改本身
a.sort()#升序
a.sort(reverse=True)#降序
print(a)

#schoolName=[[],[],[]]
#有三个元素的空列表，每个元素都是空列表
schoolName=[["北京大学","清华大学"],["南开大学","天津大学"],["南京大学","东南大学","南理工"]]
#嵌套中的元素数量可以不一样
print(schoolName[0][0])


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

tup1=()#创建一个空元组
print(type(tup1))
tup2=(50,)#只有一个要加逗号，如果不加就是括号里面元素的类型
print(type(tup2))
tup3=(50,60,70)
print(type(tup3))

tup1=("abc","def",2022)
print(tup1[0])
print(tup1[-1])#访问最后一个元素
print(tup1[0:2])#左闭右开进行切片

#增
tup1=(12,34,56)
#tup1[0]=100不允许修改
tup2=("abc","def")
tup=tup1+tup2
print(tup)#直接连接了

del tup1#直接删除变量，之后再调用会报错，不允许删除某一特定值



d={'bob':75,'tom':80,'bella':100}
print(d['bella'])
#访问了不存在的键
#print(d['gender'])直接访问会报错
#print(d.get('gender'))#使用get如果没找到不会报错，默认会显示None
print(d.get("gender","没找到"))#没找到可以设定默认值
print(d.get('bella',"没找到"))#引号不同会导致错误
'''
from turtle import clear


info={"name":"bella","age":18}
#增
# #newId=input("请输入新的id：")
# info["id"]=newId
# print(info)
# #删
# del info["id"]#删的是整个键值对
# print(info)

# info.clear()#清空
# print(info)

#修改直接通过键访问即可

# print(info.keys())#得到所有的键(列表形式)
# print(info.values())#得到所有的值
# print(info.items())#得到所有的项，每个键值对是一个元组

# #遍历所有的值
# for key in info.keys():
#     print(key)

# for key,value in info.items():
#     print(key)
#     print(value)

# mylist=["a","b","c","d"]
# #enumerate变成枚举类型
# for i,x in enumerate(mylist):
#     print(i,x)

# s=set([1,2,3,1,6,2])
# print(s)




