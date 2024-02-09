s1 = input()
n = int(input())

dic1 = {}



m = 0
for i in range(n):
    dic = {"L": 0, "O": 0, "V": 0, "E": 0}
    s2 = input()
    
    for c in s1:
        if c in dic:
            dic[c] += 1

    for c in s2:
        if c in dic:
            dic[c] += 1
    
    p = ((dic["L"]+dic["O"]) * (dic["L"]+dic["V"]) * (dic["L"]+dic["E"]) 
     * (dic["O"]+dic["V"]) * (dic["O"]+dic["E"]) * (dic["V"]+dic["E"])) % 100
    dic1[s2] = p
        
    if m <= p:
        m = p
ans = []
for key, val in dic1.items():
    if val == m:
        ans.append(key)

ans = sorted(ans)

print(ans[0])