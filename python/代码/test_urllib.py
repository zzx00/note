from email import header
from urllib import response
import urllib.request

#获取一个get请求
# response=urllib.request.urlopen("http://www.baidu.com")
# print(response.read().decode('utf-8'))#使用utf-8进行解码，得到的就是整个网页的内容


# #获取一个post请求
# #模拟用户真实登录
# import urllib.parse
# data=bytes(urllib.parse.urlencode({"hello":"world"}),encoding="utf-8")
# response=urllib.request.urlopen("http://httpbin.org/post",data=data)
# #会把收到的表单信息显示到form中
# print(response.read().decode("utf-8"))

# #超时处理
# try:
#     response=urllib.request.urlopen("http://httpbin.org/get",timeout=0.01)
#     print(response.read().decode("utf-8"))
# except urllib.error.URLError as e:
#     print("timeout")

# response=urllib.request.urlopen("http://baidu.com")
# #print(response.status)#200是状态码
# print(response.getheaders())
# print(response.getheader("Server"))#获取其中具体某一个信息

# url="https://www.douban.com"
# #url="http://httpbin.org/post"
# headers={
#     "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36"
# }
# data=bytes(urllib.parse.urlencode({"name":"bella"}),encoding="utf-8")
# req=urllib.request.Request(url=url,headers=headers,method="POST")
# response=urllib.request.urlopen(req)
# print(response.read().decode("utf-8"))


url="https://www.douban.com"

headers={
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4896.127 Safari/537.36"
}

req=urllib.request.Request(url=url,headers=headers,method="POST")
response=urllib.request.urlopen(req)
print(response.read().decode("utf-8"))

