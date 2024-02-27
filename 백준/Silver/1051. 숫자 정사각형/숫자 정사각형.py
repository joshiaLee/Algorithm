n, m = [int(i) for i in input().split(" ")]
l = []
for i in range(n):
    l.append(list(input()))

min_val = 1
max_val = min(n,m)

for side in range(2, max_val+1):
    for i in range(n-(side-1)):
        for j in range(m-(side-1)):
            if l[i][j] == l[i+(side-1)][j] == l[i][j+(side-1)] == l[i+(side-1)][j+(side-1)]:
                min_val = side

print(min_val*min_val)    