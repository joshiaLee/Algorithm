a, b, c = [int(i) for i in input().split(" ")]
if a+b == c:
    print("{}+{}={}".format(a, b, c))
elif a-b == c:
    print("{}-{}={}".format(a, b, c))
elif a*b == c:
    print("{}*{}={}".format(a, b, c))
elif a/b == c:
    print("{}/{}={}".format(a, b, c))
elif a == b+c:
    print("{}={}+{}".format(a, b, c))
elif a == b-c:
    print("{}={}-{}".format(a, b, c))
elif a == b*c:
    print("{}={}*{}".format(a, b, c))
elif a == b/c:
    print("{}={}/{}".format(a, b, c))
    
        


