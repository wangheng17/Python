a="-"
b="+"
c="|"
d=" "
for i in range(13):
    if i in [0,6,12]:
        print("{0}{1}{0}{1}{0}".format(b,a*4,b,a*4,b))
    else:
        print("{0}{1}{0}{1}{0}".format(c,d*4,c,d*4,c))
