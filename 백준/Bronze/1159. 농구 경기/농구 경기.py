n = int(input())

player_dic = {}

ans = ""

for i in range(n):
    s = input()
    
    if s[0] in player_dic:
        player_dic[s[0]] += 1
    else:
        player_dic[s[0]] = 1

for key, val in player_dic.items():
    if val >= 5:
        ans += key

if not ans:
    print("PREDAJA")
    
else:     
    ans = sorted(ans)
    print("".join(ans))
    