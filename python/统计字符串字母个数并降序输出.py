str="wecjdifhvgsjfudhscgj"
list1=list(set(str))
dict1=dict()
for i in list1:
    num=str.count(i)
    dict1.setdefault(i,num)
items=list(dict1.items())
items.sort(key=lambda x:x[1],reverse=True)
for i in items:
    print("{}:{}".format(i[0],i[1]))

