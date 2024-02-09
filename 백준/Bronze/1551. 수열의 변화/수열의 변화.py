n,k = map(int,input().split(" "))

s = input()
l = list(map(int, s.split(",")))

for i in range(k):
    new_l = []
    
    for j in range(0,len(l) - 1):
        new_l.append(l[j+1] - l[j])
    
    l = new_l
    
l = [str(item) for item in l]
print(",".join(l))
