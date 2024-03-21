m = int(input())
n = int(input())
if n < 10:
    d = str(m) + str(n*10)
else:
    d = str(m) + str(n)
if int(d) < 218:
    print("Before")
elif int(d) == 218:
    print("Special")
else:
    print("After")