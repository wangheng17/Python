TempSter=eval(input("请输入所选择的转换的方式1或2："))
if TempSter==1:
    C=eval(input("请输入华氏温度："))
    C=(C-32)/1.8
    C=int(C)
    print("转换后的温度后{:.2f}".format(C))
elif TempSter==2:
    F=eval(input("请输入摄氏温度："))
    F=1.8*F+32
    F=int(F)
    print("转换后的温度是{:.2f}".format(F))
