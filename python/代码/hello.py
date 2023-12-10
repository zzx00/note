# import keyword
# print("hello world")
# #注释，使用井号单行注释

# '''
# 多行注释
# 第二行
# '''

# print("python")

# a=10
# print("这是变量:",a)


# #python关键字
# print(keyword.kwlist)

# #格式化输出
# age=10
# print("我今年%d岁了"%age)
# print("我的名字是：%s,我的国籍是：%s"%("小张","中国"))

# #可以一直打印，中间用空格分隔
# print("aaa","bbb","ccc")
# #中间用.来分隔
# print("www","baidu","com",sep=".")


# print("hello",end="")#不换行
# print("world",end="\t")#中间空一段
# print("python",end="\n")#结束换行
# print("end")

'''
password=input("请输入密码：")
print("您的密码是：",password)
print(type(password))

a=10
print(type(a))
'''
'''
a=int("123")
b=a+100
print(b)
print(type(a))

c=int(input("请输入："))
print("输入了一个数字：%d"%c)


d=int(input("请输入数字"))
if (d>0)&(d<1):
    print("1")
elif (d>1)&(d<5):
    print("2")
else:
    print("3")

if True:
    print("True")
else:
    print("False")

'''
'''
score=100
if score>=90 and score<=100:
    print("优秀")
elif score<90 and score>=80:
    print("良好")
else:
    if score>=70 and score<80:
        print("中等")
    elif score>=60 and score<70:
        print("及格")
    else:
        print("不及格")
'''

#引入库
import random
x=random.randint(0,100)#0到100之间的整数，随机数
print(x)

for i in range(5):
    print(i)

for i in range(0,10,3):
    print(i)
#从0开始到10，每次步进3
