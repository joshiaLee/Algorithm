n = int(input())
l = ['A','E','I','O','U','a','e','i','o','u']
for i in range(n):
    s = input().split(' ')
    new_s = ''.join(s)
    cnt = 0
    for c in new_s:
        if c in l:
           cnt = cnt + 1
    print(len(new_s) - cnt, cnt)
