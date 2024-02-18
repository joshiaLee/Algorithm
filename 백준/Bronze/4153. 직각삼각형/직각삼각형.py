while True:
    l = [int(i) for i in input().split(" ")]
    if all(value == 0 for value in l):
        break
    m = max(l)
    if m*m == sum(length * length for length in l if length != m):
        print("right")
    else:
        print("wrong")