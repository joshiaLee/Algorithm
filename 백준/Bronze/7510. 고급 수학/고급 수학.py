n = int(input())
for i in range(1,n+1):
    l = [int(j) for j in input().split(" ")]
    m = max(l)
    sum = 0
    for a in l:
        if a != m:
            sum += a * a
    print("Scenario #" + str(i) + ":")
    if m*m == sum:
        print("yes\n")
    else:
        print("no\n")