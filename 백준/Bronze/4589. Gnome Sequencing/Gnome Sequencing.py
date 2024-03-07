print("Gnomes:")
for i in range(int(input())):
    a, b, c = [int(j) for j in input().split(" ")]
    if (a <= b and b <= c) or (a >= b and b >= c):
        print("Ordered")
    else:
        print("Unordered")