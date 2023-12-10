#### cudaMalloc

为什么cuda_Malloc第一个参数是两个星星

![img](https://img-blog.csdnimg.cn/20190205141059886.png)

&dev_c   就是dev_c的地址

*(&dev_c) 就是解引用，就是dev_c，(void *)&dev_c将其整体转化为一个指针，指向var

**(&dev_c)指向变量var

(void **)&dev_c就是指向指针的指针，指针类型的void\*\*类型，这样，才可以在子函数中获得目标地址，不然就是修改的形参的指向，没有意义

[双重指针](https://blog.csdn.net/gdjason/article/details/51123978)

通过函数参数形式修改指针地址，一般用二级指针。



####cudaMemcpy

这个函数实现数据在CPU和GPU之间的移动



#### 用vscode写cu要用英文，不能写中文



#### 用vscode不能改字符编码，不然会没有输出！！！



####cuda中<<<或者>>>之间不能有空格！！！



#### c++分文件操作

一个c++文件大概有三部分组成：

1. 类声明的头文件(.h)
2. 类实现文件(.cpp)
3. 类的使用文件(.cpp)

