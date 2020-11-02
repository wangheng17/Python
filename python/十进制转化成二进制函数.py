def change(x):
    ls=[]
    while x>0:
        m=x%2
        x=x//2
        ls.append(m)
    ls.reverse()
    print("转化为二进制{}".format("".join(map(str,ls))))

x=eval(input("请输入一个十进制数: "))
change(x)

