s = input()

dic = {"000": "0", "001": "1", "010": "2",
       "011": "3", "100": "4", "101": "5",
       "110": "6", "111": "7"}

if len(s) % 3 == 1:
    s = "00" + s
elif len(s) % 3 == 2:
    s = "0" + s

ans = []
part = ""
cnt = 0

for i in range(0, len(s)):

    part += s[i]
    cnt += 1
    
    if cnt == 3:
        ans.append(dic[part])
        part = ""
        cnt = 0

print("".join(ans))