dic = {}
A, B, C = sorted([ int(i) for i in input().split(" ")])
dic['A'] = A
dic['B'] = B
dic['C'] = C
for c in input():
    print(dic[c], end=" ")