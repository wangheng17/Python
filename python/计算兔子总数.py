month=eval(input("请输入月份："))
if month==1 or month==2:
    print("共有一只兔子")
else:
    a=1
    b=1
    c=0
    for i in range(3,month+1):
        c=a+b
        a=b
        b=c
    print(c)
