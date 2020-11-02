str=input("请输入一行字符串:\n")
letter=0
space=0
number=0
others=0
for c in str:
    if c.isalpha():
        letter+=1
    elif c.isspace():
        space+=1
    elif c.isdigit():
        number+=1
    else:
        others+=1
print("letter={},space={},number={},other={}".format(letter,space,number,others))
