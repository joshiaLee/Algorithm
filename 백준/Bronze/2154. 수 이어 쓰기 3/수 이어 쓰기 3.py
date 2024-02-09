n = int(input())

s = []

for i in range(1, n+1):
    s.append(str(i))

s = "".join(s)

print(s.find(str(n)) + 1)


