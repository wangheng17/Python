def fun(m,n,a):
    for i in range(1,m+1):
        if i==1 or i==m:
            print(a*n)
        else:
            print(a+' '*(n-2)+a)
m=eval(input("请输入打印行数: "))
n=eval(input("请输入打印列数: "))
a=input("请输入打印的符号: ")
fun(m,n,a)