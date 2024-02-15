n = int(input())
if n == 0:
    print(1)
    exit()
mul = 1
for i in range(2,n+1):
    mul = mul * i
print(mul)
