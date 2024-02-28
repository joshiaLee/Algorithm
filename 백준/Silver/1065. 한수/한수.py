n = int(input())
if n < 100:
    print(n)
else:
    cnt = 99
    for i in range(100, n+1):
        l = list(str(i))
        if int(l[1]) - int(l[0]) == int(l[2]) - int(l[1]):
            cnt += 1
    print(cnt)