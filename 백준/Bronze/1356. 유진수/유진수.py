s = input()

for i in range(1, len(s)):
    s1 = s[0:i]
    s2 = s[i:len(s)]
    
    mul1 = 1
    mul2 = 1
    
    for c in s1:
        mul1 *= int(c)
    for c in s2:
        mul2 *= int(c)
    
    if mul1 == mul2:
        print("YES")
        exit()

print("NO")