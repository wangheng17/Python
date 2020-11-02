import random
a=['apple','pear','peach','orange']
ls=random.choice(a)
ls=list(ls)
random.shuffle(ls)
ls=''.join(ls)
print("请猜乱序单词{}为".format(ls))
