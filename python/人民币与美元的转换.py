Money=input("请输入带符号的钱数:")
if Money[-1] in ['￥']:
    R=eval(Money[0:-1])/6
    print("可兑换美元为{:.2f}".format(R))
elif Money[-1] in ['＄']:
    M=6*eval(Money[0:-1])
    print("可兑换人民币为{:.2f}".format(M))
else:
    print("格式错误")
