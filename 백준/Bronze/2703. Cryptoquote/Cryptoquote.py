t = int(input())

for i in range(t):
    crypt = input()
    dic = {" ": " "}
    
    quote = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    ans = input()
    
    for i in range(26):
        dic[quote[i]] = ans[i]
    
    l = []
    
    for c in crypt:
        l.append(dic[c])
    
    print("".join(l))
        
