from urllib import response
from bs4 import BeautifulSoup      #网页解析获取数据
import urllib.request,urllib.error
from requests import request  #指定url，获取网页数据
import xlwt #进行excel操作
import re       #正则表达式进行文字匹配
import sqlite3  #进行sqlite数据库操作
#引入第三方模块

def main():
    baseurl="https://movie.douban.com/top250?start="
    #爬取网页
    datalist=getData(baseurl)
    savapath=".\\豆瓣电影top250.xls"
    #解析数据
    askUrl(baseurl)
    #saveData(savepath)
    #保存数据


#爬取网页
def getData(baseurl):
    datalist=[]
    for i in range(0,10):#调用获取页面信息的函数，循环10次
        url=baseurl+str(i*25)
        html=askUrl(url)#保存获取到的网页源码
        
    #逐一解析数据
    return datalist


#得到指定一个url的网页内容
#用户代理用来告诉服务器我们是什么类型的浏览器，用来伪装成浏览器，本质上是告诉浏览器我们可以接受什么水平的文件内容
def askUrl(url):
    headers={
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36"
    }
    request=urllib.request.Request(url,headers=headers)
    html=""
    try:
        response=urllib.request.urlopen(request)
        html=response.read().decode("utf-8")
        print(html)
    except urllib.error.URLError as e:
        if hasattr(e,"code"):
            print(e.code)
        if hasattr(e,"reason"):
            print(e.reason)
    return html




#def saveData(savepath):








if __name__ == "__main__":#当程序执行时
    #调用函数
    main()
