t = int(input())
for _ in range(t):
    l = [0 for _ in range(0, 101)]
    s = input()
    for c in s:
        l[ord(c)] = 1
    sum = 0
    for i in range(65, 91):
        if l[i] == 0:
            sum += i
    print(sum)

