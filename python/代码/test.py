a=int(input())
b=int(input())
c=int(input())
if (a+b)>c and (b+c)>a and (a+c)>b and abs(a-b)<c and abs(a-c)<b and abs(b-c)<a:
    print('YES')
else: 
    print('NO')