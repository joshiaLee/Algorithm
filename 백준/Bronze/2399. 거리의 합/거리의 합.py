n = int(input())
l = [int(i) for i in input().split(" ")]
print(sum(abs(l[i] - l[j]) for i in range(n) for j in range(i+1, n)) * 2)