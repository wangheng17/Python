import math
a=eval(input("请输入一边的值:"))
b=eval(input("请输入另一边的值:"))
degree=eval(input("请输入两边夹角:"))
x=math.radians (degree)
c=math.sqrt(a**2+b**2-2*a*b*math.cos(x))
print("第三边长度为:{:.2f}".format(c))
