import os

#os.walk("./")#当前所在路径
for temp in os.walk("./"):
    print("-"*30)
    print(temp)#第一个元素表示当前路径，，第二个元素表示当前路径下有哪些文件夹，第三个元素表示当前文件夹下有哪些文件

    