n = int(input())
s_list = []

for i in range(n):
    s = input()
    s_list.append(s)

ans = ""

for i in range(len(s_list[0])):
    c = s_list[0][i]
    flag = 1
    
    for s in s_list:
        if c is not s[i]:
            ans += '?'
            flag = 0
            break
    
    if flag:
        ans += c
      

print(ans)