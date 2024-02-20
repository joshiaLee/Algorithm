n = input()
k = int(input())
add = ""
for i in range(100): 
    if i < 10:
        add = '0' + str(i)
    else:
        add = str(i)
        
    if int(n[:-2] + add) % k == 0:
        break

print(add)