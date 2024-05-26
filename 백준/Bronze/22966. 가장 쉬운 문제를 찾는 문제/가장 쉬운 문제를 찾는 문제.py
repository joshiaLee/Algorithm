n = int(input())
m = 5
ans = ""
for i in range(n):
    s, length = input().split(' ')
    if int(length) < m:
        m = int(length)
        ans = s
print(ans)