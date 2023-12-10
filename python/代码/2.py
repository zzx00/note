
'''
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
'''
#返回多个值的函数
# def divid(a,b):
#     shang=a//b
#     yushu=a%b
#     return shang,yushu#多个返回值用逗号分隔

# sh,yu=divid(5,2)#需要使用多个值来保存返回内容
# print(sh)
# print(yu)

# def printoneline():
#     print('-'*30)

# #根据用户输入打印相应的条数
# def printNumberLine(num):
#     i=0
#     while i<num:
#         printoneline();
#         i+=1

# printNumberLine(3)


#全局变量和局部变量
# def test1():
#     a=300
#     print("test1修改前a：%d"%a)

# test1()

# f=open("test.txt",'r')#打开文件 w模式，写模式，文件不存在就新建
# #f.write("hello,world")#将字符串写入文件中
# content=f.read(5)
# print(content)
# content=f.read(5)#会接着往后读5个字符，刚打开的时候定位在开头
# print(content)

# f.close()#关闭文件
# f=open("test.txt",'r')
# content=f.readlines()#读完整个文档，帮你存储成一个列表
# print(content)


# f=open("test.txt",'r')
# content=f.readline()
# print(content)
# f.close()


# import os
# os.rename("test.txt","python_test.txt")



#异常捕获
#发生异常
# try:
#     print("--------test-------1--------")
#     f=open("123.txt",'r')
#     print("test2")#这句代码不会被执行
# except IOError:
#     pass


# try:
#     print(num)
# #except IOError:#不是io异常的问题，捕获的异常要和产生的异常相匹配
# except NameError:
#     print("产生错误了")
# #异常类型想要被捕获，需要一致


# #获取错误描述
# try:
#     print("test1")
#     f=open("123.txt",'r')
#     print("test2")
#     print(num)
# except (IOError,NameError) as result:
#     print("产生错误了")
#     print(result)
# #捕获多个异常



# try:
#     print("test1")
#     f=open("123.txt",'r')
#     print("test2")
#     print(num)
# except Exception as result:#Exception可以承接任何异常，这是所有异常的父类
#     print("产生错误了")
#     print(result)


#try和finally的嵌套


# import time
# try:
#     f=open("123.txt",'r')
#     try:
#         while True:
#             content=f.readline()
#             if len(content)==0:
#                 break
#             time.sleep(2)
#             print(content)
#     finally:
#         f.close()
#         print("文件关闭")

# except Exception as result:
#     print("发生异常")

if __name__ == "__main__":





