for i in range(0,9999):
    for j in range(2,i):
        if i%j==0:
            break;
    else:
        print("{}是素数".format(i))
