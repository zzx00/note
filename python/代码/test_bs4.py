'''
BeautifulSoup4将复杂的html文档转换成一个复杂的树形结构，每个节点都是python对象，所有的对象可归纳为4种
Tag
NavigableString
BeautifulSoup
Comment
'''
import re
from bs4 import BeautifulSoup

file=open("./baidu.html","rb")
html=file.read().decode("utf-8")
bs=BeautifulSoup(html,"html.parser")



#1、tag标签及其内容，拿到它找到的第一个内容

#2、NavigableString，标签里的内容（字符串）

#3、BeautifulSoup表示整个文档

#4、Comment 是一个特殊的NavigableString，输出的内容不包含注释符号



#文档的遍历


#文档的搜索
#字符串过滤，查找与字符串完全匹配的内容
t_list=bs.find_all("a")

#正则表达式搜索：使用search方法匹配内容
t_list=bs.find_all(re.compile("a"))

#方法搜索：传入一个函数，根据函数的方法来搜索

#kwargs 参数
t_list=bs.find_all(id="head")

#text参数
t_list=bs.find_all(re.compile("\d"))#使用正则表达式来查找包含特定文本的内容（标签里的字符串）

#limit参数
t_list=bs.find_all("a",limit=3)#得到三个，限定三个

#css选择器
t_list=bs.select('title')#通过标签查找
t_list=bs.select(".mnav")#前面加.表示用类名进行查找
t_list=bs.select("#u1")#通过id来查找
t_list=bs.select("a[class='bri']")#通过属性来查找
t_list=bs.select("head>title")#通过子标签来查找
t_list=bs.select(".mnav ~ .bri")#通过兄弟标签来查找

print(t_list)








